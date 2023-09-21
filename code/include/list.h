/*
list.h
*/

#ifndef LIST_H //ubica si ya hay un archivo asi y si no lo crea en el apartado de abajo
#define LIST_H

#include<stdlib.h>

//linked list node
typedef struct ListNode_{
    void *data;//puede ser lo que quiera ser data
    struct ListNode_ *next;
}ListNode;

//list definition

typedef struct LIST_{
    int size;

    void (*destroy) (void *data);//es un pointer que apunt aa una funcion //destroy luego lo vamos a hacer reservado y le vamos a poner free

    ListNode *head;// llega a ser la herencia del objeto 
    ListNode *tail;
}List;//objeto 

//interfaces 
void list_init(List *list, void (*destroy)(void *data));//igual que la linea 21,, 
void list_destroy(List *list);

int list_ins_next(List *list, ListNode *node, const void *data);//const que mi funcion no me modifique mi data, proteger 
int list_rem_next(List *list, ListNode *noide, void **data);//genero un apuntador que apunta al data que apunta a data 

//macros
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list,node) ((node)==(list)->head? 1 : 0)
#define list_is_tail(node) ((node)->next==NULL? 1 : 0)//#define list_is_tail(list,node) ((node)->next ==NULL? 1 : 0)

#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif