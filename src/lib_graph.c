// Copyright [2022] <griselle, laynadre>

#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"
#include "lib_parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int make_me_free(char *str, int **matrix, char *polish, stack *op_stack, int return_code) {
    if (str != NULL)
        free(str);
    if (matrix != NULL)
        free(matrix);
    if (polish != NULL)
        free(polish);
    destroy(&op_stack);
    return (return_code);
}

int **create_matrix(int size_x, int size_y) {
    int **arr;
    int *ptr;

    arr = calloc(1, (size_x * size_y * sizeof(int) + size_x * sizeof(int *)));
    if (arr == NULL)
        return (arr);
    ptr = (int *) (arr + size_x);
    for (int count = 0; count < size_x; count++)
        *(arr + count) = ptr + size_y * count;
    return (arr);
}

float convert_x_to_unreal(int x) {
    return (x * ((4 * M_PI) / (SCREEN_WIDTH - 1)));
}

int convert_y_to_real(float y) {
    return (round(y * ((SCREEN_HEIGHT - 1) / 2) / 1) + (SCREEN_HEIGHT / 2));
}

void feel_matrix(int **matrix, int size_x, int size_y, char *str) {
    int count_y;

    count_y = 0;
    while (count_y < size_y) {
        int x;

        x = convert_y_to_real(notation_result(str, convert_x_to_unreal(count_y)));
        if (x < size_x && x >= 0)
            matrix[x][count_y] = 1;
        count_y++;
    }
}

int parse(char *input_str, char *polish, stack **op_stack) {
    char *temp_polish;
    int shift = 0;
    char op;
    int num = 0;

    temp_polish = polish;
    if (!input_str || *input_str == '\0')
        return (0);
    while (*input_str != '\0') {
        if (*input_str == 'x') {
            add_x_to_polish(&input_str, &polish, &shift);
            continue;
        }
        if (*input_str >= '0' && *input_str <= '9') {
            add_num_to_polish(&input_str, &polish, &num, &shift);
            if (*(input_str + shift) == '\0')
                break;
            input_str = input_str + shift;
            continue;
        }
        if (extract_op(input_str, &op, &shift) == 0)
            return (0);
        // add_op_to_polish(&polish, &shift, op_stack, &op);
        if (!op_routing(&polish, &shift, op_stack, op))
            return (0);
        if (*(input_str + shift) != '\0')
            input_str = input_str + shift;
        else
            break;
    }
    if (*op_stack != NULL) {
        display_stack(*op_stack);
    }
    while (*op_stack)
        add_op_to_polish(&polish, &shift, pop(op_stack));
    return (1);
}

float notation_result(char *str, float x) {
    int num = 0;
    int shift = 0;
    float y = 0;
    float a = 0;
    float b = 0;

    n_stack *num_stack;
    num_stack = NULL;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {  // Numbers
            shift = extract_num(str, &num);
//            printf("\n num is %d", num);

            if (num_stack == NULL) {
                num_stack = n_init(num);
            } else {
                n_push(&num_stack, num);
            }

            num = 0;
            str = str + shift;
        } else if (*str == ' ') {  // Space
            str++;
            continue;
        } else if (*str == 'x') {  // X
            if (num_stack == NULL) {
                num_stack = n_init(x);
            } else {
                n_push(&num_stack, x);
            }
            str++;
        } else {  // Binary operators
            if (strchr("^+-/*", *str)) {
                b = n_pop(&num_stack);
                a = n_pop(&num_stack);
                n_push(&num_stack, calc(a, b, *str));
            }
            if (strchr("scltgq", *str)) {
                a = n_pop(&num_stack);
                n_push(&num_stack, unary_calc(a, *str));
            }

            str++;
        }
    }
 //   printf("\n stack: ");
 //   if (num_stack != NULL) {
 //       n_display_stack(num_stack);
 //   }
    y = n_pop(&num_stack); 
    n_destroy(&num_stack);
    return y;
}

float calc(float a, float b, char op) {
    if (op == '-')
        return (a - b);
    if (op == '+')
        return (a + b);
    if (op == '*')
        return (a * b);
    if (op == '/')
        return (a / b);
    if (op == '^')
        return (pow(a, b));
    return (0);
}

float unary_calc(float a, char op) {
    if (op == 's')
        return (sin(a));
    if (op == 'c')
        return (cos(a));
    if (op == 't')
        return (tan(a));
    if (op == 'g')
        return (1/tan(a));
    if (op == 'l')
        return (log(a));
    if (op == 'q')
        return (sqrt(a));
    return (0);
}





























