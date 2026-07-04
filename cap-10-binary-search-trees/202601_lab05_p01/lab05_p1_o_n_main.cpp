/*
   Author: J.L.C.B.
   Date: 04/07/2026
   Problem: 1. Zig-Zag order traversal (O(N) solution)
*/

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;

void zigZagOrder(ArbolBinarioBusqueda arbol) {
    if (esArbolVacio(arbol)) return;

    Cola colaActual; construir(colaActual);
    Cola colaSiguiente; construir(colaSiguiente);

    encolar(colaActual, {arbol.raiz});
    bool izquierdaDerecha = true;
    int nivel = 1;

    cout << "Nivel 1: ";
    while (!esColaVacia(colaActual)) {
        NodoArbolBinarioBusqueda *nodo = desencolar(colaActual).nodo;

        if (nodo) {
            cout << nodo->elemento.numero << " ";

            if (izquierdaDerecha) {
                if (nodo->izquierda) encolar(colaSiguiente, {nodo->izquierda});
                if (nodo->derecha) encolar(colaSiguiente, {nodo->derecha});
            } else {
                if (nodo->derecha) encolar(colaSiguiente, {nodo->derecha});
                if (nodo->izquierda) encolar(colaSiguiente, {nodo->izquierda});
            }
        }

        if (esColaVacia(colaActual)) {
            cout << endl;
            izquierdaDerecha = !izquierdaDerecha;
            
            Cola temp = colaActual;
            colaActual = colaSiguiente;
            colaSiguiente = temp;
            
            if (!esColaVacia(colaActual)) {
                nivel++;
                cout << "Nivel " << nivel << ": ";
            }
        }
    }
}

/*
 * IMPLEMENTACION DEL TAD ARBOL BINARIO BUSQUEDA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    /* ABB*/
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
    recorrerPostOrden(arbol); cout<<endl;

    cout << "Recorrer en ZigZag: " << endl;
    zigZagOrder(arbol); cout<<endl;

    return 0;
}