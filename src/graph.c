// Copyright [2022] <griselle, laynadre, ronnyfre>

#include <stdio.h>
#include <stdlib.h>
#include "lib_io.h"
#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"

int main(void) {
    char *str;
    int **matrix;
    char *polish = calloc(100, sizeof(char));

    if (!input(&str)) {
        printf("n/a");
        if (str != NULL)
            free(str);
        return (1);
    }

    // String for the output sequence

    if (parse(str, polish) == 0) {
        printf("ERROR FORMULA");
        return 0;
    }

    printf("\nOUPUT %s\n", polish);
    matrix = create_matrix(SCREEN_HEIGHT, SCREEN_WIDTH);
    if (matrix == NULL) {
        printf("n/a");
        if (str != NULL)
            free(str);
        return (1);
    }

    printf("DBG: %s\n", str);
    feel_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH);
    print_matrix(matrix, SCREEN_HEIGHT, SCREEN_WIDTH);

    free(polish);
    free(matrix);
    free(str);
    return (0);
}
