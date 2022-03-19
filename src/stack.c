// Copyright [2022] <griselle>

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *init(int num) {
    struct stack *ret;

    ret = (struct stack *)malloc(sizeof(struct stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->num = num;
    return (ret);
}

void push(struct stack **last, int num) {
    struct stack *ret;

    ret = (struct stack *)malloc(sizeof(struct stack));
    ret->next = *last;
    ret->num = num;
    *last = ret;
}

int pop(struct stack **last) {
    struct stack *ptr;
    int num;

    if (*last == NULL) {
        printf("stack.c: Stack UNDERflow error!.. ");
        return (-1);
    }
    ptr = (*last)->next;
    num = (*last)->num;
    free(*last);
    *last = ptr;
    return (num);
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
