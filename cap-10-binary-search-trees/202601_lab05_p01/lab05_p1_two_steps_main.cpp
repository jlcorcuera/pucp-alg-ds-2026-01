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

    // Step 1: Store all nodes level by level using MARCADOR_NULO as separator
    Cola colaBFS; 
    construir(colaBFS);
    
    Cola colaFinal; 
    construir(colaFinal);

    encolar(colaBFS, {arbol.raiz->elemento.numero});
    encolar(colaBFS, {MARCADOR_NULO});

    while (!esColaVacia(colaBFS)) {
        int numero = desencolar(colaBFS).numero;
        encolar(colaFinal, {numero});

        if (numero == MARCADOR_NULO) {
            if (!esColaVacia(colaBFS)) {
                encolar(colaBFS, {MARCADOR_NULO});
            }
        } else {
            NodoArbolBinarioBusqueda* nodo = obtenerNodo(arbol.raiz, numero);
            if (nodo) {
                if (nodo->izquierda) {
                    encolar(colaBFS, {nodo->izquierda->elemento.numero});
                }
                if (nodo->derecha) {
                    encolar(colaBFS, {nodo->derecha->elemento.numero});
                }
            }
        }
    }

    // Step 2: Iterate the final cola and print in Zig-Zag
    Pila pilaInversa;
    construir(pilaInversa);
    bool izquierdaDerecha = true;
    int nivel = 1;

    cout << "Nivel 1: ";

    while (!esColaVacia(colaFinal)) {
        int val = desencolar(colaFinal).numero;

        if (val == MARCADOR_NULO) {
            // If going from right to left, print all the numbers accumulated in the stack
            if (!izquierdaDerecha) {
                while (!esPilaVacia(pilaInversa)) {
                    cout << desapilar(pilaInversa).numero << " ";
                }
            }
            cout << endl;

            if (!esColaVacia(colaFinal)) {
                nivel++;
                cout << "Nivel " << nivel << ": ";
                izquierdaDerecha = !izquierdaDerecha;
            }
        } else {
            if (izquierdaDerecha) {
                // If going from left to right, print the number directly
                cout << val << " ";
            } else {
                // If going from right to left, push to the stack to reverse the order
                apilar(pilaInversa, {val, 0});
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
