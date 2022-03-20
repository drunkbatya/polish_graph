// Copyright [2022] <griselle, laynadre>

#include "lib_stack.h"
#include <stdio.h>
#include <stdlib.h>

stack *init(char sym) {
    stack *ret;

    ret = (stack *)malloc(sizeof(stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->sym = sym;
    return (ret);
}

void push(stack **last, char sym) {
    stack *ret;

    ret = (stack *)malloc(sizeof(stack));
    ret->next = *last;
    ret->sym = sym;
    *last = ret;
}

char pop(stack **last) {
    stack *ptr;
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

void destroy(stack **last) {
    stack *ret;
    stack *temp;

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

void display_stack(stack *last) {
    stack *temp;
    temp = last;
    while (temp->next != NULL) {
        printf("%c", temp->sym);
        temp = temp->next;
    }
    printf("%c", temp->sym);
}
