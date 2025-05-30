#include <stdlib.h> // malloc, free, realloc
#include <string.h> 

// Exercicio 1
int perfeito(int x) {
    int soma = 0;

    for (int i = 1; i <= x / 2; i++) {          // i <= x/2 porque nenhum número é divisível por algum número maior que a sua metade (exceto pelo o próprio número)
        if (x % i == 0)
            soma += i;
    }

    return soma == x;
}


// Exercicio 2
typedef struct {
     int x,y;
} Ponto;

//não usei sqrt porque fica mais eficiente, sqrt(a) < sqrt(b) => a < b
int distancia(Ponto p) {
    return p.x * p.x + p.y * p.y;
}

void ordena(Ponto pos[], int N) {
    for (int i = 0; i < N - 1; i++) {

        for (int j = 0; j < N - 1 - i; j++) {

            if (distancia(pos[j]) > distancia(pos[j + 1])) {

                Ponto tmp = pos[j];
                pos[j] = pos[j + 1];
                pos [j + 1] = tmp;
                
            }
        }
    }
}

// Exercicio 3
typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;


int depth(ABin a, int x) {
    if (a == NULL) return -1;
    if (a->valor == x) return 0;

    int e = depth(a->esq, x);
    if (e != -1) return e + 1;

    int d = depth(a->dir, x);
    if (d != -1) return d + 1;

    return -1;
}

// Exercicio 4
#include <string.h>

int wordle(char secreta[], char tentativa[]) {
    int tam = strlen(tentativa);
    int corretas = 0;

    // 1ª parte: letras na posição certa -> maiúsculas
    for (int i = 0; i < tam; i++) {
        if (secreta[i] == tentativa[i]) {
            tentativa[i] = tentativa[i] - 32;
            corretas++;
        }
    }

    // 2ª parte: letras erradas -> '*' se não existirem
    for (int i = 0; i < tam; i++) {
        // Se já está em maiúscula, já foi tratada
        if (tentativa[i] >= 'A' && tentativa[i] <= 'Z') continue;

        int encontrada = 0;
        for (int j = 0; j < tam; j++) {
            if (secreta[j] == tentativa[i]) {
                encontrada = 1;
                break;
            }
        }

        if (!encontrada)
            tentativa[i] = '*';
    }

    return corretas;
}

// Exercicio 5

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;

LInt criarNodo(int v) {
    LInt novo = malloc(sizeof(struct lint_nodo));
    if (!novo) return NULL;
    novo->valor = v;
    novo->prox = NULL;
    return novo;
}

LInt periodica(char s[]) {
    LInt inicio = NULL, fim = NULL;
    LInt inicio_periodica = NULL;
    int i = 0;

    while(s[i] && s[i] != '(') {
        LInt novo = criarNodo(s[i] - '0');
        if (!novo) return NULL;
        if (!inicio) inicio = novo;
        else fim->prox = novo;
        fim = novo;
        i++;
    }

    if (s[i] != '(') {
        if (fim) fim->prox = inicio; 
        return inicio;
    }

    i++;

    LInt anterior_periodica = NULL;
    int start_periodica_index = i;

    while (s[i] && s[i] != ')') {
        LInt novo = criarNodo(s[i] - '0');
        if (!novo) return NULL;
        if (!inicio_periodica) inicio_periodica = novo;
        else anterior_periodica->prox = novo;
        anterior_periodica = novo;
        i++;
    }

    if (s[i] != ')') {
        return NULL;
    }

    if (fim) fim->prox = inicio_periodica;
    else inicio = inicio_periodica;

    anterior_periodica->prox = inicio_periodica;

    return inicio;
}
