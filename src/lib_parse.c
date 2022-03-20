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
    if (strchr("+-", op))
        return (0);
    if (strchr("*/", op))
        return (1);
    if (strchr("sctgl", op))
        return (2);
    if (strchr("q^", op))
        return (3);
    if (strchr("()", op))
        return (4);
    return (0);
}

/*
void add_to_stack(char op, char *polish, stack *root) {
   if (priority(op) > 1)
       printf("%c", *polish);
}
*/

int extract_num(char *str, int *num) {
    int shift;

    shift = 0;
    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            break;
      //  *num = *num * 10 + (*str - '0');
        str++;
        shift++;
    }
    printf("\nnum is %d", *num);
  //  *num = 0;
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
    if (strchr("^+-/*()", *str)) {
        *op = *str;
        return (1);
    }
    return (0);
}

void add_x_to_polish(char **input_str, char **polish) {
    add_to_polish(*polish, *input_str, 1);
    ++*polish;
    **polish = ' ';
    ++*polish;
    ++*input_str;
}

void add_num_to_polish(char **input_str, char **polish, int *num, int *shift) {
    *shift = extract_num(*input_str, num);
    add_to_polish(*polish, *input_str, *shift);
    *polish = *polish + *shift + 1;  // + 1 - for the added space
}

void add_op_to_polish(char **polish, int *shift, stack **op_stack, char *op) {
    **polish = *op;
    *(*polish + 1)= ' ';
    *polish = *polish + *shift + 1;
    if (*op_stack == NULL)
        *op_stack = init(*op);
    else
        push(op_stack, *op);
}
