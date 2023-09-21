//list.c

#include<stdlib.h>


#include "list.h"

//init list
void list_init(List *list, void(*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

//destroy list
void list_destroy(List *list){
    void *data;

    while(list_size(list) > 0){
        if(list_rem_next(list,NULL,(void **) &data ) == 0 && list-> destroy != NULL)/*va a borrar con la cabeza*/{
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(List));
    return;
}

//insert next node
int list_ins_next(List *list, ListNode *node, const void *data){
    ListNode *new_node; 

    if(new_node = (ListNode *)malloc(sizeof(ListNode)) == NULL){//genera un espacio de memoria 
        return -1;
    }

    if(node == NULL){//cuando quiero insertar en la cabeza
        if(node->next == NULL){
            list->tail = new_node;
        }
        new_node->next = list->head;
        list->head = new_node;
    }else{
        if (node ->next == NULL)
            list->tail = new_node;
        new_node->next = node->next;
        node->next = new_node;
    }
    list->size++;
    return 0;
}

int list_rem_next(List *list, ListNode *node, void **data){

    ListNode *old_node;

    if(list_size(list)==0)
        return -1;

    if(node==NULL ){
        *data=list->head->data;
        old_node =list->head;
        list->head= list->head->next;
        if (list size(list)==1)
                    list->tail =NULL;
    }else{
        if(node->next ==NULL)
            return -1;

        *data=node->next->data;
        old_node=node->next;
        node->next =node->next->next;
    }

    free(old_node);
    list->size--;

    return 0;
}