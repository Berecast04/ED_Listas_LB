#include<stdlib.h>
#include<stdio.h>

#include"list.h"

static void print_list(const List *list){
    ListNode *node;
    int *data, i;

    fprintf(stdout, "List size is %d\n", list_size(list));
    i=0;
    node=list_head (list);
    while (1){
        data=list_data
        fprintf(stdout, "List.node[%03d]=%03d, %p-> %p \n", i, *data, node, node->next );//salida donde va a mandar a imprimir a la pantalla, 
        i++;
        if(list_is_tail(node))
            break;
        else
            node =list_next(node);
    }
    return;
    
    
}

int main(){
    List list;
    ListNode *node;

    int *data, i;

    //init linked list
    list_init(&list, free);
    //fill the list
    node = list_head(&list);
    for(i=20; i>10; i--){
        if((data=(int *)malloc(sizeof(int))) ==NULL)
          return 1;

        *data=i;
        if(list_ins_next(&list, NULL,data)!=0)
            return -1;
    }

    print_list(&list);

    node= list_head(&list);

    for(i=0; i<4; i++)
        node=list_next(node);

    data=list_data(node);
    fprintf(stdout, " \n Removing a node after one containing %03d\n", *data);

    if (list_rem_next(&list, node,(void**)&data)!=0)
        return 1;
    print_list(&list);

    fprintf(stdout,"\nInserting 437 at the tail of the list \n");
    *data=437;
    if(list_ins_next(&list,list_tail(&list),data) != 0 )
        return 1;
    print_list(&list);

    fprintf(stdout, "\nDestroying the list \n");
    list_destroy(&list);

    return 0;
}