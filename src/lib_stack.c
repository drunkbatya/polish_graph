// Copyright [2022] <griselle>

#include "lib_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct int_stack *int_init(int num) {
    struct int_stack *ret;

    ret = (struct int_stack *)malloc(sizeof(struct int_stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->num = num;
    return (ret);
}

struct char_stack *char_init(char sym) {
    struct char_stack *ret;

    ret = (struct char_stack *)malloc(sizeof(struct char_stack));
    if (ret == NULL) {
        printf("stack.c: Memmory allocation error!.. ");
        return (ret);
    }
    ret->next = NULL;
    ret->sym = sym;
    return (ret);
}

void int_push(struct int_stack **last, int num) {
    struct int_stack *ret;

    ret = (struct int_stack *)malloc(sizeof(struct int_stack));
    ret->next = *last;
    ret->num = num;
    *last = ret;
}

void char_push(struct char_stack **last, char sym) {
    struct char_stack *ret;

    ret = (struct char_stack *)malloc(sizeof(struct char_stack));
    ret->next = *last;
    ret->sym = sym;
    *last = ret;
}

int int_pop(struct int_stack **last) {
    struct int_stack *ptr;
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

char char_pop(struct char_stack **last) {
    struct char_stack *ptr;
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

void int_destroy(struct int_stack **last) {
    struct int_stack *ret;
    struct int_stack *temp;

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

void char_destroy(struct char_stack **last) {
    struct char_stack *ret;
    struct char_stack *temp;

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
