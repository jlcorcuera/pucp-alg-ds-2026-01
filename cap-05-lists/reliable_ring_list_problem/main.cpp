#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/NodoLista.h"
#include "BibliotecaLista/ElementoLista.h"
#include "BibliotecaLista/funcionesLista.h"

using namespace std;

// Notar que solo se tiene un puntero para el inicio de la lista
typedef struct Lista ReliableRingList;

void agregar_nodo(ReliableRingList & ring, int id) {
    struct ElementoLista elem;
    elem.node_id   = id;
    elem.is_active = true;

    // 1. Ubicamos el ultimo nodo para abrir el ring
    if (ring.inicio != nullptr) {
        struct NodoLista * ultimo = ring.inicio;
        for (int i = 0; i < ring.longitud - 1; ++i)
            ultimo = ultimo->next;
        ultimo->next = nullptr;
    }

    // 2. Agregamos el nuevo nodo: Notar que se modifico insertarAlFinal
    // para que devuelva el nodo insertado
    struct NodoLista * nuevoUltimo = insertarAlFinal(ring, elem);

    // 3. Cerramos el anillo
    nuevoUltimo->next = ring.inicio;
}

void calcular_skip_next(ReliableRingList & ring) {
    if (ring.inicio == nullptr || ring.longitud < 2) return;

    struct NodoLista * cur = ring.inicio;

    // Iteramos y solo actualizamos el puntero skip_next
    for (int i = 0; i < ring.longitud; ++i) {
        cur->skip_next = cur->next->next;
        cur = cur->next;
    }
}

struct NodoLista * buscarNodo(const ReliableRingList & ring, int id) {
    if (ring.inicio == nullptr) return nullptr;

    struct NodoLista * cur = ring.inicio;
    for (int i = 0; i < ring.longitud; ++i) {
        // Dado un id, ubicamos el nodo y lo devolvemos
        if (cur->elemento.node_id == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void desactivar_nodo(ReliableRingList & ring, int id) {
    struct NodoLista * n = buscarNodo(ring, id);
    // El nodo con el id dado, se le desactiva
    if (n != nullptr) n->elemento.is_active = false;
}

void auto_healing(ReliableRingList & ring) {
    if (ring.inicio == nullptr || ring.longitud == 0) return;

    // Paso 1: separar activos e inactivos en un solo recorrido
    // - Los activos se reenlazan formando el nuevo anillo circular.
    // - Los inactivos se enlazarán via skip_next para borrarlos.
    int activos = 0;
    struct NodoLista * partida = nullptr;
    struct NodoLista * ultimoAct = nullptr;
    struct NodoLista * listaElim = nullptr;

    struct NodoLista * cur = ring.inicio;
    for (int i = 0; i < ring.longitud; ++i) {
        struct NodoLista * siguiente_orig = cur->next;

        if (cur->elemento.is_active) {
            activos++;
            if (partida == nullptr) {
                partida = ultimoAct = cur; // primer activo encontrado
            } else {
                ultimoAct->next = cur; // enlazar al último activo previo
                ultimoAct = cur;
            }
        } else {
            cur->skip_next = listaElim; // encadenar en la lista de borrado
            listaElim = cur;
        }
        cur = siguiente_orig;
    }

    if (partida == nullptr || activos == 0) {
        ring.inicio = nullptr;
        ring.longitud = 0;
        return;
    }

    ultimoAct->next = partida; // cerrar el anillo de activos
    ring.inicio = partida;
    ring.longitud = activos;

    // Paso 2: recalcular skip_next sobre el anillo ya limpio
    calcular_skip_next(ring);

    // Paso 3: liberar los nodos inactivos
    while (listaElim != nullptr) {
        struct NodoLista * aEliminar = listaElim;
        listaElim = listaElim->skip_next;
        delete aEliminar;
    }
}

void imprimir_anillo(const ReliableRingList & ring) {
    if (ring.inicio == nullptr) {
        cout << "[Anillo vacío]\n";
        return;
    }
    cout << "Anillo (" << ring.longitud << " nodos):\n";
    struct NodoLista * cur = ring.inicio;
    for (int i = 0; i < ring.longitud; ++i) {
        cout << "  Nodo " << cur->elemento.node_id
             << " [" << (cur->elemento.is_active ? "ACTIVO" : "CAIDO ") << "]"
             << "  siguiente=" << cur->next->elemento.node_id
             << "  skip_next=" << cur->skip_next->elemento.node_id
             << "\n";
        cur = cur->next;
    }
}

int main() {
    int N = 5;
    ReliableRingList ring;
    construir(ring);

    for (int id = 1; id <= N; ++id) {
        agregar_nodo(ring, id * 10);
    }

    // Se asigna el skip_next
    calcular_skip_next(ring);

    cout << "=== Estado inicial ===\n";
    imprimir_anillo(ring);

    // Prueba 1: nodo 3 no operativo, failover automático
    desactivar_nodo(ring, 20);
    cout << "\n>>> Nodo 20 cae <<<\n";

    // Prueba 2: nodo 4 también -> anillo roto
    desactivar_nodo(ring, 30);
    cout << "\n>>> Nodo 30 cae <<<\n";

    // Prueba 3: auto_healing
    cout << "\n=== Estado antes de auto_healing ===\n";
    imprimir_anillo(ring);

    auto_healing(ring);

    cout << "\n=== Estado después de auto_healing ===\n";
    imprimir_anillo(ring);

    return 0;
}