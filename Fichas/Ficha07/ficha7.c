#include <stdio.h>

/*--------------------------------------- Ficha 7 ----------------------------------------*/

typedef struct celula
{
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

// Exercicio 1
void libertaLista (Palavras l)
{
    Palavras p;

    while (l != NULL)
    {
        p = l->prox;
        free(l->palavra);
        free(l);
        l = p;
    } 
}

// Exercicio 2
int quantasP (Palavras l)
{
    int conta = 0;

    while (l != NULL)
    {
        conta++;
        l = l->prox;
    }

    return conta;
}

// Exercicio 3
void listaPal (Palavras l)
{
    while (l != NULL)
    {
        printf("%s, %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// Exercicio 4
char * ultima (Palavras l) 
{
    if (l == NULL)
        return NULL;

    while (l->prox != NULL)
        l = l->prox;
        
    return l->palavra;
}

// Exercicio 5
Palavras acrescentaInicio (Palavras l, char *p) 
{
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = malloc(strlen(p) + 1);
    strcpy(novo->palavra, p);
    novo->ocorr = 1;
    novo->prox = l;

    return novo;
}


// Exercicio 6
Palavras acrescentaFim (Palavras l, char *p)
{
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = malloc(strlen(p) + 1);
    strcpy(novo->palavra, p);
    novo->ocorr = 1;
    novo->prox = l;

    while (l->prox != NULL)
        l = l->prox;

    l->prox = novo;

    return l;
}

// Exercicio 7
Palavras acrescenta (Palavras l, char *p) 
{    
    Palavras pt = l;

    while (pt != NULL)
    {
        if (strcmp(pt->palavra, p) == 0)
            {
            pt->ocorr++;
            return l;
            }

        pt = pt->prox;
    }
 
    l = acrescentaInicio(l, p);

    return l;
}

// Exercicio 8
struct celula * maisFreq (Palavras l) 
{
    int max = -1;
    struct celula *maisF = NULL;

    while (l != NULL)
    {
        if (l->ocorr > max)
        {
            max = l->ocorr;
            maisF = l;
        }
        l = l->prox;
    }

    return maisF;
}
