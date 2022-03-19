// Copyright [2022] <griselle, laynadre, ronnyfre>

#include <stdio.h>
#include <stdlib.h>
#include "lib_io.h"
#include "lib_stack.h"
#include "lib_graph.h"
#include "graph.h"

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
