// Copyright [2022] <griselle>

#include "lib_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *init(char sym) {
    struct stack *ret;

    ret = (struct stack *)malloc(sizeof(struct stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->sym = sym;
    return (ret);
}

void push(struct stack **last, char sym) {
    struct stack *ret;

    ret = (struct stack *)malloc(sizeof(struct stack));
    ret->next = *last;
    ret->sym = sym;
    *last = ret;
}

char pop(struct stack **last) {
    struct stack *ptr;
    char sym;

    if (*last == NULL) {
        printf("stack.c: Stack UNDERflow error!.. ");
        return (-1);
    }
    ptr = (*last)->next;
    sym = (*last)->sym;
    free(*last);
    *last = ptr;
    return (sym);
}

void destroy(struct stack **last) {
    struct stack *ret;
    struct stack *temp;

    ret = *last;
    while (ret) {
        if (ret->next == NULL) {
            *last = NULL;
            return (free(ret));
        }
        temp = ret->next;
        free(ret);
        ret = temp;
    }
}

void display_stack(struct stack *stack) {
    struct stack *temp;
    temp = stack;
    while (temp->next != NULL) {
        printf("%c", temp->sym);
        temp = temp->next;
    }
    printf("%c", temp->sym);
}
