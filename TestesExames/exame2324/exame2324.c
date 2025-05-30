#include <stdlib.h> // malloc, free, realloc
#include <string.h> 
#include <ctype.h>

// Exercício 1

int pesquisa(int x, int a[], int N) {
    int low = 0, high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            low = mid + 1; 
        else
            high = mid - 1;   
    }
    return -1;               
}

// Exercício 2

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;

int duplica (LInt *l) {
    if (*l == NULL) return 0;    

    LInt curr = *l;
    while (curr != NULL) {
        LInt novo = malloc(sizeof(struct lint_nodo));
        if (novo == NULL) return -1;   

        novo->valor = curr->valor;
        novo->prox  = curr->prox;
        curr->prox  = novo;

        curr = novo->prox;             
    }
    return 0;                         
}

// Exercicio 3

#include <string.h>

int expande(char s[]) {
    int lenOrig = strlen(s);
    if (lenOrig == 0) return 0;

    int lenExp = 0;
    for (int i = 0; i < lenOrig; i += 2) {
        int n = s[i + 1] - '0';
        lenExp += n;
    }

    char aux[lenExp + 1];

    int pos = 0;
    for (int i = 0; i < lenOrig; i += 2) {
        char c = s[i];
        int n = s[i + 1] - '0';

        for (int j = 0; j < n; j++) {
            aux[pos++] = c;
        }
    }
    aux[pos] = '\0';

    for (int i = 0; i <= lenExp; i++) {
        s[i] = aux[i];
    }

    return lenExp;
}

// Exercicio 4

int fizzbuzz2(int n) {
    int primeiraFB = -1;  
    int ultimaB = -1;     

    for (int i = 0; i < n; i++) {
        if (fizz(i) && buzz(i)) {
            if (primeiraFB == -1)
                primeiraFB = i;
        }

        if (buzz(i)) {
            ultimaB = i;
        }
    }

    if (primeiraFB == -1 || ultimaB == -1 || ultimaB <= primeiraFB)
        return -1;

    return ultimaB - primeiraFB - 1;  
}

// Exercicio 5

typedef struct abin_nodo { 
int valor; 
struct abin_nodo *esq, *dir; 
} *ABin;

int todosIguaisAux(ABin a, int n, int *valorRef, int *found) {
    if (a == NULL) return 1;

    if (n == 0) {
        if (!(*found)) {  
            *valorRef = a->valor;
            *found = 1;
            return 1;
        }
        return (a->valor == *valorRef);
    }

    return todosIguaisAux(a->esq, n-1, valorRef, found) &&
           todosIguaisAux(a->dir, n-1, valorRef, found);
}

int todosIguais(ABin a, int n) {
    int valorRef = 0;
    int found = 0;
    return todosIguaisAux(a, n, &valorRef, &found);
}

// Exercício 6

int calcula(char s[]) {
    int stack[100];  
    int sp = 0;      

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isdigit(c)) {
           
            stack[sp++] = c - '0';
        }
        else if (c == '+' || c == '*') {
            if (sp < 2) return -1; 

            int b = stack[--sp];   
            int a = stack[--sp];   
            int res;

            if (c == '+') res = a + b;
            else          res = a * b;

            stack[sp++] = res;  
        }
        else {
            return -1;
        }
    }

    if (sp != 1) return -1;

    return stack[0];
}
