#include <stdio.h> 


/*--------------------------------------- Ficha 9 ----------------------------------------*/

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;
ABin newABin (int r, ABin e, ABin d) {
ABin a = malloc (sizeof(struct nodo));
if (a!=NULL) {
a->valor = r; a->esq = e; a->dir = d;
}
return a;
}

// Exercicio 1

// a)
int altura (ABin a) {
    if (a == NULL) return 0;
    else return 1 + max(altura(a->esq) , altura(a->dir));
}

// b)
int nFolhas (ABin a) {
    if (a == NULL)
        return 0;

    else if (((a->esq) == NULL) &&
        ((a->dir) == NULL)) 
        return 1;

    else return (nFolhas(a->esq) + nFolhas(a->dir));
} 

// d)
void imprimeNivel (ABin a, int n) {
    if (a != NULL) {
        if (n == 0) printf ("%d", a->valor);

    else { imprimeNivel (a->esq , n-1);
           imprimeNivel (a->dir , n-1);

        }
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
int maiorFolha (ABin a) {
    int maior;

    if (((a->esq) == NULL) && 
       ((a->dir) == NULL)) 
       return (a->valor);

    else 
        if (a->esq == NULL)
            return (maiorFolha(a->dir));

        else if (a->dir == NULL)
            return (maiorFolha (a->esq));

        else return max(maiorFolha(a->esq) , maiorFolha (a->dir));

}

// extra (está nas 50 questões)
void freeABin (ABin a) {
    if (a != NULL) {
        freeABin(a->esq);
        freeABin(a->dir);
        free(a);
    }
}

// Exercicio 2

// f)
struct nodo *procura (ABin a, int x) {
    while (a != NULL && a->valor != x) {
        if (a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return (a != NULL);
}

// h)
void imprimeAte (ABin a, int x) {
    if (a != NULL) {

        if (a->valor == x)
            imprimeAte (a->esq, x);

        else if (a->valor > x)
            imprimeAte (a->esq, x);

        else {imprimeC (a->esq);          // imprimeC para ser mais eficiente
              printf ("%a " , a->valor);
              imprimeAte (a->dir, x);
        }
    }
}

void imprimeC (ABin a) {
    if (a != NULL) {
        imprimeC (a->esq);
        printf ("%d", a->valor);
        imprimeC (a->dir);
    }
}

// extra (quantos elementos de uma árvore (de procura) são iguais a x)
int quantos (ABin a, int e) {
    if (a == NULL) return 0;

    if (a->valor == e) return 1 + quantos(a->esq, e) + quantos(a->dir, e);

    else if (a->valor > e) return quantos(a->esq, e);

    else return quantos(a->dir, e);
}