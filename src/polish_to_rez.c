#include "polish_to_rez.h"
#include <math.h>

double ToRezalt(struct stack_double* stk, char* polish, const int *len, double *x) {
    double rez = 0;
    int j = 0;
    double a;
    double b;
     char num[10];
    for (int i = 0; i < *len; i++) {
         if (polish[i] == '/' || polish[i] == '^' || polish[i] == '*' || polish[i] == '-' ||
            polish[i] == '+' || polish[i] == '\n' ||
            polish[i] == '~' || polish[i] == 'l' || polish[i] == 's' || polish[i] == 'c' ||
            polish[i] == 't' || polish[i] == 'g' || polish[i] == 'q' || polish[i] == 'x') {
                switch (polish[i]) {
                    case '-': minus(stk, &a, &b); break;
                    case '*':umn(stk, &a, &b); break;
                    case '+': plus(stk, &a, &b); break;
                    case '/':del(stk, &a, &b); break;
                    case '^':pow_s(stk, &a, &b); break;

                    case 's': sin_s(stk, &a); break;
                    case 'c':cos_s(stk, &a); break;
                    case 't': tan_s(stk, &a); break;
                    case 'g':ctg_s(stk, &a); break;
                    case 'q': sqrt_s(stk, &a); break;
                    case 'l':ln_s(stk, &a); break;
                    case '~': un_min(stk, &a); break;

                    case 'x': push_double(stk, *x); break;
                    case '\n':
                    rez = pop_double(stk);
                    break;
                    default:
                    break;
                }
         } else {
            ToDouble(stk, polish[i], num, &j);
         }
    }
    return rez;
}


void ToDouble(struct stack_double* stk, char polish, char *num, int *j) {
    if (polish == '|') {
        push_double(stk, atof(num));
        int len_num = strlen(num);
        *j = 0;
        memset(num, '\0', len_num);
    } else {
        num[*j] = polish;
        (*j)++;
    }
}

void minus(struct stack_double* stk, double *a, double *b) {
    *a = pop_double(stk);
    *b = pop_double(stk);
    push_double(stk, (*b-*a));
}

void plus(struct stack_double* stk, double *a, double *b) {
    *a = pop_double(stk);
    *b = pop_double(stk);
    push_double(stk, (*b+*a));
}
void umn(struct stack_double* stk, double *a, double *b) {
    *a = pop_double(stk);
    *b = pop_double(stk);
    push_double(stk, ((*b)*(*a)));
}
void del(struct stack_double* stk, double *a, double *b) {
    *a = pop_double(stk);
    *b = pop_double(stk);
    push_double(stk, ((*b)/(*a)));
}
void pow_s(struct stack_double* stk, double *a, double *b) {
    *a = pop_double(stk);
    *b = pop_double(stk);
    push_double(stk, pow(*b, *a));
}


void sin_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, sin(*a));
}
void cos_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, cos(*a));
}
void tan_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, tan(*a));
}
void ctg_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, 1/(tan(*a)));
}
void sqrt_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, sqrt(*a));
}
void ln_s(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, log(*a));
}
void un_min(struct stack_double* stk, double *a) {
    *a = pop_double(stk);
    push_double(stk, (-1)*(*a));
}
