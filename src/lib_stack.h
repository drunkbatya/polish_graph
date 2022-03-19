// Copyright [2022] <griselle>

#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

struct int_stack {
    int num;
    struct int_stack *next;
};

struct char_stack {
    char sym;
    struct char_stack *next;
};

struct int_stack *int_init(int num);
struct char_stack *char_init(char sym);
void int_push(struct int_stack **last, int num);
void char_push(struct char_stack **last, char sym);
int int_pop(struct int_stack **last);
char char_pop(struct char_stack **last);
void int_destroy(struct int_stack **last);
void char_destroy(struct char_stack **last);
#endif  // SRC_LIB_STACK_H_
