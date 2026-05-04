//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
void sort(struct Pila & pilaTAD, struct Pila & pilaOrdenada) {
    while (!esPilaVacia(pilaTAD)) {
        struct ElementoPila maxElement = desapilar(pilaTAD);
        int cantidadARegresar = pilaTAD.longitud;
        for (int i = 0; !esPilaVacia(pilaTAD); i++) {
            struct ElementoPila tmp = desapilar(pilaTAD);
            if (tmp.numero > maxElement.numero) {
                apilar(pilaOrdenada, maxElement);
                maxElement = tmp;
            } else {
                apilar(pilaOrdenada, tmp);
            }
        }
        int i = 0;
        while (i < cantidadARegresar) {
            apilar(pilaTAD, desapilar(pilaOrdenada));
            i++;
        }
        apilar(pilaOrdenada, maxElement);
    }
}

int main(int argc, char ** argv) {
    /*Funciones de Pila*/
    struct Pila pila;
    struct Pila pilaOrdenada;
    struct ElementoPila elemento{};
    construir(pila);
    construir(pilaOrdenada);
    /*Apilamos elementos en la pila*/
    elemento.numero = 100;
    apilar(pila, elemento);

    elemento.numero = -8;
    apilar(pila, elemento);

    elemento.numero = 15;
    apilar(pila, elemento);

    elemento.numero = 7;
    apilar(pila, elemento);

    elemento = cima(pila);
    cout << "La cima es: " << elemento.numero << endl;
    cout << longitud(pila) << endl;
    imprimir(pila);

    cout << "Pila ordenada " << endl;
    sort(pila, pilaOrdenada);
    imprimir(pilaOrdenada);

    // /*Desapilamos elementos en la pila*/
    // while (not esPilaVacia(pila)) {
    //     elemento = desapilar(pila);
    //     cout << "Desapilando: " << elemento.numero << endl;
    // }
    // imprimir(pila);
    return 0;
}
