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

    matrix = NULL;
    polish = NULL;

    /*  if (!input(&str)) {
        printf("graph.c: input error!\n");
        return (make_me_free(str, matrix, polish, op_stack, 1));
    } */
    matrix = create_matrix(SCREEN_HEIGHT, SCREEN_WIDTH);
    polish = calloc((strlen(str) + 1), sizeof(char));

    // MOCKS:
    str = "5+4*(x-1)\0";
    // polish = "5 4 x 1 - * +\0";
    polish = "x 8 / 1 8 / -\0";
    char *temp = polish;

    /*   if (matrix == NULL || polish == NULL) {
        printf("graph.c: memmory allocation error!\n");
        return (make_me_free(str, matrix, temp, op_stack, 1));
    }

    if (!parse(str, polish, &op_stack)) {
        printf("graph.c: parse error!\n");
        return (make_me_free(str, matrix, temp, op_stack, 1));
    }
*/
    printf("\nINPUT %s\n", str);
    printf("\nOUPUT %s\n", temp);
    // for (float x = 0; x < 80; x+=1.33) {
    //    printf("\n%.2lf\n", notation_result(temp, x));
    //}

    feel_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH, temp);
    print_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH);

    if (matrix != NULL)
        free(matrix);

    return 0;
}

