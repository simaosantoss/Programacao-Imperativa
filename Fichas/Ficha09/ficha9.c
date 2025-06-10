#include <stdio.h> 


/*--------------------------------------- Ficha 9 ----------------------------------------*/

typedef struct nodo 
{
int valor;
struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) 
{
ABin a = malloc (sizeof(struct nodo));
        if (a!=NULL) 
        {
            a->valor = r; a->esq = e; a->dir = d;
        }
return a;
}

// Exercicio 1

// a)
int max (int a, int b)
{
    return (a > b) ? a : b;
}

int altura (ABin a)
{
    if (a == NULL)
        return 0;

    else
        return 1 + max(altura(a->esq), altura(a->dir));
}

// b)
int nFolhas (ABin a)
{
    if (a == NULL)
        return 0;

    if (a->esq == NULL && a->dir == NULL)
        return 1;

    return nFolhas(a->esq) + nFolhas(a->dir);
}

// c)
ABin maisEsquerda (ABin a)
{
    if (a == NULL)
        return NULL;

    while (a->esq != NULL)
        a = a->esq;

    return a;
}

// d)
void imprimeNivel (ABin a, int l)
{
    if (a == NULL)  // Se a árvore for vazia, return
        return;

    if (l == 0)
        printf("%d ", a->valor);
        
    else
    {
        imprimeNivel (a->esq, l - 1);
        imprimeNivel (a->dir, l - 1);
    }
}

// e) 
int procuraE (ABin a, int e) {
    if (a == NULL) return 0;
    
    if (a->valor == e) return 1;

    if (procuraE (a->esq, e)) return 1;

    if (procuraE (a->dir, e)) return 1;

    return 0;
}

// extra
int maiorFolha (ABin a)
{
    // Assume que a != NULL (árvore não vazia)
    if (a->esq == NULL && a->dir == NULL)
        return a->valor;  // é folha
    else if (a->esq == NULL)
        return maiorFolha(a->dir);  // só tem subárvore direita
    else if (a->dir == NULL)
        return maiorFolha(a->esq);  // só tem subárvore esquerda
    else
        return max(maiorFolha(a->esq), maiorFolha(a->dir));  // tem ambas
}

// extra (está nas 50 questões)
void freeABin (ABin a) 
{
    if (a != NULL)
    {
        freeABin(a->esq);
        freeABin(a->dir);
        free(a);
    }
}

// Exercicio 2

// f)
struct nodo *procura (ABin a, int x)
{
    if (a == NULL)
        return NULL;

    if (a->valor == x)
        return a;

    if (a->valor > x)
        return procura (a->esq, x);

    if (a->valor < x)
        return procura (a->dir, x);

    return NULL;
}

// g)
int nivel (ABin a, int x)
{
    if (a == NULL)
        return -1; // a é vazia

    if (a->valor == x)
        return 0; // o valor está no nivel 0

    if (a->valor > x)
    {
        int resultado = nivel (a->esq, x);
        if (resultado == -1)
            return -1;
        else
            return 1 + resultado;
    }

    if (a->valor < x)
    {
        int resultado = nivel (a->dir, x);
        if (resultado == -1)
            return -1;
        else
            return 1 + resultado;
    }

    return -1;
}

// h)
void imprimeAte (ABin a, int x) 
{
    if (a == NULL)
        return;


    if (a->valor == x)
        imprimeAte (a->esq, x);

    else if (a->valor > x)
        imprimeAte (a->esq, x);

    else
    {
        imprimeAte (a->esq, x);
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    }
}

// extra (quantos elementos de uma árvore (de procura) são iguais a x)
int quantos (ABin a, int e) 
{
    if (a == NULL) return 0;

    if (a->valor == e) return 1 + quantos(a->esq, e) + quantos(a->dir, e);

    else if (a->valor > e) return quantos(a->esq, e);

    else return quantos(a->dir, e);
}