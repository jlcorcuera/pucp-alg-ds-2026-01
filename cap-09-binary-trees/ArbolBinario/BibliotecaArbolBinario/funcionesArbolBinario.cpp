//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "funcionesArbolBinario.h"
#include "ArbolBinario.h"
using namespace std;

void construir(struct ArbolBinario &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct ArbolBinario &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoArbolBinario *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct ArbolBinario &arbol, const struct ArbolBinario &izquierda,
                         const struct ElementoArbolBinario &elemento, const struct ArbolBinario &derecha) {
    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoArbolBinario *&nodo, struct NodoArbolBinario *izquierda,
                             const struct ElementoArbolBinario &elemento, struct NodoArbolBinario *derecha) {
    struct NodoArbolBinario *nuevo = new struct NodoArbolBinario;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoArbolBinario *raiz) {
    cout << setw(5) << raiz->elemento.numero;
}

void recorrerPreOrden(const struct ArbolBinario &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoArbolBinario *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct ArbolBinario &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el árbol en orden */
void recorrerEnOrdenRecursivo(struct NodoArbolBinario *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct ArbolBinario &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoArbolBinario *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct ArbolBinario &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbolBinario *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct ArbolBinario &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoArbolBinario *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct ArbolBinario & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoArbolBinario * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int maximo(int a, int b){
    return a >= b ? a : b;
}

bool esEquilibrado(const struct ArbolBinario & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoArbolBinario * nodo){

    if(esNodoVacio(nodo))
        return true;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <=1 and esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }

}

void destruirArbolBinario(struct ArbolBinario & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbolBinario * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}