#include <stdio.h>

/*--------------------------------------- Ficha 3 ----------------------------------------*/

// Exercicio 2

void swapM (int *a , int *b) {
    int c ;
    c = *a ;
    *a = *b ;
    *b = c ;
}

// Exercicio 3

void swap (int v[] , int i , int j) {
    int t = v[i] ;
    v[i] = v [j] ;
    v[j] = t ; 
}

// Exercicio 4

int soma (int v[], int N) {
    int sum = 0 ;
    for(int i = 0; i < N; i++) {
        sum += v[i] ;
    }
    return sum ;
}

// Exercicio 5 

void inverteArray (int a[] , int n) {
    int i;
    for (i = 0 ; i < n/2 ; i++)
        swap (a , i , n - i - 1) ;
}

/*
versão com menos calculos

void inverteArray (int a[] , int n) {
    int i , j;
    for (i = 0 ; j = n - 1 ; i < j ; i++ ; j--)
        swap (a , i , j) ;
}
*/

// Exercicio 6

int maximum (int v[], int n, int *m) {
    if (n < 1) return 1 ;
    else {
        *m = v[0] ;
        for (int i = 0 ; i < n ; i++) {
            if (v[i] > *m) {
                *m = v[i] ;
            }
        }
        return 0 ;
    }
}

// Exercicio 7

void quadrados (int q[] , int n) {
    int i , delta ; 
    q[0] = 0 ; delta = 1 ;
    for (i = 1 ; i < n ; i++)
        q[i] = q [i-1] + delta ;
        delta = delta + 2 ;
}


/*
resolucao alternativa - mais simples

void quadrados (int q[], int n) {
    int i; 
    for (i = 0 ; i < n ; i++)
    q[i] = i * i ;
}
*/

// Exercicio 8

// a)

void pascal (int v[] , int n) {
    int i , j ; 
    v[0] = 1 ;
    for (i = 1 ; i <= n ; i++) {
        v[i] = 1 ; 
        for (j = i - 1 ; j >= 1 ; j--)
            v[j] = v[j] + v [j-1] ;
    }
} 
