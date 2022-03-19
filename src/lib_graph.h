// Copyright [2022] <griselle, laynadre, ronnyfre>

#ifndef SRC_LIB_GRAPH_H_
#define SRC_LIB_GRAPH_H_

int **create_matrix(int size_x, int size_y);
int parse(char *input_str, char *polish);
void parse_symb(char *str);
int extract_num(char *str, int *num);
void feel_matrix(int **matrix, int size_x, int size_y);

#endif  // SRC_LIB_GRAPH_H_
