#include <stdlib.h> // malloc, free, realloc
#include <string.h> 
#include <ctype.h>

// Exercicio 1

int isEven (int i) {
    if (i % 2 == 0)
        return 1;

    else
        return 0;
}

void swap (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int paresImpares (int v[], int N) {
    int inicio = 0;
    int fim = N - 1;
    int num_pares = 0;

    while (inicio < fim) {
        if (isEven (v[inicio]) == 1) {
            inicio++;
            num_pares++;
            }

        else if (isEven (v[fim]) == 0)
            fim--;

        else {
            swap (&v[inicio], &v[fim]);
            inicio++;
            fim--;
        }
    }

    if (inicio == fim && isEven(v[inicio]))
        num_pares++;

    return num_pares;
}

// Exercicio 2

typedef struct no {
    int valor;
    struct no *prox;
} *LInt;

void merge (LInt *r, LInt a, LInt b) {
    *r = NULL;
    LInt *atual = r;

    while (a != NULL && b != NULL) {
        if (a->valor <= b->valor) {
            *atual = a;
            a = a->prox;
        }

        else {
            *atual = b;
            b = b->prox;
        }

        atual = &((*atual)->prox);
    }

    if (a == NULL) {
        *atual = b;
        b = b->prox;
    }

    if (b == NULL) {
        *atual = a;
        a = a->prox;
    }
}

// Exercicio 3

void latino (int N, int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m [i][j] = ((i + j) % N) + 1;
        }
    }
}