#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

// Exercicio 1

typedef struct {
    int inf,sup;
} Intervalo;

void swap (Intervalo *a, Intervalo *b) {
    Intervalo tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (Intervalo c[], int low, int high) {
    int pivot = c[(low + high) / 2].inf;

    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {i++;} while (c[i].inf < pivot);
        do {j--;} while (c[j].inf > pivot);

        if (i >= j) return j;

        swap (&c[i], &c[j]);
    }
}

void quickSort (Intervalo c[], int low, int high) {
    if (low < high) {
        int p = partition (c, low, high);
        quickSort (c, low, p);
        quickSort (c, p + 1, high);
    }
}

void ordena (Intervalo c[], int N) {
    quickSort (c, 0, N-1);
}

/*
se se puder usar qsort da biblioteca (não sei se pode) poderia ser feito assim:asinhf

int compare(const void *a, const void *b) {
    Intervalo *intervalA = (Intervalo *)a;
    Intervalo *intervalB = (Intervalo *)b;
    
    return intervalA->inf - intervalB->inf;
}

void ordena(Intervalo c[], int N) {
    qsort(c, N, sizeof(Intervalo), compare);
}

mais simples, rápido e menos probabilidade de errar
*/

// Exercicio 2

int cardinalidade(Intervalo c[], int N) {
    int cont = 0;
    
    // Conta todos os intervalos
    for (int i = 0; i < N; i++) {
        cont += c[i].sup - c[i].inf + 1;
    }
    
    // Subtrai sobreposições
    for (int i = 0; i < N-1; i++) {
        if (c[i].sup >= c[i+1].inf) {
            // Subtrai a sobreposição
            cont -= (min(c[i].sup, c[i+1].sup) - max(c[i].inf, c[i+1].inf)) + 1;
        }
    }
    
    return cont;
}

// Exercicio 3

void camel2snake(char *id) {
    int len = strlen(id);
    int j = 0, num_maiusculas = 0;

    for (int i = 0; i < len; i++)
        if (isupper (id[i])) num_maiusculas += 1;

    char snake[len + num_maiusculas];
    
    for (int i = 0; i < len; i++) {
        if (islower (id[i])) {
            snake[j] = id[i];
            j++;
        }

        else if (isupper (id[i])) {
            snake[j] = '_';
            snake[j + 1] = tolower (id[i]);
            j += 2;
        }

        else {
            snake[j] = id[i];  // copia outros caracteres que não são letras
            j++;
        }
    }

    snake[j] = '\0';
    strcpy (id, snake);
}

// Exercicio 4

typedef struct no {
    int valor;
    struct no *prox;
} *LInt;

LInt arrayToList (int v[], int N) {
    LInt head = NULL;
    LInt tail = NULL;
    
    for (int i = 0; i < N; i++) {
        LInt novo = malloc(sizeof(struct no));
        novo->valor = v[i];
        novo->prox = NULL;

        if (head == NULL) {
            head = novo;
            tail = novo;
        }

        else { 
            tail->prox = novo;
            tail = novo;
        }
    }

    return head;
}

// Exercicio 5

int apagaUltimo(LInt *l, int x) {
    LInt prev = NULL;
    LInt atual = *l;
    LInt ultimoX = NULL;
    LInt anterior_ultimoX = NULL;

    // Encontra última ocorrência
    while (atual != NULL) {
        if (atual->valor == x) {
            ultimoX = atual;
            anterior_ultimoX = prev;
        }

        prev = atual;
        atual = atual->prox;
    }

    if (ultimoX == NULL) {
        return 1;                               // Elemento não encontrado
    }

    if (anterior_ultimoX == NULL) {
        *l = ultimoX->prox;                     // Remove primeiro elemento
    } 
    
    else {
        anterior_ultimoX->prox = ultimoX->prox;  // Caso geral
    }

    free(ultimoX);
    return 0;
}

// Exercicio 6

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int nivel (ABin a, int x) {

    if (a->valor == x) 
        return 0;

    if (a->valor > x)
        return 1 + nivel (a->esq, x);

    else
        return 1 + nivel (a->dir, x);       
}

int ancestralComum (ABin a, int x, int y) {
    if (x < a->valor && y < a->valor)
        return ancestralComum(a->esq, x, y);

    if (x > a->valor && y > a->valor)
        return ancestralComum(a->dir, x, y);

    else
        return a->valor;
}

int parentesco(ABin a, int x, int y) {
    
    if (a == NULL)
        return -1;

    int lca = ancestralComum (a, x, y);

    return (nivel (a, x)) + (nivel (a, y)) - (2 * (nivel (a, lca)));
}