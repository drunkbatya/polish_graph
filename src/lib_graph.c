// Copyright [2022] <griselle, laynadre>

#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"
#include "lib_parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float dummy(float x) {
    // return (pow(x, 2));
    return (sin(cos(2 * x)));
}

float convert_x_to_unreal(int x) {
    return (x * ((4 * M_PI) / (SCREEN_WIDTH - 1)));
}

int convert_y_to_real(float y) {
    return (round(y * ((SCREEN_HEIGHT - 1) / 2) / 1) + (SCREEN_HEIGHT / 2));
}

void feel_matrix(int **matrix, int size_x, int size_y) {
    int count_y;

    count_y = 0;
    while (count_y < size_y) {
        int x;

        // x is y, y is x, cake is a lie, sorry for this..
        x = convert_y_to_real(dummy(convert_x_to_unreal(count_y)));
        if (x < size_x && x >= 0)
            matrix[x][count_y] = 1;
        count_y++;
    }
}

int parse(char *input_str, char *polish, stack **op_stack) {
    int shift = 0;
    char op;
    int num = 0;

    if (!input_str || *input_str == '\0')
        return (0);
    while (*input_str != '\0') {
        printf("\n now symb is %c", *input_str);
        if (*input_str == 'x') {
            add_x_to_polish(&input_str, &polish);
            continue;
        }
        if (*input_str >= '0' && *input_str <= '9') {
            add_num_to_polish(&input_str, &polish, &num, &shift);
            if (*(input_str + shift) == '\0') {
                break;
            }
            input_str = input_str + shift;
            continue;
        }
        if (extract_op(input_str, &op, &shift) == 0)
            return (0);
        add_op_to_polish(&polish, &shift, op_stack, &op);
        if (*(input_str + shift))
            input_str = input_str + shift;
        else
            break;
    }
    printf("\n stack: ");
    if (*op_stack != NULL) {
        display_stack(*op_stack);
    }
    return (1);
}
