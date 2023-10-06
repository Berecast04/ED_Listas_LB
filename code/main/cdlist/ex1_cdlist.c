#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

// Función de muestra para destruir datos
void destroy_data(void *data) {
    free(data);
}

static void print_cdlist(const CDList *my_list) {
    // Imprimir los datos en la lista
    CDListNode *current_node = cdlist_head(my_list);
    int i = 0;

    do {
        int *current_data = (int *)cdlist_data(current_node);
        fprintf(stdout, "Nodo en la lista[%03d] = %03d, %p->%p->%p\n", i, *current_data, current_node->prev, current_node, current_node->next);
        i++;

        current_node = cdlist_next(current_node);
    } while (current_node != cdlist_head(my_list));

    printf("\n");
}

int main() {
    CDList my_list;
    cdlist_init(&my_list, destroy_data);

    // Insertar elementos en la lista
    int *data1 = (int *)malloc(sizeof(int));
    *data1 = 1;
    cdlist_ins_next(&my_list, NULL, data1);

    int *data2 = (int *)malloc(sizeof(int));
    *data2 = 2;
    cdlist_ins_next(&my_list, cdlist_head(&my_list), data2);

   /* // Insertar un nuevo dato previo al primer nodo
    int *new_data = (int *)malloc(sizeof(int));
    *new_data = 0;
    cdlist_ins_prev(&my_list, cdlist_head(&my_list), new_data);*/
    // Insertar un nodo con prev
    int *data4 = malloc(sizeof(int));
    *data4 = 4;
    cdlist_ins_prev(&my_list, cdlist_head(&my_list), data4);

    // Imprimir la lista
    print_cdlist(&my_list);

    int *data3 = (int *)malloc(sizeof(int));
    *data3 = 3;
    cdlist_ins_next(&my_list, cdlist_head(&my_list), data3);

    print_cdlist(&my_list);

    // Eliminar un elemento de la lista
    int *removed_data = NULL;
    if (cdlist_remove(&my_list, cdlist_head(&my_list), (void **)&removed_data) == 0) {
        printf("Elemento eliminado de la lista: %d\n", *removed_data);
        free(removed_data);  // Liberar memoria del elemento eliminado
    }

    print_cdlist(&my_list);

    // Destruir la lista circular doblemente enlazada y liberar la memoria
    cdlist_destroy(&my_list);

    return 0;
}
