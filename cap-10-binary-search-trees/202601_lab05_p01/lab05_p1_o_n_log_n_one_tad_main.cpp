/*
   Author: J.L.C.B.
   Date: 04/07/2026
   Problem: 1. Zig-Zag order traversal (O(N*log(N)) solution)
*/

#include <iostream>
#include "BibliotecaCola_numero/Cola.h"
#include "BibliotecaCola_numero/funcionesCola.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;

const int MARCADOR_NULO = -1; 

NodoArbolBinarioBusqueda* obtenerNodo(NodoArbolBinarioBusqueda* nodo, int elemento) {
    while (nodo != nullptr) {
        if (nodo->elemento.numero == elemento) {
            return nodo;
        }
        if (elemento < nodo->elemento.numero) {
            nodo = nodo->izquierda;
        } else {
            nodo = nodo->derecha;
        }
    }
    return nullptr;
}

void zigZagOrder(ArbolBinarioBusqueda arbol) {
    if (esArbolVacio(arbol)) return;

    Cola cola; construir(cola);

    encolar(cola, {arbol.raiz->elemento.numero});
    encolar(cola, {MARCADOR_NULO}); 

    bool izquierdaDerecha = true;
    int nivel = 1;

    cout << "Nivel 1: ";
    
    while (!esColaVacia(cola)) {
        int numero = desencolar(cola).numero;
        
        if (numero == MARCADOR_NULO) {
            if (!esColaVacia(cola)) {
                cout << endl;
                nivel++;
                cout << "Nivel " << nivel << ": ";
                encolar(cola, {MARCADOR_NULO}); 
                izquierdaDerecha = !izquierdaDerecha; 
            }
        } else {
            NodoArbolBinarioBusqueda* nodo = obtenerNodo(arbol.raiz, numero);
            
            cout << nodo->elemento.numero << " ";
            
            if (izquierdaDerecha) {
                if (nodo->izquierda) encolar(cola, {nodo->izquierda->elemento.numero});
                if (nodo->derecha) encolar(cola, {nodo->derecha->elemento.numero});
            } else {
                if (nodo->derecha) encolar(cola, {nodo->derecha->elemento.numero});
                if (nodo->izquierda) encolar(cola, {nodo->izquierda->elemento.numero});
            }
        }
    }
    cout << endl;
}

int main(int argc, char **argv) {

    /* ABB */
    ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol, {9});
    insertar(arbol, {4});
    insertar(arbol, {14});
    insertar(arbol, {11});
    insertar(arbol, {16});
    insertar(arbol, {19});
    insertar(arbol, {1});
    insertar(arbol, {6});
    
    // 1 6 4 11 19 16 14 9
    cout << "Recorrer en Post: " << endl;
    recorrerPostOrden(arbol); cout << endl;

    cout << "Recorrer en ZigZag: " << endl;
    zigZagOrder(arbol); 

    return 0;
}
