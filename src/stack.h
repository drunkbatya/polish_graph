#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
    char item;
    struct stack *prev;
};

struct stack *init(char item);
struct stack *push(struct stack *stack, char item);
struct stack *pop(struct stack *stack);
void destroy(struct stack* stack);

#endif  // SRC_STACK_H_
