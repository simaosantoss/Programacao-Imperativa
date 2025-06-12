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

// Exercicio 4

typedef struct nodo {
     int valor;
     struct nodo *pai, *esq, *dir;
} *ABin;

ABin maisEsquerda(ABin a) {
    if (a == NULL) 
        return NULL;

    while (a->esq != NULL) {
        a = a->esq;

    }
    return a;
}

ABin ancestralCorreto(ABin a) {
    if (a == NULL) 
        return NULL;

    ABin curr = a;

    while (curr->pai != NULL && curr == curr->pai->dir) {
        curr = curr->pai;
    }
    
    return curr->pai;
}

ABin next(ABin a) {
    if (a == NULL) return NULL;
    
    if (a->dir != NULL) {
        return maisEsquerda(a->dir);
    } 
    
    else {
        return ancestralCorreto(a); 
    }
}

// Exercicio 5

typedef struct palavras {
    char *palavra;
    int nOcorr;
    struct palavras *esq, *dir;
} *Palavras;

int acrescentaPal(Palavras *p, char *pal) {
    if (*p == NULL) {
        *p = malloc(sizeof(struct palavras));
        (*p)->palavra = strdup(pal);
        (*p)->nOcorr = 1;
        (*p)->esq = (*p)->dir = NULL;
        
        return 1;
    }

    int cmp = strcmp(pal, (*p)->palavra);

    if (cmp == 0) {
        (*p)->nOcorr++;
    }

    else if (cmp < 0) {
        int res = acrescentaPal(&((*p)->esq), pal);

        if ((*p)->esq != NULL && (*p)->esq->nOcorr > (*p)->nOcorr) {
            rodaDireita(p); 
        }

        return res;
    }

    else {
        int res = acrescentaPal(&((*p)->dir), pal);

        if ((*p)->dir != NULL && (*p)->dir->nOcorr > (*p)->nOcorr) {
            rodaEsquerda(p);  
        }

        return res;
    }

    return 1;
}