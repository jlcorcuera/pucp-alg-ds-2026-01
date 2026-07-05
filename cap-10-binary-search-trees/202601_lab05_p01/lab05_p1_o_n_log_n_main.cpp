/*
   Author: J.L.C.B.
   Date: 04/07/2026
   Problem: 1. Zig-Zag order traversal (O(N*log(N)) solution)
*/

#include <iostream>
#include "BibliotecaCola_numero/Cola.h"
#include "BibliotecaCola_numero/funcionesCola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;


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

    Pila pilaInversa; 
    construir(pilaInversa);

    Cola colaActual; 
    construir(colaActual);

    encolar(colaActual, {arbol.raiz->elemento.numero});
    bool izquierdaDerecha = true;
    int nivel = 1;

    // main loop to control the current level
    while (!esColaVacia(colaActual)) {
        cout << "Nivel " << nivel << ": ";

        // lets iterate over the current queue length
        int n = colaActual.longitud;
        
        // logic to process nodes for the current level
        for (int i = 0; i < n; i++) {
            int numero = desencolar(colaActual).numero;
            // when its from left to right, I have to print the number directly
            if (izquierdaDerecha) {
                cout << numero << " ";
            } else {
                apilar(pilaInversa, {numero, 0});
            }
            // getting references from next level
            NodoArbolBinarioBusqueda* nodo = obtenerNodo(arbol.raiz, numero);
            if (nodo) {
                if (nodo->izquierda) {
                    encolar(colaActual, {nodo->izquierda->elemento.numero});
                }
                if (nodo->derecha) {
                    encolar(colaActual, {nodo->derecha->elemento.numero});
                }
            }
        }
        
        // logic to print the current level based on the zigzag order
        if (!izquierdaDerecha) {
            // the stack used to print in the reverse order, 
            // in the original version I haved used a List
            // in this version I haved used a stack
            while (!esPilaVacia(pilaInversa)) {
                cout << desapilar(pilaInversa).numero << " ";
            }
        }
        cout << endl;
        
        // switch the direction for the next level
        izquierdaDerecha = !izquierdaDerecha;
        nivel++;
    }
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
    zigZagOrder(arbol); cout << endl;

    return 0;
}
