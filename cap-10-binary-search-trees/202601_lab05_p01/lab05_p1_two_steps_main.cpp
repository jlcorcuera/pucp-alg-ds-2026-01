/*
   Author: J.L.C.B.
   Date: 04/07/2026
   Problem: 1. Zig-Zag order traversal (Two Steps Solution)
*/

#include <iostream>
#include "BibliotecaCola_numero/Cola.h"
#include "BibliotecaCola_numero/funcionesCola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
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

    // Remember: only two TADs are allowed!
    Cola cola; 
    construir(cola);
    
    Pila pila; 
    construir(pila);

    // Step 1: Traverse the tree and temporarily save them in the stack (it will be in reverse order)
    encolar(cola, {arbol.raiz->elemento.numero});
    encolar(cola, {MARCADOR_NULO});

    while (!esColaVacia(cola)) {
        int numero = desencolar(cola).numero;
        apilar(pila, {numero, 0});

        if (numero == MARCADOR_NULO) {
            if (!esColaVacia(cola)) {
                encolar(cola, {MARCADOR_NULO});
            }
        } else {
            NodoArbolBinarioBusqueda* nodo = obtenerNodo(arbol.raiz, numero);
            if (nodo) {
                if (nodo->izquierda) {
                    encolar(cola, {nodo->izquierda->elemento.numero});
                }
                if (nodo->derecha) {
                    encolar(cola, {nodo->derecha->elemento.numero});
                }
            }
        }
    }

    // At this point, we have the elements in the Stack in bottom-up order
    // It is required to change to top-down order
    while (!esPilaVacia(pila)) {
        encolar(cola, {desapilar(pila).numero});
    }
    // From Cola -> Pila result: the Stack is in top-down order
    while (!esColaVacia(cola)) {
        apilar(pila, {desencolar(cola).numero, 0});
    }
    // From Pila -> Cola result: the Queue is in top-down order ready for use in step 2
    while (!esPilaVacia(pila)) {
        encolar(cola, {desapilar(pila).numero});
    }

    // Step 2: Iterate the Queue and print in Zig-Zag
    bool izquierdaDerecha = true;
    int nivel = 1;

    cout << "Nivel 1: ";

    while (!esColaVacia(cola)) {
        int val = desencolar(cola).numero;

        if (val == MARCADOR_NULO) {
            // If going right to left, print the stack content
            if (!izquierdaDerecha) {
                while (!esPilaVacia(pila)) {
                    cout << desapilar(pila).numero << " ";
                }
            }
            cout << endl;

            // Next level
            if (!esColaVacia(cola)) {
                nivel++;
                cout << "Nivel " << nivel << ": ";
                izquierdaDerecha = !izquierdaDerecha;
            }
        } else {
            if (izquierdaDerecha) {
                // If going left to right, print the number
                cout << val << " ";
            } else {
                // If going right to left, stack the number to print it in the next iteration
                apilar(pila, {val, 0});
            }
        }
    }
}

int main(int argc, char **argv) {
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
    
    cout << "Recorrer en Post: " << endl;
    recorrerPostOrden(arbol); cout << endl;

    cout << "Recorrer en ZigZag: " << endl;
    zigZagOrder(arbol); 

    return 0;
}
