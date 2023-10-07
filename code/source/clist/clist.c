/*
	clist.c
*/

#include "clist.h"

//Inicilizacion de la lista
void clist_init(CList *clist, void (*destroy)(void *data)){
	clist->size=0;
	clist->destroy=destroy;
	clist->head=NULL;
	
	return;
}

//Destruir la lista

void clist_destroy(CList *clist){
	void *data;
	
	while (clist_size(clist)>0){
		if (clist_rem_next(clist,NULL, (void **)&data) ==0 && clist->destroy != NULL){
			clist->destroy(data);
		}
	}
	memset(clist,0,sizeof(CList));
	return;
	
}

//insertar un nodo siguiente en la lista

int clist_ins_next(CList *clist, CListNode *node,const void *data){
	CListNode *new_node;
	
	if((new_node = (CListNode *) malloc(sizeof(CListNode))) ==NULL)
		return -1;
		
	new_node->data = (void *)data;
	
	// Iniciando la insercion al principio de la lista
    if (node == NULL) {
        
        // Lista vacia?
        if (clist_size(clist) == 0){
        	clist->head=new_node;
        	new_node->next=clist->head;
        	
		}
        
    } else {
        
        new_node->next = node->next;
        node->next = new_node;
    }

    clist->size++;

    return 0;
}

//Remover el nodo siguiente de la lista

int clist_rem_next (CList *clist, CListNode *node, void **data) {
    CListNode *old_node;
  

    // La lista esta vacia?
    if (clist_size(clist) == 0)
        return -1;
    
    //borrar la cabeza
    if (node == NULL) {
    
        *data = clist->head->data;
        old_node = clist->head;
        clist->head = clist->head->next;
        
        // Ultimo nodo de la lista
        if (clist_size(clist) == 1)
            clist->head = NULL;
	}else{

        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;
        
    }

    free(old_node);
    clist->size--;

    return 0;
}
