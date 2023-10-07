//ex1_clist_char.c

#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

// Función de muestra para destruir datos (en este caso, liberar memoria)
void destroy_data(void *data) {
    free(data);
}

// Función para imprimir la lista circular de caracteres
static void print_clist(const CList my_list) {
    CListNode *current_node = clist_head(&my_list);
    int i = 0;

    // Imprimir los datos en la lista
    while (current_node != NULL) {
        char *current_data = (char *)clist_data(current_node);

        fprintf(stdout, "Nodo en la lista[%03d]=%c, %p->%p\n", i, *current_data, current_node, current_node->next);

        i++;

        // current_node es el último elemento en la lista circular
        if (current_node->next == clist_head(&my_list))
            break;
        else
            current_node = clist_next(current_node);
    }
    printf("\n");
}

int main() {
    CList my_list;
    clist_init(&my_list, destroy_data);

    // Insertar elementos de tipo char en la lista
    char *data1 = (char *)malloc(sizeof(char));
    *data1 = 'A';
    clist_ins_next(&my_list, NULL, data1);

    char *data2 = (char *)malloc(sizeof(char));
    *data2 = 'B';
    clist_ins_next(&my_list, clist_head(&my_list), data2);

    char *data3 = (char *)malloc(sizeof(char));
    *data3 = 'C';
    clist_ins_next(&my_list, clist_head(&my_list), data3);

    print_clist(my_list);

    // Eliminar un elemento de la lista
    char *removed_data = NULL;
    if (clist_rem_next(&my_list, clist_head(&my_list), (void **)&removed_data) == 0) {
        printf("Elemento eliminado de la lista: %c\n", *removed_data);
        free(removed_data);  // Liberar memoria del elemento eliminado
    }

    print_clist(my_list);

    // Destruir la lista circular y liberar la memoria
    clist_destroy(&my_list);

    return 0;
}
