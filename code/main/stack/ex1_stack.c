#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*
    Print queue
*/
static void print_stack(const Stack *stack) {
    ListNode *node;
    int *data, size, i;

    fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));

    i = 0;
    node = list_head(stack);

    while (i < size) {
       data = list_data(node);
       fprintf(stdout, "stack[%03d]=%03d, %p -> %p\n", i, *data, node, node->next);
       node = list_next(node);
       i++;
    }
    return;
}

// Main program
int main(int argc, char const *argv[]) {
    Stack stack;
    int *data, i;

    // Initialize the queue
    stack_init(&stack, free);

    fprintf(stdout, "\nPush 10 elements\n");

    for (i = 10; i < 20; i++) {

        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

            *data = i + 1;

        if (stack_push(&stack, data) != 0)
            return 1;
    }
    print_stack(&stack);

    fprintf(stdout, "\nPop 3 elements\n");
    for (i = 0; i < 3; i++) {
        if(stack_pop(&stack, (void **)&data) == 0)
            free(data);
        else
            return 1;
    }
    print_stack(&stack);

    fprintf(stdout, "\nPop 001 and 998\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
   *data = 1;
    if (stack_push(&stack, data) != 0)
        return 1;

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 998;
    if (stack_push(&stack, data) != 0)
        return 1;
    
    print_stack(&stack);

    if ((data = stack_peek(&stack)) != NULL)
        fprintf(stdout, "\nPeeking at the head element [value]=%03d\n", *data);
    else
        fprintf(stdout, "\nPeeking at the head element [value]=NULL\n");
    print_stack(&stack);

    fprintf(stdout, "Pop all elements\n");
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, (void **)&data) == 0)
            free(data);
    }
    if ((data = stack_peek(&stack)) != NULL)
        fprintf(stdout, "\nPeeking at an empty [value]=%03d\n", *data);
    else
        fprintf(stdout, "\nPeeking at an empty [value]=NULL\n");
    print_stack(&stack);

    fprintf(stdout, "\nDestroying the queue\n");
    stack_destroy(&stack);
    return 0;
}
