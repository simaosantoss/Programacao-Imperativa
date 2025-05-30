#include <stdio.h> 


/*--------------------------------------- Ficha 5 ----------------------------------------*/

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

// Exercicio 1

int nota (Aluno a) {
    int i , r = 0;
    float f;
    int miniTestes = 0;

    for (i = 0 ; i < 6 ; i++)
        miniTestes += a.miniT[i];
    miniTestes *= 2;

    if (miniTestes >= 5) {
        f = a.teste * 0.8 + miniTestes * 0.2;
        if (f >= 9.5) r = (f + 0.5);
    }

    return r;    
}

// Exercicio 2

// o array deve estar ordenado 

int procuraNum (int num, Aluno t[], int N) {
    int i = 0 , s = N-1 , m , r = -1;

    while (i<=s && r == -1) {
        m = i + (s-1)/2;
        if (num = t[m].numero) r = m;
        else if (num < t[m].numero) s = m-1;
        else i = m+1;
    }

    return r;
}

// Exercicio 3

void swapT (Aluno t[] , int i , int j) {
    Aluno aux = t[i];
    t[i] = t[j];
    t[j] = aux;
}

void ordenaPorNum (Aluno t [], int N) {
    int i , j;

    for (i = 0 ; i < N ; i++) {
        for (j = i+1 ; j < N - i - 1; j++) {
            if (t[j].numero > t[j+1].numero)
                swap (t , t[j] , t[j+1]);
        } 
    }
}