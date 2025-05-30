#include <stdio.h>

/*--------------------------------------- Ficha 7 ----------------------------------------*/

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;

// Exercicio 1
void libertaLista (Palavras l) {
    Palavras p;

    while (l != NULL) {
        p = l;
        l = l->prox;
        free(p->palavra);
        free(p);
    }
}

// Exercicio 2
int quantasP (Palavras l) {
    int conta = 0;

    for (; l != NULL ; l = l->prox)
        conta++;

    return conta;
}

// Exercicio 3
void listaPal (Palavras l) {
    for (; l != NULL ; l = l->prox)
        printf ("%s %d\n", l->palavra, l->ocorr);
}

// Exercicio 5
Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = malloc(strlen(p) + 1);
    strcpy(nova->palavra, p);
    nova -> ocorr = 1;
    nova -> prox = l;
    return nova;
}

// Exercicio 6
Palavras acrescentaFim (Palavras l, char *p) {
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = malloc(strlen(p) + 1);
    strcpy(nova->palavra, p);
    nova -> ocorr = 1;
    nova -> prox = NULL;

    while (l->prox != NULL)
        l = l->prox;
    l->prox = nova;

    return l;
}

// Exercicio 7
Palavras acrescenta (Palavras l, char *p) {
    Palavras pt = l;

    while (pt != NULL && strcmp(pt->palavra, p) != 0)
        pt = pt->prox;

    if (pt != NULL)
        pt ->ocorr++;

    else
        l = acrescentaInicio(l, p);

    return l;
}

// Exercicio 8
struct celula * maisFreq (Palavras l) {
    int max = 0;
    struct celula * r = NULL;
    
    while (l != NULL) {
        if (l->ocorr > max) {
            max = l->ocorr;
            r = l;
        }
        l = l->prox;
    }
}