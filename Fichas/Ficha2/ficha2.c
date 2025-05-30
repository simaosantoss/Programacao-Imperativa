#include <stdio.h>

/*--------------------------------------- Ficha 2 ----------------------------------------*/

// Exercicio 1

float multInt1 (int n , float m) {
    // calcula n * m
    float r = 0 , i ;
    for (i = 0 ; i < n ; i++)
            r += m ;
    return r ; 
}

/*
Forma recursiva. Versão mais simples de fazer a mesma função (minha opinião):

float multInt (int n, float m) {
    if (n == 1) return m;
    else return (m + multInt(n - 1,m));
}
*/

// Exercicio 2

float multInt2 (int n , float m) {
    float r = 0;
    while (n>0) {
        if (n%2 == 1)
            r += m;
        // em vez de 
        // n = n/2 ; m = m * 2 
        // (para que não se use '/' nem '*')
        n = n >> 1 ; m = m+m;
    }
    return r;
}

// Exercicio 3

// para confirmar que está certo fiz uma função que imprime todos os divisores de um numero n
int imprimeDivisores (unsigned n) {
    int i ;
    for (i = 1 ; i <= n ; i++) {
        if (n % i == 0) 
            printf ("%d\n" , i );
    }
}

int mdc1 (int a, int b) {
    int i , p ;
        // alternativa à linha de baixo : p = (n > m) ? n : m ;
            // significa que se n for maior que m , devolve n. Senão devolve m
    if (a < b) p = a ; else p = b ; 
    for (i = p ; i > 0 ; i--) {
        if
            (a % i == 0 && b % i == 0)
            return i ;
    }
}

// Exercicio 4

int mdc2 (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) 
            a -= b ;
        else 
            b -= a ;
    }
    if (a == 0) return b ;
    else return a ;
}

// Exercicio 5

int mdc3 (int a, int b) {
    while (a > 0 && b > 0)
        if (a > b) a = a % b ;
        else b = b % a ;
    if (a == 0) return b ;
    else return a ;
}

// Exercicio 6

// a) 

int fib1 (int n) {
    if (n == 0 || n == 1) return 1 ;
    else return fib (n - 1) + fib (n - 2) ;
}

// b) 
int fib2 (int n) {
    int x , acc1 = 1 , acc2 = 0 ;
    for (int i = 3 ; i <= n ; i++) {
        x = acc2 ;
        acc2 += acc1 ;
        acc1 = x ;
    }
    return acc2;
}

int main ( int argc , char const * argv [] ) {
    int opt , num1 , num2 ;
    float fl1 ;
    
    printf ( "Introduz o número da pergunta: " ) ;
    scanf ( "%d", & opt ) ;
    
    switch ( opt ) {
        case 1 :
            scanf ( "%d %f", & num1 , & fl1 ) ;
            float ans = multInt1 ( num1 , fl1 ) ;
            printf ( "Resposta: %f" , ans ) ;
            break ;
        case 2 :
            scanf ( "%d %f", & num1 , & fl1 ) ;
            ans = multInt2 ( num1 , fl1 ) ;
            printf ( "Resposta: %f" , ans ) ;
            break ;
        case 3 :
            scanf ( "%d %d", & num1 , & num2 ) ;
            printf ( "Resposta: %d" , mdc1 ( num1 , num2 ) ) ;
            break ;
        case 4 :
            scanf ( "%d %d", & num1 , & num2 ) ;
            printf ( "Resposta: %d" , mdc2 ( num1 , num2 ) ) ;
            break ;
        case 5 :
            scanf ( "%d %d", & num1 , & num2 ) ;
            printf ( "Resposta: %d" , mdc3 ( num1 , num2 ) ) ;
            break ;
        case 6 :
            scanf ( "%d", & num1 ) ;
            printf ( "Resposta: %d" , fib1 ( num1 ) ) ;
            break ;
        case 7 :
            scanf ( "%d", & num1 ) ;
            printf ( "Resposta: %d" , fib2 ( num1 ) ) ;
            break ;
        default :
            break ;
    }
    return 0 ;
}
