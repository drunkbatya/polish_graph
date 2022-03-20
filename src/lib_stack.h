// Copyright [2022] <griselle, laynadre>

#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

typedef struct stack_t {
    char sym;
    struct stack_t *next;
} stack;

stack *init(char sym);
void push(stack **last, char sym);
char pop(stack **last);
void destroy(stack **last);
void display_stack(stack *stack);

#endif  // SRC_LIB_STACK_H_
