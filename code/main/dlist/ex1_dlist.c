#include <stdio.h>
#include <stdlib.h> // Necesario para la función malloc
#include "dlist.h"

// Función de ejemplo para destruir datos almacenados en la lista
void destroy_data(void *data) {
    free(data); // En este ejemplo, asumimos que los datos son punteros a memoria dinámica que deben liberarse.
}
static void print_list(const DList my_list){
	// Imprimir los datos en la lista
    DListNode *current_node = dlist_head(&my_list);
    int i=0;
    while (current_node != NULL) {
        int *current_data = (int *)dlist_data(current_node);
        
        
        
		fprintf(stdout, "Nodo en la lista[%03d]=%03d,%p <- %p->%p \n", i , *current_data,current_node->prev,current_node, current_node->next);
		
		i++;
		
		//revisa si es el final de la lista 
		if (dlist_is_tail(current_node))
			break;
		else 
			current_node =dlist_next(current_node);
    }
    printf("\n");
}

int main() {
    DList my_list;
    dlist_init(&my_list, free);

    // Insertar algunos datos en la lista
    int *data1 = malloc(sizeof(int));
    *data1 = 42;
    dlist_ins_next(&my_list, NULL, data1);
    print_list(my_list);

    int *data2 = malloc(sizeof(int));
    *data2 = 23;
    dlist_ins_next(&my_list, dlist_head(&my_list), data2);
    print_list(my_list);

    // Insertar un dato antes del primer nodo
    int *data3 = malloc(sizeof(int));
    *data3 = 99;
    dlist_ins_prev(&my_list, dlist_head(&my_list), data3);
    print_list(my_list);
    
    
    // Insertar un dato antes del primer nodo
    int *data4 = malloc(sizeof(int));
    *data4 = 234;
    dlist_ins_prev(&my_list, dlist_head(&my_list), data4);
    print_list(my_list);


    // Eliminar un nodo de la lista
    int *removed_data;
    dlist_remove(&my_list, dlist_head(&my_list), (void **)&removed_data);
    free(removed_data); // Liberar el dato eliminado
    
    

    // Destruir la lista y liberar la memoria
    dlist_destroy(&my_list);

    return 0;
}
