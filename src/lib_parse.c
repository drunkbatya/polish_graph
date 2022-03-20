// Copyright [2022] <griselle, laynadre>

#include "lib_parse.h"
#include "lib_stack.h"
#include <string.h>
#include <stdio.h>

void add_to_polish(char *polish, char *input_str, int shift) {
    for (int i = 0; i < shift; i++) {
        *polish = *input_str;
        polish++;
        input_str++;
    }
    *polish = ' ';
}

int priority(char op) {
    if (strchr("(", op))
        return (0);
    if (strchr("+-", op))
        return (1);
    if (strchr("*/", op))
        return (2);
    if (strchr("sctgl", op))
        return (3);
    if (strchr("q^", op))
        return (4);
    return (0);
}

int extract_num(char *str, int *num) {
    int shift;

    shift = 0;
    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            break;
        *num = *num * 10 + (*str - '0');
        str++;
        shift++;
    }
    return (shift);
}

int extract_op(char *str, char *op, int *shift) {
    if ((!*shift) && (*str == '-')) {  // Unary minus processing
        *op = '~';
        *shift = 1;
        return (1);
    }
    *shift = 2;
    if (!strncmp(str, "ln", *shift)) {
        *op = 'l';
        return (1);
    }
    *shift = 3;
    if (!strncmp(str, "sin", *shift)) {
        *op = 's';
        return (1);
    }
    if (!strncmp(str, "cos", *shift)) {
        *op = 'c';
        return (1);
    }
    if (!strncmp(str, "tan", *shift)) {
        *op = 't';
        return (1);
    }
    if (!strncmp(str, "ctg", *shift)) {
        *op = 'g';
        return (1);
    }
    *shift = 4;
    if (!strncmp(str, "sqrt", *shift)) {
        *op = 'q';
        return (1);
    }
    *shift = 1;
    if (*str == '-') {
        if (*(str - 1) == '(') {
            *op = '~';
            return (1);
        }
    }
    if (strchr(")^+-/*(", *str)) {
        *op = *str;
        return (1);
    }
    return (0);
}

void add_x_to_polish(char **input_str, char **polish, int *shift) {
    add_to_polish(*polish, *input_str, 1);
    ++*polish;
    **polish = ' ';
    ++*polish;
    ++*input_str;
    *shift = 1;
}

void add_num_to_polish(char **input_str, char **polish, int *num, int *shift) {
    *shift = extract_num(*input_str, num);
    add_to_polish(*polish, *input_str, *shift);
    *polish = *polish + *shift + 1;  // + 1 - for the added space
}

void add_op_to_polish(char **polish, int *shift, char op) {
    **polish = op;
    *(*polish + 1)= ' ';  // TODO(griselle): chars after sin/lb/cos... don't go into polish (ex.: ln(x) = l)
    *polish = *polish + *shift + 1;
}

int op_routing(char **polish, int *shift, stack **op_stack, char op) {
    char last;

    if (*op_stack == NULL) {
        *op_stack = init(op);
        return (1);
    }
    if (op == '(') {
        push(op_stack, op);
        return (1);
    }
    if (op == ')') {
        while (*op_stack) {
            last = pop(op_stack);
            if (last == '(') {
                return (1);
            }
            add_op_to_polish(polish, shift, last);
        }
        return (0);
    }
    last = pop(op_stack);
    if (priority(op) > priority(last)) {
        push(op_stack, last);
        push(op_stack, op);
        return (1);
    }
    while (priority(op) <= priority(last)) {
        add_op_to_polish(polish, shift, last);
        if (*op_stack == NULL) {
            *op_stack = init(op);
            return (1);
        } else {
            last = pop(op_stack);
        }
    }
    if (*op_stack)
        push(op_stack, last);
    else
        *op_stack = init(last);
    return (0);
}
