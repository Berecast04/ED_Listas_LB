#include "cdlist.h"
#include <stdlib.h>
#include <string.h>

// Inicialización de la lista circular doblemente enlazada
void cdlist_init(CDList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

// Destruir la lista circular doblemente enlazada
void cdlist_destroy(CDList *list) {
    void *data;
    while (cdlist_size(list) > 0) {
        if (cdlist_remove(list, cdlist_head(list), (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CDList));
}

// Insertar un nodo siguiente en la lista circular doblemente enlazada
int cdlist_ins_next(CDList *list, CDListNode *node, const void *data) {
    CDListNode *new_node;
    
    if ((new_node = (CDListNode *)malloc(sizeof(CDListNode))) == NULL)
        return -1;
    
    new_node->data = (void *)data;

    if (cdlist_size(list) == 0) {  // Lista vacía
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    } else {
        new_node->next = node->next;
        new_node->prev = node;
        node->next->prev = new_node;
        node->next = new_node;
    }

    list->size++;
    return 0;
}

// Eliminar un nodo de la lista circular doblemente enlazada
int cdlist_remove(CDList *list, CDListNode *node, void **data) {
    if (cdlist_size(list) == 0)
        return -1;

    *data = node->data;

    if (cdlist_size(list) == 1) {  // Único elemento en la lista
        list->head = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node == cdlist_head(list)) {
            list->head = node->next;
        }
    }

    free(node);
    list->size--;
    return 0;
}

