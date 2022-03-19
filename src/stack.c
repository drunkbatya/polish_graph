#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *init(char item) {
    struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack));
    new_stack->item = item;
    new_stack->prev = NULL;
    return new_stack;
}

struct stack *push(struct stack *stack, char item) {
    struct stack *new_stack = (struct stack*)malloc(sizeof(struct stack));
    new_stack->item = item;
    new_stack->prev = stack;
    return new_stack;
}

struct stack *pop(struct stack *stack) {
    struct stack *temp = stack->prev;
    return temp;
}

void destroy(struct stack* stack) {
    struct stack *temp = stack;
    while (stack->prev != NULL) {
        temp = stack;
        stack = stack->prev;
        free(temp);
    }   
    free(stack);
}

