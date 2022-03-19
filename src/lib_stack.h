// Copyright [2022] <griselle>

#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

struct stack {
    int num;
    struct stack *next;
};

struct stack *init(int num);
void push(struct stack **last, int num);
int pop(struct stack **last);
void destroy(struct stack **last);
#endif  // SRC_LIB_STACK_H_
