#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

// 1 - Maior da sequência

void one () {
    int num , maior;
    printf ("Insira uma sequência de números (um número por linha) terminada em 0 para saber o maior: ");
    scanf ("%d" , &num);

    if (num == 0) {
        printf ("Nenhum numero foi inserido\n");
        return;
    }

    maior = num ;
    while (num != 0) {
        scanf ("%d" , &num);
        if (num > maior) {
            maior = num;
        }
    }

    printf("O maior número é: %d\n", maior);
}


// 2 - Média da sequência

void two () {
    int num , media , nArray = 0 , soma = 0;
    printf ("Insira uma sequência de números (um número por linha) terminada em 0 para saber a média: ");
    scanf ("%d" , &num);

    if (num == 0) {
        printf("Nenhum número foi inserido.\n");
        return;
    }

    while (num != 0) {
        soma += num;
        nArray++;
        scanf ("%d" , &num);
    }

    media = soma / nArray;
    printf ("A média da sequência é %d" , media);
}

// 3 - Segundo maior da sequência

void three() {
    int num;
    int maior = INT_MIN;         // começa com o menor int possível
    int segundoMaior = INT_MIN;

    scanf ("%d", &num);
    
    if (num == 0) {
        printf ("Nenhum número foi inserido.\n");
        return;
    }

    while (num != 0) {
        scanf ("%d", &num);
        if (num > maior) {
            segundoMaior = maior;
            maior = num;
        }
        else if (num > segundoMaior && num < maior) {
            segundoMaior = num;
        }
    }

    printf ("O segundo maior número da sequência é %d\n", segundoMaior);
}


// 4 - Nº de bits iguais a 1 na representação binária de n

int bitsUm (unsigned int n) {
    int cont = 0;

    while (n != 0) {
        if (n % 2 == 1)
            cont++;
        n = n >> 1;
    }

    return cont;
}

// 5 - Nº de bits a 0 no final da representação binária de um número

int trailingZ (unsigned int n) {
    if (n % 2) return 0;
    else return 1 + trailingZ (n >> 1);
}

// 6 - Nº de dígitos necessários para escrever o inteiro n em base decimal

int qDig (unsigned int n){
    if (n / 10 < 1) return 1;
    else return 1 + qDig (n / 10);
}

// 7 - Concatena a string s2 a s1

char* mystrcat(char s1[], char s2[]) {
    char *dest = s1;

    while (*dest != '\0'){
    dest++;
    }

    while (*s2 != '\0') {
        *dest = *s2;
        dest++;
        s2++;
    }

    *dest = '\n';
    return s1; 
}

// 8 - Copia a string source para dest retornando o valor desta última

char *mystrcpy (char *dest, char source[]) {
    char *p = dest;

    while (*source != '\0') {
        *p = *source;
        p++;
        source++;
    }

    *p = '\0';
    return dest;
}


// 9 - Comparar (lexicograficamente) duas strings

int mystrcmp (char s1[], char s2[]) {
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    else return (s1[i] - s2[i]);
}

// 10 - Determinar a posição onde a string s2 ocorre em s1

char *mystrstr (char s1[], char s2[]) {

    if (s2[0] == '\0') {
        return s1;
    }
    
    for (int i = 0; s1[i] != '\0'; i++) {
        int j;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i+j] != s2[j]) {
                break;
            }
        }

        if (s2[j] == '\0') {
            return &s1[i];
        }
    }

    return NULL;
}

// 11 - Inverter uma string

void swap(char s[], int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void strrev(char s[]) {
    int inicio = 0;
    int fim = strlen(s) - 1;
    while (inicio < fim) {
        swap(s, inicio, fim);
        inicio++;
        fim--;
    }
}

// 12 - Retirar todas as vogais de uma string

int evogal (char c) {
    char *v = "aAeEiIoOuU";
    int i;

    for (i = 0 ; v[i] != '\0' && v[i] != c ; i++);
    return (v[i] != '\0');
}

void strnoV(char s[]) {
    int i = 0, j = 0;
    
    while (s[i] != '\0') {
        if (!evogal(s[i])) {
            s[j] = s[i];
            j++;
        }
        i++;
    }

    s[j] = '\0';
}

// 13 - Truncar todas as palavras de forma a terem no máximo n caracteres

void truncW(char t[], int n) {
    int i = 0, j = 0, contador = 0;

    while (t[i] != '\0') {

        if (t[i] != ' ') {
            if (contador < n) {
                t[j] = t[i];  
                j++;          
                contador++; 
            }
        } else {
            t[j] = ' '; 
            j++;       
            contador = 0;
        }
        i++;
    }
    
    t[j] = '\0';
}


// 14 - Determinar qual o caracter mais frequente numa string

char charMaisfreq(char s[]) {
    int i, maxCount = 0;
    char mostFrequent = 0;

    if (s[0] == '\0') return 0;

    int count[256] = {0};

    for (i = 0; s[i] != '\0' ; i++) {
        count[s[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequent = (char)i;
        }
    }

    return mostFrequent;
}

// 15 - Calcular o comprimento da maior sub-string com caracteres iguais

int iguaisConsecutivos(char s[]) {
    int i = 0;
    int cont = 1;
    int max = 1;

    while (s[i] != '\0') {
        if (s[i] == s[i + 1]) {
            cont++;
        } else {
            if (cont > max) {
                max = cont;
            }
            cont = 1;
        }
        i++;
    }

    if (cont > max) {
        max = cont;
    }

    return max;
}

// 16 - Calcular o comprimento da maior sub-string com caracteres diferentes
int difConsecutivos(char s[]) {
    int i = 0, cont = 1, max = 1;
    
    if (s[0] == '\0') {
        return 0;
    }

    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[i - 1]) {
            cont++;
        } else {
            if (cont > max) {
                max = cont;
            }
            cont = 1;
        }
    }

    if (cont > max) {
        max = cont;
    }

    return max;
}

// 17 - Calcular o comprimento do maior prefixo comum entre duas strings
int maiorPrefixo(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return i;
}

// 18 - Calcular o comprimento do maior sufixo comum entre duas strings
int maiorSufixo(char s1[], char s2[]) {
    int i = strlen(s1) - 1, j = strlen(s2) - 1, count = 0;
    
    while (i >= 0 && j >= 0 && s1[i] == s2[j]) {
        count++;
        i--;
        j--;
    }
    
    return count;
}

// 19 - Calcular o tamanho do maior sufixo de s1 que é um prefixo de s2
int sufPref(char s1[], char s2[]) {
    int i, j;
    for (i = strlen(s1); i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (s1[strlen(s1) - i + j] != s2[j]) {
                break;
            }
        }
        if (j == i) {
            return i;
        }
    }
    return 0;
}

// 20 - Contar o número de palavras em uma string
int contaPal(char s[]) {
    int i = 0, count = 0, inWord = 0;

    while (s[i] != '\0') {
        if (s[i] != ' ' && !inWord) {
            inWord = 1;
            count++;
        } else if (s[i] == ' ' && inWord) {
            inWord = 0;
        }
        i++;
    }

    return count;
}

// 21 - Contar o número de vogais em uma string
int contaVogais(char s[]) {
    int i = 0, count = 0;
    while (s[i] != '\0') {
        if (strchr("aeiouAEIOU", s[i])) {
            count++;
        }
        i++;
    }
    return count;
}

// 22 - Testar se todos os caracteres da primeira string aparecem na segunda
int contida(char a[], char b[]) {
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {
        int found = 0;
        for (j = 0; b[j] != '\0'; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

// 23 - Testar se uma palavra é palíndrome
int palindromo(char s[]) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// 24 - Eliminar caracteres repetidos sucessivos em uma string
int remRep(char x[]) {
    int i = 0, j = 0;
    while (x[i] != '\0') {
        if (x[i] != x[i + 1]) {
            x[j++] = x[i];
        }
        i++;
    }
    x[j] = '\0';
    return j;
}

// 25 - Eliminar sucessivas repetições de espaços em uma string
int limpaEspacos(char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] != ' ' || (i > 0 && t[i-1] != ' ')) {
            t[j++] = t[i];
        }
        i++;
    }
    t[j] = '\0';
    return j;
}

// 26 - Inserir um elemento em um vetor ordenado
void insere(int v[], int N, int x) {
    int i = N - 1;
    while (i >= 0 && v[i] > x) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = x;
}

// 27 - Merge de dois vetores ordenados
void merge(int r[], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = b[j++];
        }
    }
    while (i < na) {
        r[k++] = a[i++];
    }
    while (j < nb) {
        r[k++] = b[j++];
    }
}

// 28 - Testar se elementos de um vetor estão em ordem crescente
int crescente(int a[], int i, int j) {
    for (int k = i; k < j; k++) {
        if (a[k] > a[k + 1]) {
            return 0;
        }
    }
    return 1;
}

// 29 - Retirar números negativos de um vetor
int retiraNeg(int v[], int N) {
    int i, j = 0;
    for (i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[j++] = v[i];
        }
    }
    return j;
}

// 30 - Retornar o menos frequente elemento de um vetor ordenado
int menosFreq(int v[], int N) {
    int minCount = N, count = 1, i;
    int minVal = v[0];
    for (i = 1; i < N; i++) {
        if (v[i] == v[i - 1]) {
            count++;
        } else {
            if (count < minCount) {
                minCount = count;
                minVal = v[i - 1];
            }
            count = 1;
        }
    }
    if (count < minCount) {
        minVal = v[N - 1];
    }
    return minVal;
}

// 31 - Retornar o mais frequente elemento de um vetor ordenado
int maisFreq(int v[], int N) {
    int maxCount = 1, count = 1, i;
    int maxVal = v[0];
    for (i = 1; i < N; i++) {
        if (v[i] == v[i - 1]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                maxVal = v[i - 1];
            }
            count = 1;
        }
    }
    if (count > maxCount) {
        maxVal = v[N - 1];
    }
    return maxVal;
}

// 32 - Calcular o comprimento da maior sequência crescente de elementos consecutivos
int maxCresc(int v[], int N) {
    int max = 1, count = 1, i;
    for (i = 1; i < N; i++) {
        if (v[i] > v[i - 1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 1;
        }
    }
    if (count > max) {
        max = count;
    }
    return max;
}

// 33 - Eliminar repetições no vetor
int elimRep(int v[], int n) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (int k = 0; k < j; k++) {
            if (v[i] == v[k]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            v[j++] = v[i];
        }
    }
    return j;
}

// 34 - Eliminar repetições em vetor ordenado
int elimRepOrd(int v[], int n) {
    int i, j = 1;
    for (i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            v[j++] = v[i];
        }
    }
    return j;
}

// 35 - Calcular o número de elementos em comum entre dois vetores ordenados
int comunsOrd(int a[], int na, int b[], int nb) {
    int i = 0, j = 0, count = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            count++;
            i++;
            j++;
        }
    }
    return count;
}

// 36 - Calcular o número de elementos em comum entre dois vetores não ordenados
int comuns(int a[], int na, int b[], int nb) {
    int count = 0;
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

// 37 - Encontrar o índice do menor elemento do vetor
int minInd(int v[], int n) {
    int min = v[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
            index = i;
        }
    }
    return index;
}

// 38 - Preencher vetor Ac com somas acumuladas do vetor v
void somasAc(int v[], int Ac[], int N) {
    Ac[0] = v[0];
    for (int i = 1; i < N; i++) {
        Ac[i] = Ac[i - 1] + v[i];
    }
}

// 39 - Testar se uma matriz é triangular superior
int triSup(int N, float m[N][N]) {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

// 40 - Transformar uma matriz na sua transposta
void transposta(int N, float m[N][N]) {
    float temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

// 41 - Adicionar uma matriz à outra
void addTo(int N, int M, int a[N][M], int b[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

// 42 - União de dois conjuntos
int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] | v2[i];
    }
    return 1;
}

// 43 - Interseção de dois conjuntos
int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] & v2[i];
    }
    return 1;
}

// 44 - Interseção de multi-conjuntos
int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = (v1[i] < v2[i]) ? v1[i] : v2[i];
    }
    return 1;
}

// 45 - União de multi-conjuntos
int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
    }
    return 1;
}

// 46 - Cardinalidade de um multi-conjunto
int cardinalMSet(int N, int v[N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
    }
    return sum;
}

// 47 - Calcular a posição final do robot após os movimentos

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal(Posicao inicial, Movimento mov[], int N) {
    for (int i = 0; i < N; i++) {
        switch (mov[i]) {
            case Norte: inicial.y++; break;
            case Sul: inicial.y--; break;
            case Este: inicial.x++; break;
            case Oeste: inicial.x--; break;
        }
    }
    return inicial;
}

// 48 - Preencher movimentos para alcançar a posição final
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i = 0;
    while (inicial.x != final.x || inicial.y != final.y) {
        if (inicial.x < final.x) {
            mov[i++] = Este;
            inicial.x++;
        } else if (inicial.x > final.x) {
            mov[i++] = Oeste;
            inicial.x--;
        }
        if (inicial.y < final.y) {
            mov[i++] = Norte;
            inicial.y++;
        } else if (inicial.y > final.y) {
            mov[i++] = Sul;
            inicial.y--;
        }
        if (i >= N) return -1;
    }
    return i;
}

// 49 - Encontrar o índice da posição mais central
int maisCentral(Posicao pos[], int N) {
    int index = 0;
    double minDist = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y);
    for (int i = 1; i < N; i++) {
        double dist = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
        if (dist < minDist) {
            minDist = dist;
            index = i;
        }
    }
    return index;
}

// 50 - Calcular quantos vizinhos são adjacentes à posição dada
int vizinhos(Posicao p, Posicao pos[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if ((abs(p.x - pos[i].x) == 1 && p.y == pos[i].y) || (abs(p.y - pos[i].y) == 1 && p.x == pos[i].x)) {
            count++;
        }
    }
    return count;
}

// Main

int main(void) {
    int opt;
    do {
        // Exibe o menu de opções
        printf("\n--- Menu ---\n");
        printf("1 - Encontrar o maior número da sequência (one)\n");
        printf("2 - Calcular a média da sequência (two)\n");
        printf("3 - Encontrar o segundo maior número da sequência (three)\n");
        printf("4 - Contar os bits 1 de um número (bitsUm)\n");
        printf("5 - Contar os bits a 0 no final da representação (trailingZ)\n");
        printf("6 - Calcular o número de dígitos (qDig)\n");
        printf("7 - Concatenar duas strings (mystrcat)\n");
        printf("8 - Copiar uma string (mystrcpy)\n");
        printf("9 - Comparar duas strings (mystrcmp)\n");
        printf("10 - Encontrar a posição onde uma string ocorre em outra (mystrstr)\n");
        printf("11 - Inverter uma string (strrev)\n");
        printf("12 - Retirar todas as vogais de uma string (strnoV)\n");
        printf("13 - Truncar todas as palavras de forma a terem no máximo n caracteres (truncW)\n");
        printf("14 - Determinar qual o caracter mais frequente numa string (charMaisfreq)\n");
        printf("15 - Calcular o comprimento da maior sub-string com caracteres iguais (iguaisConsecutivos)\n");
        printf("16 - Calcular o comprimento da maior sub-string com caracteres diferentes (difConsecutivos)\n");
        printf("17 - Calcular o comprimento do maior prefixo comum entre duas strings (maiorPrefixo)\n");
        printf("18 - Calcular o comprimento do maior sufixo comum entre duas strings (maiorSufixo)\n");
        printf("19 - Calcular o tamanho do maior sufixo de s1 que é um prefixo de s2 (sufPref)\n");
        printf("20 - Contar o número de palavras em uma string (contaPal)\n");
        printf("21 - Contar o número de vogais em uma string (contaVogais)\n");
        printf("22 - Testar se todos os caracteres da primeira string aparecem na segunda (contida)\n");
        printf("23 - Testar se uma palavra é palíndromo (palindromo)\n");
        printf("24 - Eliminar caracteres repetidos sucessivos em uma string (remRep)\n");
        printf("25 - Eliminar sucessivas repetições de espaços em uma string (limpaEspacos)\n");
        printf("26 - Inserir um elemento em um vetor ordenado (insere)\n");
        printf("27 - Merge de dois vetores ordenados (merge)\n");
        printf("28 - Testar se elementos de um vetor estão em ordem crescente (crescente)\n");
        printf("29 - Retirar números negativos de um vetor (retiraNeg)\n");
        printf("30 - Retornar o menos frequente elemento de um vetor ordenado (menosFreq)\n");
        printf("31 - Retornar o mais frequente elemento de um vetor ordenado (maisFreq)\n");
        printf("32 - Calcular o comprimento da maior sequência crescente de elementos consecutivos (maxCresc)\n");
        printf("33 - Eliminar repetições no vetor (elimRep)\n");
        printf("34 - Eliminar repetições em vetor ordenado (elimRepOrd)\n");
        printf("35 - Calcular o número de elementos em comum entre dois vetores ordenados (comunsOrd)\n");
        printf("36 - Calcular o número de elementos em comum entre dois vetores não ordenados (comuns)\n");
        printf("37 - Encontrar o índice do menor elemento do vetor (minInd)\n");
        printf("38 - Preencher vetor Ac com somas acumuladas do vetor v (somasAc)\n");
        printf("39 - Testar se uma matriz é triangular superior (triSup)\n");
        printf("40 - Transformar uma matriz na sua transposta (transposta)\n");
        printf("41 - Adicionar uma matriz à outra (addTo)\n");
        printf("42 - União de dois conjuntos (unionSet)\n");
        printf("43 - Interseção de dois conjuntos (intersectSet)\n");
        printf("44 - Interseção de multi-conjuntos (intersectMSet)\n");
        printf("45 - União de multi-conjuntos (unionMSet)\n");
        printf("46 - Cardinalidade de um multi-conjunto (cardinalMSet)\n");
        printf("47 - Calcular a posição final do robot após os movimentos (posFinal)\n");
        printf("48 - Preencher movimentos para alcançar a posição final (caminho)\n");
        printf("49 - Encontrar o índice da posição mais central (maisCentral)\n");
        printf("50 - Calcular quantos vizinhos são adjacentes à posição dada (vizinhos)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4: {
                unsigned int n;
                printf("Insira um número: ");
                scanf("%u", &n);
                int res = bitsUm(n);
                printf("O número de bits 1 em %u é: %d\n", n, res);
                break;
            }
            case 5: {
                unsigned int n;
                printf("Insira um número: ");
                scanf("%u", &n);
                int tz = trailingZ(n);
                printf("O número de zeros no final da representação de %u é: %d\n", n, tz);
                break;
            }
            case 6: {
                unsigned int n;
                printf("Insira um número: ");
                scanf("%u", &n);
                int q = qDig(n);
                printf("O número de dígitos em %u é: %d\n", n, q);
                break;
            }
            case 7: {
                char s1[100], s2[100];
                printf("Insira a primeira string: ");
                scanf("%s", s1);
                printf("Insira a segunda string: ");
                scanf("%s", s2);
                char *result = mystrcat(s1, s2);
                printf("String concatenada: %s\n", result);
                break;
            }
            case 8: {
                char s1[100], s2[100];
                printf("Insira a string original: ");
                scanf("%s", s1);
                printf("Insira a string a ser copiada: ");
                scanf("%s", s2);
                char *result = mystrcpy(s1, s2);
                printf("String copiada: %s\n", result);
                break;
            }
            case 9: {
                char s1[100], s2[100];
                printf("Insira a primeira string: ");
                scanf("%s", s1);
                printf("Insira a segunda string: ");
                scanf("%s", s2);
                int cmp = mystrcmp(s1, s2);
                printf("Resultado da comparação: %d\n", cmp);
                break;
            }
            case 10: {
                char s1[100], s2[100];
                printf("Insira a string onde procurar: ");
                scanf("%s", s1);
                printf("Insira a substring a procurar: ");
                scanf("%s", s2);
                char *pos = mystrstr(s1, s2);
                if (pos != NULL)
                    printf("A substring foi encontrada em: %s\n", pos);
                else
                    printf("Substring não encontrada.\n");
                break;
            }
            case 11: {
                char s[100];
                printf("Insira a string para inverter: ");
                scanf("%s", s);
                strrev(s);
                printf("String invertida: %s\n", s);
                break;
            }
            case 12: {
                char s[100];
                printf("Insira a string para remover as vogais: ");
                scanf("%s", s);
                strnoV(s);
                printf("String sem vogais: %s\n", s);
                break;
            }
            case 13: {
                char t[100];
                int n;
                printf("Insira a string: ");
                scanf("%s", t);
                printf("Insira o número máximo de caracteres para truncar: ");
                scanf("%d", &n);
                truncW(t, n);
                printf("String truncada: %s\n", t);
                break;
            }
            case 14: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                char res = charMaisfreq(s);
                if (res == 0)
                    printf("A string está vazia.\n");
                else
                    printf("O caractere mais frequente é: %c\n", res);
                break;
            }
            case 15: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = iguaisConsecutivos(s);
                printf("O comprimento da maior sub-string com caracteres iguais é: %d\n", res);
                break;
            }
            case 16: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = difConsecutivos(s);
                printf("O comprimento da maior sub-string com caracteres diferentes é: %d\n", res);
                break;
            }
            case 17: {
                char s1[100], s2[100];
                printf("Insira a primeira string: ");
                scanf("%s", s1);
                printf("Insira a segunda string: ");
                scanf("%s", s2);
                int res = maiorPrefixo(s1, s2);
                printf("O comprimento do maior prefixo comum é: %d\n", res);
                break;
            }
            case 18: {
                char s1[100], s2[100];
                printf("Insira a primeira string: ");
                scanf("%s", s1);
                printf("Insira a segunda string: ");
                scanf("%s", s2);
                int res = maiorSufixo(s1, s2);
                printf("O comprimento do maior sufixo comum é: %d\n", res);
                break;
            }
            case 19: {
                char s1[100], s2[100];
                printf("Insira a primeira string: ");
                scanf("%s", s1);
                printf("Insira a segunda string: ");
                scanf("%s", s2);
                int res = sufPref(s1, s2);
                printf("O comprimento do maior sufixo de s1 que é prefixo de s2 é: %d\n", res);
                break;
            }
            case 20: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = contaPal(s);
                printf("O número de palavras na string é: %d\n", res);
                break;
            }
            case 21: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = contaVogais(s);
                printf("O número de vogais na string é: %d\n", res);
                break;
            }
            case 22: {
                char a[100], b[100];
                printf("Insira a primeira string: ");
                scanf("%s", a);
                printf("Insira a segunda string: ");
                scanf("%s", b);
                int res = contida(a, b);
                printf("Todos os caracteres de a estão em b: %s\n", res ? "Sim" : "Não");
                break;
            }
            case 23: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = palindromo(s);
                printf("A palavra %s é um palíndromo.\n", res ? "é" : "não é");
                break;
            }
            case 24: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = remRep(s);
                printf("String após eliminar repetições: %s\n", s);
                break;
            }
            case 25: {
                char s[100];
                printf("Insira a string: ");
                scanf("%s", s);
                int res = limpaEspacos(s);
                printf("String após eliminar espaços sucessivos: %s\n", s);
                break;
            }
            case 26: {
                int v[100], N, x;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                printf("Insira o elemento a inserir: ");
                scanf("%d", &x);
                insere(v, N, x);
                printf("Vetor após inserção: ");
                for (int i = 0; i < N + 1; i++) {
                    printf("%d ", v[i]);
                }
                printf("\n");
                break;
            }
            case 27: {
                int a[100], b[100], r[200], na, nb;
                printf("Insira o número de elementos do vetor a: ");
                scanf("%d", &na);
                printf("Insira os elementos do vetor a: ");
                for (int i = 0; i < na; i++) {
                    scanf("%d", &a[i]);
                }
                printf("Insira o número de elementos do vetor b: ");
                scanf("%d", &nb);
                printf("Insira os elementos do vetor b: ");
                for (int i = 0; i < nb; i++) {
                    scanf("%d", &b[i]);
                }
                merge(r, a, b, na, nb);
                printf("Vetor resultado: ");
                for (int i = 0; i < na + nb; i++) {
                    printf("%d ", r[i]);
                }
                printf("\n");
                break;
            }
            case 28: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = crescente(v, 0, N-1);
                printf("O vetor está em ordem crescente: %s\n", res ? "Sim" : "Não");
                break;
            }
            case 29: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = retiraNeg(v, N);
                printf("Vetor após retirar números negativos: ");
                for (int i = 0; i < res; i++) {
                    printf("%d ", v[i]);
                }
                printf("\n");
                break;
            }
            case 30: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = menosFreq(v, N);
                printf("O menos frequente elemento é: %d\n", res);
                break;
            }
            case 31: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = maisFreq(v, N);
                printf("O mais frequente elemento é: %d\n", res);
                break;
            }
            case 32: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = maxCresc(v, N);
                printf("O comprimento da maior sequência crescente é: %d\n", res);
                break;
            }
            case 33: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = elimRep(v, N);
                printf("Vetor após eliminar repetições: ");
                for (int i = 0; i < res; i++) {
                    printf("%d ", v[i]);
                }
                printf("\n");
                break;
            }
            case 34: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = elimRepOrd(v, N);
                printf("Vetor após eliminar repetições em vetor ordenado: ");
                for (int i = 0; i < res; i++) {
                    printf("%d ", v[i]);
                }
                printf("\n");
                break;
            }
            case 35: {
                int a[100], b[100], na, nb;
                printf("Insira o número de elementos do vetor a: ");
                scanf("%d", &na);
                printf("Insira os elementos do vetor a: ");
                for (int i = 0; i < na; i++) {
                    scanf("%d", &a[i]);
                }
                printf("Insira o número de elementos do vetor b: ");
                scanf("%d", &nb);
                printf("Insira os elementos do vetor b: ");
                for (int i = 0; i < nb; i++) {
                    scanf("%d", &b[i]);
                }
                int res = comunsOrd(a, na, b, nb);
                printf("O número de elementos em comum entre os vetores é: %d\n", res);
                break;
            }
            case 36: {
                int a[100], b[100], na, nb;
                printf("Insira o número de elementos do vetor a: ");
                scanf("%d", &na);
                printf("Insira os elementos do vetor a: ");
                for (int i = 0; i < na; i++) {
                    scanf("%d", &a[i]);
                }
                printf("Insira o número de elementos do vetor b: ");
                scanf("%d", &nb);
                printf("Insira os elementos do vetor b: ");
                for (int i = 0; i < nb; i++) {
                    scanf("%d", &b[i]);
                }
                int res = comuns(a, na, b, nb);
                printf("O número de elementos em comum entre os vetores é: %d\n", res);
                break;
            }
            case 37: {
                int v[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = minInd(v, N);
                printf("O índice do menor elemento é: %d\n", res);
                break;
            }
            case 38: {
                int v[100], Ac[100], N;
                printf("Insira o número de elementos no vetor: ");
                scanf("%d", &N);
                printf("Insira os elementos do vetor: ");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                somasAc(v, Ac, N);
                printf("Vetor com somas acumuladas: ");
                for (int i = 0; i < N; i++) {
                    printf("%d ", Ac[i]);
                }
                printf("\n");
                break;
            }
            case 39: {
                int N;
                float m[100][100];
                printf("Insira a ordem da matriz: ");
                scanf("%d", &N);
                printf("Insira os elementos da matriz:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        scanf("%f", &m[i][j]);
                    }
                }
                int res = triSup(N, m);
                printf("A matriz é triangular superior: %s\n", res ? "Sim" : "Não");
                break;
            }
            case 40: {
                int N;
                float m[100][100];
                printf("Insira a ordem da matriz: ");
                scanf("%d", &N);
                printf("Insira os elementos da matriz:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        scanf("%f", &m[i][j]);
                    }
                }
                transposta(N, m);
                printf("Matriz transposta:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        printf("%f ", m[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 41: {
                int N, M;
                int a[100][100], b[100][100];
                printf("Insira a ordem da matriz: ");
                scanf("%d", &N);
                printf("Insira a ordem da segunda matriz: ");
                scanf("%d", &M);
                printf("Insira os elementos da primeira matriz:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("Insira os elementos da segunda matriz:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        scanf("%d", &b[i][j]);
                    }
                }
                addTo(N, M, a, b);
                printf("Matriz após a adição:\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 42: {
                int N;
                int v1[100], v2[100], r[100];
                printf("Insira o número de elementos do primeiro conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do primeiro conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v1[i]);
                }
                printf("Insira o número de elementos do segundo conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do segundo conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v2[i]);
                }
                int res = unionSet(N, v1, v2, r);
                printf("União dos dois conjuntos: ");
                for (int i = 0; i < N; i++) {
                    printf("%d ", r[i]);
                }
                printf("\n");
                break;
            }
            case 43: {
                int N;
                int v1[100], v2[100], r[100];
                printf("Insira o número de elementos do primeiro conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do primeiro conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v1[i]);
                }
                printf("Insira o número de elementos do segundo conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do segundo conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v2[i]);
                }
                int res = intersectSet(N, v1, v2, r);
                printf("Interseção dos dois conjuntos: ");
                for (int i = 0; i < N; i++) {
                    printf("%d ", r[i]);
                }
                printf("\n");
                break;
            }
            case 44: {
                int N;
                int v1[100], v2[100], r[100];
                printf("Insira o número de elementos do primeiro multi-conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do primeiro multi-conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v1[i]);
                }
                printf("Insira o número de elementos do segundo multi-conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do segundo multi-conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v2[i]);
                }
                int res = intersectMSet(N, v1, v2, r);
                printf("Interseção dos multi-conjuntos: ");
                for (int i = 0; i < N; i++) {
                    printf("%d ", r[i]);
                }
                printf("\n");
                break;
            }
            case 45: {
                int N;
                int v1[100], v2[100], r[100];
                printf("Insira o número de elementos do primeiro multi-conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do primeiro multi-conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v1[i]);
                }
                printf("Insira o número de elementos do segundo multi-conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do segundo multi-conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v2[i]);
                }
                int res = unionMSet(N, v1, v2, r);
                printf("União dos multi-conjuntos: ");
                for (int i = 0; i < N; i++) {
                    printf("%d ", r[i]);
                }
                printf("\n");
                break;
            }
            case 46: {
                int N;
                int v[100];
                printf("Insira o número de elementos do multi-conjunto: ");
                scanf("%d", &N);
                printf("Insira os elementos do multi-conjunto:\n");
                for (int i = 0; i < N; i++) {
                    scanf("%d", &v[i]);
                }
                int res = cardinalMSet(N, v);
                printf("A cardinalidade do multi-conjunto é: %d\n", res);
                break;
            }
            case 47: {
                Posicao inicial;
                Movimento mov[100];
                int N;
                printf("Insira a posição inicial (x y): ");
                scanf("%d %d", &inicial.x, &inicial.y);
                printf("Insira o número de movimentos: ");
                scanf("%d", &N);
                printf("Insira os movimentos (N, S, E, O):\n");
                for (int i = 0; i < N; i++) {
                    char m;
                    scanf(" %c", &m);
                    mov[i] = m == 'N' ? Norte : m == 'S' ? Sul : m == 'E' ? Este : Oeste;
                }
                Posicao res = posFinal(inicial, mov, N);
                printf("Posição final: (%d, %d)\n", res.x, res.y);
                break;
            }
            case 48: {
                Posicao inicial, final;
                Movimento mov[100];
                printf("Insira a posição inicial (x y): ");
                scanf("%d %d", &inicial.x, &inicial.y);
                printf("Insira a posição final (x y): ");
                scanf("%d %d", &final.x, &final.y);
                int res = caminho(inicial, final, mov, 100);
                if (res != -1) {
                    printf("Movimentos para alcançar a posição final: ");
                    for (int i = 0; i < res; i++) {
                        printf("%c ", mov[i] == Norte ? 'N' : mov[i] == Sul ? 'S' : mov[i] == Este ? 'E' : 'O');
                    }
                    printf("\n");
                } else {
                    printf("Impossível alcançar a posição final.\n");
                }
                break;
            }
            case 49: {
                Posicao pos[100];
                int N;
                printf("Insira o número de posições: ");
                scanf("%d", &N);
                printf("Insira as posições (x y): ");
                for (int i = 0; i < N; i++) {
                    scanf("%d %d", &pos[i].x, &pos[i].y);
                }
                int res = maisCentral(pos, N);
                printf("A posição mais central é: (%d, %d)\n", pos[res].x, pos[res].y);
                break;
            }
            case 50: {
                Posicao p, pos[100];
                int N;
                printf("Insira a posição (x y): ");
                scanf("%d %d", &p.x, &p.y);
                printf("Insira o número de posições: ");
                scanf("%d", &N);
                printf("Insira as posições (x y): ");
                for (int i = 0; i < N; i++) {
                    scanf("%d %d", &pos[i].x, &pos[i].y);
                }
                int res = vizinhos(p, pos, N);
                printf("Número de vizinhos adjacentes: %d\n", res);
                break;
            }
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while(opt != 0);
    return 0;
}

