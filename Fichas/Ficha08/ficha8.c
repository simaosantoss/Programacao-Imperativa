#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/*--------------------------------------- Ficha 8 ----------------------------------------*/

typedef struct slist  {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs)  {
    LInt r = malloc (sizeof(struct slist));
        if (r!=NULL) {
            r->valor = x; r->prox = xs;
        }

    return r;
}


// Exercicio 1

typedef LInt Stack;

// a)
void initStack (Stack *s) {
    *s = NULL;
}

// b)
int SisEmpty (Stack s) {
    if (s == NULL)
        return 1;

    else 
        return 0;
}

// c)
int push (Stack *s, int x) {
    if (*s == NULL) {
        Stack novo = malloc(sizeof(struct slist));
        if (novo == NULL) return -1;
        novo->valor = x;
        novo->prox = NULL;
        *s = novo;
        return 0;
    }

    Stack novo = malloc(sizeof(struct slist));
    if (novo == NULL) return -1;
    novo->valor = x;
    novo->prox = *s;
    *s = novo;
    return 0;
}

// d)
int pop (Stack *s, int *x) {
    if (*s == NULL) 
        return -1;

    *x = (*s)->valor;
    Stack tmp = (*s);
    *s = (*s)->prox;
    free(tmp);

    return 0;
}

// e)
int top (Stack s, int *x) {
    if (s == NULL)
        return -1;

    *x = s->valor;

    return 0;
}

// Exercicio 2

typedef struct {
    LInt inicio,fim;
} Queue;

void initQueue (Queue *q) {
    q -> inicio = q -> fim = NULL;
}

int QisEmpty (Queue q) {
    if (q.inicio == NULL) return 1;

    else return 0;
}

int enqueue (Queue *q, int x) {
    LInt nova = newLInt (x, NULL);

    if (nova == NULL) return 1;

    if (q->fim != NULL) {
        q->fim = nova;
    }

    else
        q->inicio = q->fim = nova;

    return 0;
}

int dequeue (Queue *q, int *x) {
    LInt tmp;

    if (q->inicio == NULL) return 1;

    *x = q->inicio->valor;
    tmp = q->inicio;
    q->inicio = q->inicio->prox;

    if (q->inicio == NULL) 
        q->fim = NULL;

    free(tmp);

    return 0;
}

