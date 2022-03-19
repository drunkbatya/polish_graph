// Copyright [2022] <griselle, laynadre, ronnyfre>

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

float dummy(float x) {
    return (pow(x, 2));
}

float convert_x_to_unreal(int x) {
    return (x * ((4 * M_PI) / (SCREEN_WIDTH - 1)));
}

int convert_y_to_real(float y) {
    return (y * ((SCREEN_HEIGHT - 1) / 2) / 1);
}

void feel_matrix(int **matrix, int size_x, int size_y) {
    int count_y;

    count_y = 0;
    size_x = 0;
    while (count_y < size_y) {
        int x;

        // x is y, y is x, cake is a lie, sorry for this..
        x = convert_y_to_real(dummy(convert_x_to_unreal(count_y)));
        if (x < SCREEN_HEIGHT && x >= 0)
            matrix[x][count_y] = 1;
        count_y++;
    }
}
