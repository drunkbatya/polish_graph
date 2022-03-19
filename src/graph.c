// Copyright [2022] <griselle, laynadre>

#include <stdio.h>
#include <stdlib.h>
#include "lib_io.h"

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80

#define GRAPH_SYM "$"

int main(void) {
    char *str;

    if (!input(&str)) {
        printf("n/a");
        if (str != NULL)
            free(str);
        return (1);
    }
    printf("DBG: %s\n", str);
    free(str);
    return (0);
}