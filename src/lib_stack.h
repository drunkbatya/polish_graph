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

typedef struct stack_num {
    float item;
    struct stack_num *next;
} n_stack;

n_stack *n_init(float item);
void n_push(n_stack **last, float item);
float n_pop(n_stack **last);
void n_destroy(n_stack **last);
void n_display_stack(n_stack *stack);

#endif  // SRC_LIB_STACK_H_
