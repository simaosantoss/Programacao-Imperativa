#include <stdio.h> 
#include <string.h> 

// mergeSort (sort que dá mais cotação num teste)

void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + 1];
    }
    for (j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0; 
    k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else 
        {
        arr[k] = rightArr[j];
        j++;
        }
    }

    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (i < n2) 
    {
        arr[k] = leftArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left - (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// swap (util para trocar posições de elementos em arrays)

void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// binarySearch (procura eficiente num array)

int binarySearch(int array[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (array[meio] == valor) {
            return meio; // Valor encontrado
        }
        else if (array[meio] < valor) {
            inicio = meio + 1; // Procurar na metade direita
        }
        else {
            fim = meio - 1; // Procurar na metade esquerda
        }
    }

    return -1; // Valor não encontrado
}