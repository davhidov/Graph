#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#include "polish_to_rez.h"


int test_str(const char* equation);


char *input(char *str);
void check_sin(char *str, int k);
void check_cos(char *str, int k);
void check_tg(char *str, int k);
void check_ctg(char *str, int k);
void check_ln(char *str, int k);
void check_sqrt(char *str, int k);
void squeeze(char *str, char c);
void draw(char* equation);

#endif  // SRC_INPUT_H_
