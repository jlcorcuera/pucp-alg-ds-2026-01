//Fecha:  sábado 06 Setiembre 2025
//Autor: Ana Roncal

#ifndef LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H

/*
 * ElementoLista representa los datos de un proceso en el anillo distribuido.
 *   node_id   : identificador único del nodo/proceso
 *   is_active : true si el nodo está operativo, false si colapsó
 */
struct ElementoLista {
    int  node_id;
    bool is_active;
};

#endif //LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H