#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>  
#include <ctype.h>     
#include <math.h>      

// Exercício 1

int fizzbuzz(int n) {
    int cont = -1;

    for (int i = 0; i < n; i++) {
        if (fizz(i) && buzz(i)) {
            cont = 0;
        }

        else if (cont >= 0) {
            if (buzz(i)) {
                return cont;
            }

            else {
                cont++;
            }
        }
    }

    return -1;
}

// Exercício 2

void rodaEsq(int a[], int N, int r) {
    int tmp[r];
    int i, j;

    for (i = 0; i < r; i++) {
        tmp[i] = a[i];
    }

    for (j = 0; j < N - r; j++) {
        a[j] = a[j + r];
    }

    for (int i = 0; i < r; i++)
    a[N - r + i] = tmp[i];
}

// Exercício 3

typedef struct lint_nodo { 
int valor; 
struct lint_nodo *prox; 
} *LInt;

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;

int delete(int n, LInt *l) {
    if (n < 0 || *l == NULL)                
        return -1;

    LInt curr = *l;                        
    if (n == 0) {                           
        *l = curr->prox;                   
        free(curr);
        return 0;
    }

    LInt prev = NULL;                       
    for (int i = 0; i < n && curr != NULL; i++) {
        prev = curr;
        curr = curr->prox;
    }

    if (curr == NULL)                       
        return -1;

    prev->prox = curr->prox;                
    free(curr);                             
    return 0;
}

// Exercício 4

int maxCresc(LInt l) {
    if (l == NULL) return 0;

    int maxLen  = 1;
    int currLen = 1;
    LInt curr;

    for (curr = l; curr->prox != NULL; curr = curr->prox) {

        if (curr->prox->valor > curr->valor) {
            currLen++;                // sequência continua

            if (currLen > maxLen)     
                maxLen = currLen;     // atualiza máximo

        } else {
            currLen = 1;              // sequência acabou, recomeça
        }
    }

    return maxLen;
}

// Exercício 5

typedef struct abin_nodo { 
int valor; 
struct abin_nodo *esq, *dir; 
} *ABin;

ABin folhaEsq (ABin a) {
    if (a == NULL)                   
        return NULL;

    if (a->esq == NULL && a->dir == NULL)
        return a;                   

    if (a->esq != NULL)             
        return folhaEsq(a->esq);

    return folhaEsq(a->dir);
}

// Exercicio 6

static int match (char open, char close)
{
    return  (open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}');
}

int parentesisOk (const char exp[])
{
    char st[strlen(exp)];
    int  sp = 0;                

    for (int i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            st[sp++] = exp[i];
        }

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (sp == 0)               
                return 0;

            if (!match(st[--sp], exp[i]))
                return 0;             
        }
    }

    return (sp == 0);
}

