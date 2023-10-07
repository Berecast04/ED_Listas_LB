#include <stdio.h>
#include "cdlist.h"


static void print_cdlist(const CDList *list) {
    // Imprimir los datos en la lista
    CDListNode *current_node = cdlist_head(list);
    int i = 0;

    do {
        int *current_data = (int *)cdlist_data(current_node);
        fprintf(stdout, "Nodo en la lista[%03d] = %03d, %p->%p->%p\n", i, *current_data, current_node->prev, current_node, current_node->next);
        i++;

        current_node = cdlist_next(current_node);
    } while (current_node != cdlist_head(list));

    printf("\n");
}


int main() {
    CDList list;
    cdlist_init(&list, free); // Usamos free para liberar la memoria de los datos

    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data1 = 30;
    *data2 = 24;
    *data3 = 5834;

    // Insertar nodos con next
    cdlist_ins_next(&list, NULL, data1);
    cdlist_ins_next(&list, cdlist_head(&list), data2);
    cdlist_ins_next(&list, cdlist_head(&list)->next, data3);

    // Imprimir la lista
    printf("-------------Lista despues de insertar con next:-------------\n");
    print_cdlist(&list);

    // Insertar un nodo con prev
    int *data4 = malloc(sizeof(int));
    *data4 = 432;
    cdlist_ins_prev(&list, cdlist_head(&list), data4);

    // Imprimir la lista
    printf("\n-------------Lista despues de insertar con prev:-------------\n");
    print_cdlist(&list);

    // Eliminar un nodo	
    int *removed_data;
    cdlist_remove(&list, cdlist_head(&list)->next, (void **)&removed_data);
    free(removed_data);
    
	// Imprimir la lista después de eliminar un nodo
    printf("\n-------------Lista despues de eliminar un nodo sig a la cabeza :-------------\n");
    print_cdlist(&list);
    
    // Eliminar un nodo	
   
    cdlist_remove(&list, cdlist_head(&list)->prev, (void **)&removed_data);
    free(removed_data);

    // Imprimir la lista después de eliminar un nodo
    printf("\n-------------Lista despues de eliminar un nodo previo a la cabeza:-------------\n");
    print_cdlist(&list);

    // Destruir la lista y liberar la memoria
    cdlist_destroy(&list);

    return 0;
}
