//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD ARBOL BINARIO
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {
    struct ArbolBinario arbol;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4, arbolVacio;
    struct ArbolBinario hijoIzquierdo, hijoDerecho;

    /*               100
     *             /     \
     *           50      150
     *         /   \    /   \
     *       25    80  120   200
     */
    construir(arbol);
    construir(arbol1);

    construir(arbolVacio); // para plantar con nullptr

    //Una forma de crear un arbol es plantando desde el nivel más bajo pero no es la única
    //los árboles binarios tienen criterios para plantar los nodos
    plantarArbolBinario(arbol1, arbolVacio, {25}, arbolVacio);
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);
    plantarArbolBinario(hijoIzquierdo, arbol1, {50}, arbol2);
    plantarArbolBinario(hijoDerecho, arbol3, {150}, arbol4);
    plantarArbolBinario(arbol, hijoIzquierdo, {100}, hijoDerecho);

    cout << "Esta vacio el arbol: " << esArbolVacio(arbol) << endl;
    cout << "Recorrer en En orden: " << endl;
    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Recorrer en pre orden: " << endl;
    recorrerPreOrden(arbol);
    cout << endl;

    cout << "Recorrer en Post orden: " << endl;
    recorrerPostOrden(arbol);
    cout << endl;

    cout << "Numero de hojas: " << numeroHojas(arbol) << endl;
    cout << "Numero de nodos: " << numeroNodos(arbol) << endl;
    cout << "Altura arbol: " <<  altura(arbol)  << endl;
    cout<<"Es equilibrado: "<<esEquilibrado(arbol)<<endl;

    destruirArbolBinario(arbol);
    cout << "Esta vacio el arbol: " << esArbolVacio(arbol) << endl;
    return 0;
}
