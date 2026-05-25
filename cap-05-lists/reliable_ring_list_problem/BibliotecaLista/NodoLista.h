//Fecha:  sábado 06 Setiembre 2025
//Autor: Ana Roncal

#ifndef LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#include "ElementoLista.h"

/*
 * NodoLista representa un nodo del anillo distribuido.
 *   elemento  : datos del proceso (node_id, is_active)
 *   siguiente : puntero al nodo siguiente inmediato (canal primario)
 *   skip_next : puntero al subsiguiente — vecino del vecino (canal de respaldo)
 *               Permite hacer failover si `siguiente` está caído.
 */
struct NodoLista {
    struct ElementoLista  elemento;
    struct NodoLista    * next;   // next inmediato
    struct NodoLista    * skip_next;   // salto de respaldo (next->next)
};

#endif //LISTASIMPLEMENTEENLAZADA_NODOLISTA_H