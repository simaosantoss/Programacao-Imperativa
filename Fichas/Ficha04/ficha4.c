#include <stdio.h> 
#include <string.h> 


/*--------------------------------------- Ficha 4 ----------------------------------------*/

// Exercicio 1.1

int evogal(char c)
{
    char *v = "aAeEiIoOuU";

    for (int i = 0; v[i] != '\0'; i++)
        if (v[i] == c)
            return 1; // É vogal

    return 0; // Não é vogal
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

int retiraVogaisRep (char *s)
{
    int i = 0, j = 0, removidas = 0;

    for (i = 0; s[i] != '\0'; i++)
    {

        if (evogal(s[i]) && s[i] == s[i+1])
        {
            while (s[i] == s[i+1])
            {
                i++;
                removidas++;
            }
        }

        s[j] = s[i];
        j++;
    }

    s[j] = '\0';
    return removidas;
}

//Exercicio 1.3

int duplicaVogais (char *s)
{
    int len = strlen(s);
    int num_vogais = 0;

    for (int z = 0; z < len ; z++)
    {
        if (evogal(s[z]))
            num_vogais++;
    }

    int i = len - 1;              // Última posição do original
    int j = len + num_vogais - 1; // Última posição do novo tamanho

    while (i >= 0)
    {
        if (evogal(s[i]))
        {
            s[j--] = s[i];
            s[j--] = s[i--];
        }
        else
        {
            s[j--] = s[i];
        }
        i--;
    }

    return num_vogais;
}

// Exercicio 2.1

int ordenado (int v[], int N)
{
    int i = 0;

    for (i = 0; i < N-1; i++)
    {
        if (v[i] > v[i+1])
            return 0;
    }
    return 1;
}


// Exercicio 2.2 

void merge (int a[], int na, int b[], int nb, int r[])
{
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb)
    {
        if (a[i] <= b[j])
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }

    while (i < na)
        r[k++] = a[i++];

    while (j < nb)
        r[k++] = b[j++];
}

// Exercicio 2.3 

// com array auxiliar (1)

int partition1 (int v[], int N, int x)
{
    int i = 0, j = 0, count = 0;
    int aux[N];

    for (i = 0; i < N; i++)
    {
        if (v[i] <= x)
        {
            aux[j] = v[i];
            j++;
            count++;
        }
    }

    for (i = 0; i < N; i++)
    {
        if (v[i] > x)
        {
            aux[j] = v[i];
            j++;
        }
    }

    for (i = 0; i < N; i++)
    {
        v[i] = aux[i];
    }

    return count;
}

// sem array auxiliar (2)

void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition2(int v[], int N, int x) 
{
    int i, m = 0;

    for (i = 0; i < N; i++)
    {
        if (v[i] < x)
        {
            swap (&v[i], &v[m]);
            m++;
        }
    }

    return m;
}


