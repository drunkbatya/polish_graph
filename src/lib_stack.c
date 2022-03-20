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
        printf("%c ", temp->sym);
        temp = temp->next;
    }
    printf("%c", temp->sym);
}

n_stack *n_init(float item) {
    n_stack *ret;

    ret = (n_stack *)malloc(sizeof(n_stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->item = item;
    return (ret);
}

void n_push(n_stack **last, float item) {
    n_stack *ret;

    ret = (n_stack *)malloc(sizeof(n_stack));
    ret->next = *last;
    ret->item = item;
    *last = ret;
}

float n_pop(n_stack **last) {
    n_stack *ptr;
    float item;

    if (*last == NULL) {
        printf("stack.c: Stack UNDERflow error!.. ");
        return (-1);
    }
    ptr = (*last)->next;
    item = (*last)->item;
    free(*last);
    *last = ptr;
    return (item);
}

void n_destroy(n_stack **last) {
    n_stack *ret;
    n_stack *temp;

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

void n_display_stack(n_stack *last) {
    n_stack *temp;
    temp = last;
    while (temp->next != NULL) {
        printf("%.2lf ", temp->item);
        temp = temp->next;
    }
    printf("%.2lf", temp->item);
}

