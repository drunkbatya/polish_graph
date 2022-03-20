// Copyright [2022] <griselle, laynadre>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_io.h"
#include "lib_stack.h"
#include "lib_graph.h"
#include "lib_parse.h"
#include "graph.h"

int main(void) {
    char *str;
    int **matrix;
    char *polish;
    stack *op_stack;

    matrix = NULL;
    op_stack = NULL;
    polish = NULL;
    if (!input(&str)) {
        printf("graph.c: input error!\n");
        return (make_me_free(str, matrix, polish, op_stack, 1));
    }
    matrix = create_matrix(SCREEN_HEIGHT, SCREEN_WIDTH);
    polish = calloc((strlen(str) + 1), sizeof(char));
    if (matrix == NULL || polish == NULL) {
        printf("graph.c: memmory allocation error!\n");
        return (make_me_free(str, matrix, polish, op_stack, 1));
    }
    if (!parse(str, polish, &op_stack)) {
        printf("graph.c: parse error!\n");
        return (make_me_free(str, matrix, polish, op_stack, 1));
    }

    printf("\nOUPUT %s\n", polish);

    printf("DBG: %s\n", str);
    feel_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH);
    print_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH);

    return (make_me_free(str, matrix, polish, op_stack, 0));
}
