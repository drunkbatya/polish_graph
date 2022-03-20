// Copyright [2022] <griselle, laynadre>

#ifndef SRC_LIB_GRAPH_H_
#define SRC_LIB_GRAPH_H_

int make_me_free(char *str, int **matrix, char *polish, stack *op_stack, int return_code);
int **create_matrix(int size_x, int size_y);
void parse_symb(char *str);
int extract_num(char *str, int *num);
void feel_matrix(int **matrix, int size_x, int size_y, char *str);
int parse(char *input_str, char *polish, stack **op_stack);
float notation_result(char *str, float x);
float calc(float a, float b, char op);

#endif  // SRC_LIB_GRAPH_H_
