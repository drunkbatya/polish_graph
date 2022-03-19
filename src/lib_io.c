// Copyright [2022] <griselle, laynadre, ronnyfre>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_io.h"
#include "graph.h"

//  function recives pointer address!
//  And requres memmory cleanup after return.

int input(char **ptr) {
    int size;

    size = 0;
    *ptr = malloc(sizeof(char));
    if (*ptr == NULL)
        return (0);
    while (1) {
        int c;

        c = getchar();
        if (c == '\n' || c == EOF) {
            if (size) {
                *(*ptr + size) = '\0';
                return (1);
            }
            return (0);
        }
        if (c < '0' || c > '9') {
            if (strchr(ALLOWED_SYMBOLS, c) == NULL)
                return (0);
        }
        *(*ptr + size) = c;
        *ptr = realloc(*ptr, (size + 2) * sizeof(char));
        if (*ptr == NULL)
            return (0);
        size++;
    }
}

void print_matrix(int **arr, int x, int y) {
    int count_x;

    count_x = 0;
    while (count_x < x) {
        int count_y;

        count_y = 0;
        while (count_y < y) {
            if (arr[count_x][count_y])
                printf("%c", GRAPH_SYM);
            else
                printf("%c", EMPTY_SYM);
            if (count_y == y - 1)
                printf("\n");
            count_y++;
        }
        count_x++;
    }
}
