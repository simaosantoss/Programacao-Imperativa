#include <stdio.h> 
#include <string.h> 


/*--------------------------------------- Ficha 4 ----------------------------------------*/

// Exercicio 1.1

int evogal (char c) {
    char *v = "aAeEiIoOuU";
    int i;
    for (i = 0 ; v[i] != '\0' && v[i] != c ; i++);
    return (v[i] != '\0');
}

int contavogais (char s[]) {
    int i , cont = 0;

    for (i = 0 ; s[i] != '\0' ; i++); {
        if (evogal (s[i]))
            cont++;
        i++;
    }

    return cont;
}

// Exercicio 1.2

int retiraVogaisRep (char *s) {
    int i , j , cont = 0;
    i = 0;
    j = 0;

    while (s[i] != '\0') {
        if (!(evogal (s[i]) && s[i] == s[i+1])) {
            s[j] = s[i]; j++; }
        else cont++;
        i++;
    }

    s[j] = '\0';
    return (s);
}

// Exercicio 2.1

int ordenado(int v[], int N) {
    int i;
    for (i = 0; i < N-1; i++)
        if (v[i] > v[i+1])
            return 0;
    return 1;
}


// Exercicio 2.2 

void merge (int a[], int na, int b[], int nb, int r[]) {
    int i , j , k;
    i = 0;
    j = 0;
    k = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            r[k] = a[i];
            i++;
        } 
        else {
            r[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < na) {
        r[k] = a[i];
        i++;
        k++;
    }

    while (j < nb) {
        r[k] = b[j];
        j++;
        k++;
    }
}

// Exercicio 2.3 

// com array auxiliar (1)

int partition1 (int v[], int N, int x) {
    int i , m , M;
    M = N - 1;
    int aux[N];
    
    while (i < N)
        if (v[i] <= x) aux[m++] = v[i++];
        else aux[M--] = v[i++];

    for (i = 0 ; i < N ; i++) v[i] = aux[i]; // ou 'memcpy (v , aux , n * sizeof(int))'
    return m;
}

// sem array auxiliar (2)

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition2(int v[], int N, int x) {
    int i, m;
    m = 0;

    for (i = 0; i < N; i++) {
        if (v[i] <= x) {
            swap(&v[i], &v[m]);
            m++;
        }
    }

    return m;
}

