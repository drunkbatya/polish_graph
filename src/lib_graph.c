// Copyright [2022] <griselle, laynadre, ronnyfre>

#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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
    for (int i = 0; i < shift; i++) {
        *polish = *input_str;
        polish++;
        input_str++;
    }
    *polish = ' ';
}

int priority(char op) {
    if (op == '+' || op == '-') {
        return 0;
    }
    if (op == '*' || op == '/') {
        return 1;
    }
    if (op == 's' || op == 'c'
        || op == 't' || op == 'g' || op == 'l') {
        return 2;
    }
    if (op == 'q' || op == '^') {
        return 3;
    }
    if (op == '(' || op == ')') {
        return 4;
    }
    return 0;
}

/*
void add_to_stack(char op, char *polish, struct stack *root) {
   if (priority(op) > 1)
       printf("%c", *polish);
}
*/

int extract_num(char *str, int *num) {
    int shift = 0;

    while (*str != '\0') {
        // If next is num too
        if (*str >= '0' && *str <= '9') {
            *num = *num * 10 + (int)(*str - '0');
            str++;
            shift++;
        }
        if (*str < '0' || *str > '9') {
            break;
        }
    }
    printf("\nnum is %d", *num);
    *num = 0;
    return shift;
}

int extract_op(char *str, char *op, int *shift) {
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
    if (strchr("+-/*()", *str)) {
        *op = *str;
        return (1);
    }
    return (0);
}

int parse(char *input_str, char *polish) {
    int shift = 0;
    //  struct stack *op_stack = NULL;
    char op;
    int num = 0;

    // Check for unary minus at the beginning
    if (*input_str == '-') {
        *polish = '0';
        polish++;
        *polish = ' ';
        polish++;
        input_str++;
        // add to stack ( and -
    }
    while (*input_str != '\0') {
        printf("\n now num is %c", *input_str);
        // add X ------------------- TO DO
        if (*input_str == 'x') {
            shift = 1;
            add_to_polish(polish, input_str, shift);
            polish++;
            *polish = ' ';
            polish++;
            input_str++;
        } else if (*input_str >= '0' && *input_str <= '9') {
            shift = extract_num(input_str, &num);
            add_to_polish(polish, input_str, shift);
            polish = polish + shift + 1;  // + 1 - for the added space
            if (*(input_str + shift) == '\0') {
                return 1;
            }
            input_str = input_str + shift;
        } else {
            if (extract_op(input_str, &op, &shift) == 0) {
                return 0;
            }
            add_to_polish(polish, input_str, shift);
            polish = polish + shift + 1;
            if (*(input_str + shift) == '\0') {
                return 1;
            }
            input_str = input_str + shift;
            // check what to do

         //   if (op_stack == NULL) {
          //      op_stack = init(op);
         //   } else {
          //      push(&char_stack, op);
         //   }
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
