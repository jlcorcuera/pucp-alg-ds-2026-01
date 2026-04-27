//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

/*
 * IMPLEMENTACION DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
void sortv2(struct Lista & listaTAD) {
    NodoLista* recorrido = nullptr;
    NodoLista* anteriorRecorrido = nullptr;
    NodoLista* nueva = nullptr;
    NodoLista* nuevaFinal = nullptr;
    for (int i = 0; i < listaTAD.longitud; i++) {
        NodoLista* anteriorMin = nullptr;
        NodoLista* minPtr = nullptr;
        recorrido = listaTAD.inicio;
        while (recorrido != nullptr) {
            if (minPtr == nullptr || recorrido->elemento.codigo < minPtr->elemento.codigo) {
                minPtr = recorrido;
                anteriorMin = anteriorRecorrido;
            }
            anteriorRecorrido = recorrido;
            recorrido = recorrido->siguiente;
        }

        if (anteriorMin == nullptr) {
            listaTAD.inicio = listaTAD.inicio->siguiente;
        } else {
            anteriorMin->siguiente = minPtr->siguiente;
        }

        if (i == 0) {
            nueva = minPtr;
            nuevaFinal = nueva;
        } else {
            nuevaFinal->siguiente = minPtr;
            nuevaFinal = minPtr;
        }
    }
    listaTAD.inicio=nueva;
}

void sort(struct Lista listaTAD) {
    NodoLista* anteriorI = nullptr;
    NodoLista* anteriorJ = nullptr;
    for (NodoLista* nodoI = listaTAD.inicio; nodoI != nullptr; nodoI = nodoI->siguiente) {
        anteriorJ = nodoI;
        for (NodoLista* nodoJ = nodoI->siguiente; nodoJ != nullptr; nodoJ = nodoJ->siguiente) {
            if (nodoI->elemento.codigo > nodoJ-> elemento.codigo) {
                if (anteriorI == nullptr) {
                    NodoLista* tmp = nodoJ->siguiente;
                    listaTAD.inicio = nodoJ;
                    nodoJ->siguiente = nodoI;
                    nodoI->siguiente = tmp;
                } else {
                    NodoLista* tmp = nodoJ->siguiente;
                    anteriorI->siguiente = nodoJ;
                    if (nodoI->siguiente == nodoJ) {
                        nodoI->siguiente = tmp;
                        nodoJ->siguiente = nodoI;
                    } else {
                        nodoJ->siguiente = nodoI->siguiente;
                        anteriorJ->siguiente = nodoI;
                        nodoI->siguiente = tmp;
                    }
                }
            }
            anteriorJ = nodoJ;
        }
        anteriorI = nodoI;
    }
}

int main(int argc, char **argv) {

    struct ElementoLista elemento{};
    struct Lista listaInicio, listaFinal, listaEnOrden;

    construir(listaInicio);
    construir(listaFinal);
    construir(listaEnOrden);
    cout << "La lista esta vacia: " << esListaVacia(listaInicio) << endl;

    for (int i = 1; i < 10; i+=2) {
        elemento.codigo = i;
        insertarAlInicio(listaInicio, elemento);
    }
    imprimir(listaInicio);
    cout << "Sorted list " << endl;
    sortv2(listaInicio);
    imprimir(listaInicio);
    // /*Inserta datos desde el final de la lista*/
    // for (int i = 4; i < 7; i++) {
    //     elemento.codigo = i;
    //     insertarAlFinal(listaFinal, elemento);
    // }
    // imprimir(listaFinal);
    //
    // elemento.codigo = 75;
    // insertarEnOrden(listaEnOrden, elemento);
    // elemento.codigo = 5;
    // insertarEnOrden(listaEnOrden, elemento);
    // elemento.codigo = 25;
    // insertarEnOrden(listaEnOrden, elemento);
    // elemento.codigo = 85;
    // insertarEnOrden(listaEnOrden, elemento);
    //
    //
    // imprimir(listaEnOrden);
    //
    // /*Elimina un nodo de la lista correspondiente al elemento ingresado*
    // // [1, 10, 6]
    // /*para que pueda eliminar busca el elemento dentro de la lista para eliminarlo*/
    // elemento.codigo = 85;
    // eliminaNodo(listaEnOrden, elemento);
    // imprimir(listaEnOrden);
    //
    // destruir(listaEnOrden);
    // imprimir(listaEnOrden);
    return 0;
}
