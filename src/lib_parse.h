// Copyright [2022] <griselle, laynadre>

#ifndef SRC_LIB_PARSE_H_
#define SRC_LIB_PARSE_H_

#include "lib_stack.h"

void add_to_polish(char *polish, char *input_str, int shift);
int priority(char op);
int extract_num(char *str, int *num);
int extract_op(char *str, char *op, int *shift);
void add_x_to_polish(char **input_str, char **polish);
void add_num_to_polish(char **input_str, char **polish, int *num, int *shift);
void add_op_to_polish(char **polish, int *shift, stack **op_stack, char *op);
void op_routing(char **polish, int *shift, stack **op_stack, char *op);
#endif  // SRC_LIB_PARSE_H_
