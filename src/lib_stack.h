// Copyright [2022] <griselle>

#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

struct stack {
    char sym;
    struct stack *next;
};

struct stack *init(char sym);
void push(struct stack **last, char sym);
char pop(struct stack **last);
void destroy(struct stack **last);
void display_stack(struct stack *stack);

#endif  // SRC_LIB_STACK_H_
