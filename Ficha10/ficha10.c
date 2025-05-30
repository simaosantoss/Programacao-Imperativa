#include <stdio.h> 


/*--------------------------------------- Ficha 10 ---------------------------------------*/

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// Exercicio 1

// a)
ABin removeMenor (ABin *a) {
    ABin res = *a;

    if (*a != NULL) {

        while ((*a)->esq != NULL)
            a = &((*a)->esq);

        res = *a;
        *a = (*a)->dir;
    }

    return res;
}

// b)
void removeRaiz (ABin *a) {
    ABin menor = removeMenor (&((*a)->dir));

    ABin esq = (*a)->esq;
    ABin dir = (*a)->dir;
    free(*a);

    if (menor == NULL) {
        *a = esq;
    }
    
    else {
        *a = menor;
        (*a)->esq = esq;
        (*a)->dir = dir;
    }
}

// c)
int removeElem (ABin *a, int x) {
    int res = -1;
     if (*a != NULL) {
        if ((*a)->valor == x) {
            res = 0;
            removeRaiz(a);
        }
        else if (x > (*a)->valor) {
            res = removeElem(&((*a)->dir), x);
        }
        else {
            res = removeElem(&((*a)->esq), x);
        }
}