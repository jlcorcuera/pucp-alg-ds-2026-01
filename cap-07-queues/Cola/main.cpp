//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */

void sortV1(struct Cola & colaTAD, struct Cola & colaOrdenada) {
    while (!esColaVacia(colaTAD)) {
        ElementoCola currentMin = desencolar(colaTAD);
        for (int i = 0; i < colaTAD.longitud; i++) {
            struct ElementoCola elemento = desencolar(colaTAD);
            if (elemento.codigo < currentMin.codigo) {
                encolar(colaTAD, currentMin);
                currentMin = elemento;
            } else {
                encolar(colaTAD, elemento);
            }
        }
        encolar(colaOrdenada, currentMin);
    }
}

void sortV2(struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        return;
    }
    ElementoCola currentMax = desencolar(colaTAD);
    for (int i = 0; i < colaTAD.longitud; i++) {
        struct ElementoCola elemento = desencolar(colaTAD);
        if (elemento.codigo > currentMax.codigo) {
            encolar(colaTAD, currentMax);
            currentMax = elemento;
        } else {
            encolar(colaTAD, elemento);
        }
    }
    sortV2(colaTAD);
    encolar(colaTAD, currentMax);
}



int main(int argc, char **argv) {
    struct Cola cola;
    struct Cola colaOrdenada;
    struct ElementoCola elemento;
    construir(cola);
    construir(colaOrdenada);

    elemento.codigo = 50;
    encolar(cola, elemento);

    elemento.codigo = 20;
    encolar(cola, elemento);

    elemento.codigo = -10;
    encolar(cola, elemento);

    elemento.codigo = 15;
    encolar(cola, elemento);

    elemento.codigo = 90;
    encolar(cola, elemento);

    cout << "Initial State: " << endl;
    imprimir(cola);
    cout << "New State: " << endl;
    //sortV1(cola, colaOrdenada);
    //imprimir(colaOrdenada);
    cout << "sortV2: " << endl;
    sortV2(cola);
    imprimir(cola);
    //
    // cout << "La cola esta vacia: " << esColaVacia(cola) << endl;
    // /*Encolamos elementos en la Cola*/
    // for (int i = 4; i < 20; i+= 3) {
    //     elemento.codigo = i;
    //     encolar(cola, elemento);
    // }
    //
    // imprimir(cola);
    // /*Desencolamos elementos de la cola*/
    // while(not esColaVacia(cola)){
    //     elemento = desencolar(cola);
    //     cout<<"Desencolando: "<<elemento.codigo <<endl;
    // }
    // imprimir(cola);
    return 0;
}
