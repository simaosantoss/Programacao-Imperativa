#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/*--------------------------------------- Ficha 5 ----------------------------------------*/

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

// Exercicio 1

int nota (Aluno a)
{
    int i, r = 0;
    float media;
    int miniTestes = 0;

    for (i = 0; i < 6; i++)
        miniTestes += a.miniT[i];  

    float mediaMini = (miniTestes / 6.0) * 2;

    if (mediaMini >= 1.0)
    {
        media = (0.2 * mediaMini) + (0.8 * a.teste);
        if (media >= 9.5) r = (int) (media + 0.5);
    }

    return r;
}

// Exercicio 2

// o array deve estar ordenado 

int procuraNum (int num, Aluno t[], int N) {
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = (high + low) / 2;

        if (t[mid].numero == num)
            return mid;

        else if (t[mid].numero < num)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// Exercicio 3

void swap (Aluno *a, Aluno *b) {
    Aluno tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordenaPorNum (Aluno t[], int N) {
    int i, j;

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (t[j].numero > t[j+1].numero) 
                swap (&t[j], &t[j+1]);
        }
    }
}

// Exercicio 4

void swapIndices (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void criaIndPorNum (Aluno t[], int N, int ind[])  {
    int j = 0; 
    // preencher o array com os indices 1, 2, 3, ..., N-1
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }

    // ordenar indices com buble sort
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++)
            if (t[ind[j]].numero > t[ind[j + 1]].numero)
                swapIndices(&ind[j], &ind[j + 1]);

}

// Exercicio 5

void imprimeTurma (int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        int idx = ind[i]; // índice real do aluno em t[]
        printf("%d - %s - %d\n", t[idx].numero, t[idx].nome, nota(t[idx]));
    }
}
