// Copyright [2022] <griselle, laynadre, ronnyfre>

#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

void add_to_polish(char *polish, char *input_str, int shift) {
    while (shift != 0) {
        *polish = *input_str;
        polish++;
        input_str++;
        shift--;
    }
}

void extract_num(char *str, int *num, int *shift) {
    *num = (int)(*str - '0');
    str++;
    *shift = 1;

    while (*str != '\0') {
        // If next is num too
        if (*str >= '0' && *str <= '9') {
            *num = *num * 10 + (int)(*str - '0');
        }
        str++;
        *shift++;
        if (*str >= '0' && *str <= '9') {
            break;
        }
    }
    printf("\nnum is %d", *num);
}

int parse(char *input_str, char *polish) {
    int shift = 0;
    struct char_stack *op_stack = NULL;
    int num = 0;
    if
    while (*input_str != '\0') {
        if (*input_str >= '0' && *input_str <= '9') {
            extract_num(input_str, &num, &shift);
            add_to_polish(polish, input_str, shift);
            polish = polish + shift;
            input_str = input_str + shift;
        } else {
            // 1. получаем следующий символ из входной строки
            // 2. проверяем, что это:
            // +, -, 
            shift = extract_op(char *str, char *op);
            if (op_stack == NULL) {
                op_stack = char_init(op);
            } else {
                char_push(&char_stack, op);
            }
            input_str = input_str + shift;
            polish++;
        }
    }
    return 1;
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
