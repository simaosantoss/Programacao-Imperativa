#include <stdlib.h> // malloc, free, realloc
#include <string.h> 
#include <ctype.h>

// Exercicio 1

int pesquisa(int x, int a[], int N) {
    int low = 0;
    int high = N - 1;

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

// Exercicio 2

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;

void duplicaTodos(LInt l) {

    while (l != NULL) {
        LInt novo = malloc(sizeof(struct lint_nodo));
        novo->valor = l->valor;
        novo->prox = l->prox;
        l->prox = novo;

        l = l->prox->prox;
    }
}

// Exercicio 3

int expande(char s[]) {
    int tamanho_final = 0;
    int len_original = strlen(s);
    
    for (int i = 0; i < len_original; i += 2) {
        int digito = s[i+1] - '0';
        tamanho_final += digito;
    }
    
    s[tamanho_final] = '\0';
    
    int pos_destino = tamanho_final - 1;  
    
    for (int i = len_original - 2; i >= 0; i -= 2) {
        char c = s[i];                  
        int digito = s[i+1] - '0';       
        

        for (int j = 0; j < digito; j++) {
            s[pos_destino] = c;
            pos_destino--;
        }
    }
    
    return tamanho_final;
}

// Exercicio 4

int fizzbuzz(int n) {
    int primeiro_fizzbuzz = -1;
    int ultimo_buzz_seguinte = -1;

    for (int i = 0; i < n; i++) {

        if (fizz(i) && buzz(i)) {
            primeiro_fizzbuzz = i;
            break;
        }
    }

    if (primeiro_fizzbuzz == -1) return -1;

    for (int j = primeiro_fizzbuzz + 1; j < n; j++) {
        if (buzz(j) && !fizz(j)) {
            ultimo_buzz_seguinte = j;
        }
    }

    if (ultimo_buzz_seguinte == -1) return -1;

    int diferenca = ultimo_buzz_seguinte - primeiro_fizzbuzz;

    return diferenca;
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
