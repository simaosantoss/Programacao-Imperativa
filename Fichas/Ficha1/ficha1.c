#include <stdio.h>

/*--------------------------------------- Ficha 1 ----------------------------------------*/

/* 
Exercício 1 

1) 12 16
2) 0 1 (uninitialized variable y)
3) A 65
   B 66 2 50
   b 98
4) 100 200

--------------------------------------------------------

Exercicio 2

1) a) 3 5
   b) 11 66
   c) _#_#_#_#_#_#_#_#_#_#
   d) 
      1
      01
      11
      001
      101
      011
      111
      0001
      1001
      0101
      1101
      0011
      1011
      0111 
      1111

*/

// Exercicio 3

// 3.1

// quadrado

void desenhaQuadrado (int x) {
    int linhas, colunas;
    for (linhas = 0 ; linhas < x ; linhas++) {
        for (colunas = 0 ; colunas < x ; colunas++) {
            putchar ('#');
        }
        putchar ('\n');
    }
}

// 3.2

// xadrez

void desenhaXadrez (int x) {
    int linhas , colunas ; 
    for (linhas = 0 ; linhas < x ; linhas++) {
        for (colunas = 0 ; colunas < x ; colunas++) {
            if ((linhas + colunas) % 2 == 0 ) putchar ('#');
            else putchar ('_');
        }
        putchar ('\n');
    }
}

// 3.3

// triangulo vertical

void trianguloVertical(int n) {
    // Fase crescente
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    // Fase decrescente
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}


// triangulo horizontal

void trianguloHorizontal(int n) {
    for (int i = 1; i <= n; i++) {
        int numHash = 2 * i - 1;
        for (int j = 0; j < numHash; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

int main() {
    printf("=== Ex3.1: Quadrado 5x5 ===\n");
    desenhaQuadrado(5);

    putchar('\n');

    printf("=== Ex3.2: Tabuleiro 5x5 ===\n");
    desenhaXadrez(5);

    putchar('\n');

    printf("=== Ex3.3(a): Triângulo Vertical (n=5) ===\n");
    trianguloVertical(5);

    putchar('\n');

    printf("=== Ex3.3(b): Triângulo Horizontal (n=5) ===\n");
    trianguloHorizontal(5);

    return 0;
}