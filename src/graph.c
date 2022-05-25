
#include "input.h"

int main() {
    int er;
    char *equation = NULL;
    equation = input(equation);
    er = test_str(equation);
    if (er == 1) {
        printf("Incorrect input. Try again.");
        free(equation);
    } else {
        draw(equation);
    }
    return 0;
}

int test_str(const char* equation) {
    int er = 0;
    int i = 0;
    while (equation[i] != '\n') {
        if (equation[i] == '/' || equation[i] == '^' || equation[i] == '*' || equation[i] == '-' ||
            equation[i] == '+' || equation[i] == '(' || equation[i] == ')' || equation[i] == '0' ||
            equation[i] == '~' || equation[i] == 'l' || equation[i] == 's' || equation[i] == 'c' ||
            equation[i] == 't' || equation[i] == 'g' || equation[i] == 'q' || equation[i] == 'x' ||
            equation[i] == '1' || equation[i] == '2' || equation[i] == '3' || equation[i] == '4' ||
            equation[i] == '5' || equation[i] == '6' || equation[i] == '7' || equation[i] == '8' ||
            equation[i] == '9') {
                er = 0;
            } else {
                er = 1;
            }
        i++;}
    i = 0;
    while (equation[i] != '\n') {
        if ((equation[i] == 'l' || equation[i] == 's' || equation[i] == 'c' ||
            equation[i] == 't' || equation[i] == 'g' || equation[i] == 'q')) {
               if (equation[i+1] == '(') {
               } else {
                   er = 1;}}
        i++;}
    i = 0;
    while (equation[i] != '\n') {
        if ((equation[i] == '/' || equation[i] == '^' || equation[i] == '*' || equation[i] == '-' ||
            equation[i] == '+')) {
               if (equation[i+1] == '/' || equation[i+1] == '^' || equation[i+1] == '*' ||
                   equation[i+1] == '-' || equation[i+1] == '+') {
                       er = 1;
               }
        }i++;
    }
    return er;
}
