#include <stdio.h>
#include <stdlib.h>
#include "lib_io.h"
#include "stack.h"

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
    free(str);
    return (0);
}
