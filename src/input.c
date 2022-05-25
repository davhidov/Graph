#include "input.h"

char* input(char *str) {
    int k = 0;
    char c;
    do {
        c = getchar();
        str = (char*)realloc(str, (k + 1) * sizeof(char));
        str[k] = c;
        k++;
    } while (c != '\n');
    str[k] = '\0';
    check_sin(str, k);
    check_cos(str, k);
    check_ctg(str, k);
    check_tg(str, k);
    check_ln(str, k);
    check_sqrt(str, k);
    squeeze(str, ' ');
    return str;
}

void squeeze(char *s, char c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void check_sin(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 's') {
            if ((str[i + 1] == 'i') && (str[i + 2] == 'n')) {
                str[i+1] = ' ';
                str[i+2] = ' ';
            }
        }
    }
}

void check_cos(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 'c') {
            if ((str[i + 1] == 'o') && (str[i + 2] == 's')) {
                str[i+1] = ' ';
                str[i+2] = ' ';
            }
        }
    }
}

void check_tg(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 't') {
            if (str[i + 1] == 'g') {
                str[i+1] = ' ';
            }
        }
    }
}

void check_ctg(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 'c') {
            if ((str[i + 1] == 't') && (str[i + 2] == 'g')) {
                str[i] = 'g';
                str[i+1] = ' ';
                str[i+2] = ' ';
            }
        }
    }
}
void check_ln(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 'l') {
            if (str[i + 1] == 'n') {
                str[i+1] = ' ';
            }
        }
    }
}
void check_sqrt(char *str, int k) {
    for (int i = 0; i < k; i++) {
        if (str[i] == 's') {
            if ((str[i + 1] == 'q') && (str[i + 2] == 'r') && (str[i + 3] == 't')) {
                str[i] = 'q';
                str[i+1] = ' ';
                str[i+2] = ' ';
                str[i+3] = ' ';
            }
        }
    }
}


void draw(char* equation) {
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    int len_c = strlen(equation);
    PreobToUnarMinus(equation, len_c);
    char *polish = (char*)calloc(len_c*2, sizeof(char));
    ToPolish(equation, polish, stk, len_c);
    free(stk);
    free(equation);
    struct stack_double *stk_d;
    stk_d = (struct stack_double*)malloc(sizeof(struct stack_double));
    init_double(stk_d);
    int len = strlen(polish);
    printf("%s\n", polish);
    char graph[25][80];
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            graph[i][j] = '.';}
    }
    int p = 0;
    for (double x = 0.; x <= (4. + 1e-6) * M_PI; x += 4. * M_PI/79.) {
        double y = ToRezalt(stk_d, polish, &len, &x);
        int o = round((y) / (2./24) + 12);
        if (o <= 24 && o >= 0 && y <= 1 && y >= -1) {
            graph[o][p] = '*';
        }
        p++;}
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", graph[i][j]);}
        printf("\n");}
    free(stk_d);
    free(polish);
}

