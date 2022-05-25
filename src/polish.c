#include "polish.h"

int push_simbol(struct stack *stk, char equation, char* polish, int j)  {
    if (stk->top == 0) {
        push(stk, equation);
        return j;}
        MinusPlus(stk, &equation, polish, &j);
        UmnDel(stk, &equation, polish, &j);
        UnarMinus(stk, &equation, polish, &j);
        Funks(stk, &equation, polish, &j);
        Stepen(stk, &equation, polish, &j);
    if (equation == '\n') {
        while (stk->top != 0) {
            polish[j] = pop(stk);
            if (polish[j] == '|') break;
            j++;}}
    if (equation == '(') {
        push(stk, equation);}
    if (equation == ')') {
        while (stk->elem[stk->top-1] != '(') {
            polish[j] = pop(stk);
            if (polish[j] == '|') break;
            j++;}
        pop(stk);}
     // printf("%d  |   %s\n", j, stk->elem);
    return j;
}

void ToPolish(char* equation, char* polish, struct stack* stk, int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (equation[i] == '/' || equation[i] == '^' || equation[i] == '*' || equation[i] == '-' ||
            equation[i] == '+' || equation[i] == '(' || equation[i] == ')' || equation[i] == '\n' ||
            equation[i] == '~' || equation[i] == 'l' || equation[i] == 's' || equation[i] == 'c' ||
            equation[i] == 't' || equation[i] == 'g' || equation[i] == 'q' || equation[i] == 'x') {
                if (equation[i] == 'x') {
                    polish[j] = equation[i];
                    j++;
                    continue;
                }
            j = push_simbol(stk, equation[i], polish, j);
        } else {
            polish[j] = equation[i];
            j++;
            if (equation[i+1] == '/' || equation[i+1] == '^' || equation[i+1] == '*' ||
                equation[i+1] == '-' || equation[i+1] == '+' || equation[i+1] == '(' ||
                equation[i+1] == ')' || equation[i+1] == '\n' || equation[i+1] == 'x') {
                polish[j] = '|';
                j++;
            }
        }
    }
    polish[j] = '\n';
}

void PreobToUnarMinus(char *equation, int len) {
    for (int i = 0; i < len; i++) {
        if (equation[0] == '-')
            equation[0] = '~';
        if (equation[i] == '(' && equation[i+1] == '-')
            equation[i+1] = '~';
    }
}
void MinusPlus(struct stack* stk, char *equation, char* polish, int* j) {
    if (*equation == '-' || *equation == '+') {
        while (stk->elem[stk->top-1] == '+' || stk->elem[stk->top-1] == '^' || stk->elem[stk->top-1] == '-' ||
               stk->elem[stk->top-1] == '*' || stk->elem[stk->top-1] == '/' || stk->elem[stk->top-1] == '~' ||
               stk->elem[stk->top-1] == 's' || stk->elem[stk->top-1] == 'c' || stk->elem[stk->top-1] == 't' ||
               stk->elem[stk->top-1] == 'g' || stk->elem[stk->top-1] == 'q' || stk->elem[stk->top-1] == 'l') {
            polish[*j] = pop(stk);
            (*j)++;
        }
         push(stk, *equation);
    }
}
void UmnDel(struct stack* stk, char *equation, char* polish, int* j) {
    if (*equation == '*' || *equation == '/') {
        while (stk->elem[stk->top-1] == '*' || stk->elem[stk->top-1] == '^' || stk->elem[stk->top-1] == '/' ||
               stk->elem[stk->top-1] == '~' || stk->elem[stk->top-1] == 's' || stk->elem[stk->top-1] == 'c' ||
               stk->elem[stk->top-1] == 't' || stk->elem[stk->top-1] == 'g' ||
               stk->elem[stk->top-1] == 'q' || stk->elem[stk->top-1] == 'l') {
            polish[*j] = pop(stk);
            (*j)++;
        }
        push(stk, *equation);
    }
}
void UnarMinus(struct stack* stk, char *equation, char* polish, int* j) {
    if (*equation == '~') {
        while (stk->elem[stk->top-1] == 's' || stk->elem[stk->top-1] == 'c' || stk->elem[stk->top-1] == 't' ||
               stk->elem[stk->top-1] == 'g' || stk->elem[stk->top-1] == 'q' || stk->elem[stk->top-1] == 'l' ||
               stk->elem[stk->top-1] == '~' || stk->elem[stk->top-1] == '^') {
            polish[*j] = pop(stk);
            (*j)++;
        }
        push(stk, *equation);
    }
}
void Funks(struct stack* stk, char *equation, char* polish, int* j) {
    if (*equation == 's' || *equation == 'c' || *equation == 't' ||
        *equation == 'g' || *equation == 'q' || *equation == 'l') {
        while (stk->elem[stk->top-1] == 's' || stk->elem[stk->top-1] == 'c' || stk->elem[stk->top-1] == 't' ||
               stk->elem[stk->top-1] == 'g' || stk->elem[stk->top-1] == 'q' || stk->elem[stk->top-1] == 'l') {
            polish[*j] = pop(stk);
            (*j)++;
        }
        push(stk, *equation);
    }
}
void Stepen(struct stack* stk, char *equation, char* polish, int* j) {
    if (*equation == '^') {
        while (stk->elem[stk->top-1] == 's' || stk->elem[stk->top-1] == 'c' || stk->elem[stk->top-1] == 't' ||
               stk->elem[stk->top-1] == 'g' || stk->elem[stk->top-1] == 'q' || stk->elem[stk->top-1] == 'l' ||
               stk->elem[stk->top-1] == '^') {
            polish[*j] = pop(stk);
            (*j)++;
        }
        push(stk, *equation);
    }
}
