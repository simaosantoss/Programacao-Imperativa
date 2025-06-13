#include <stdio.h> 
#include <string.h> 

// É necessário saber percorrer listas ligadas bem como adicionar ou retirar nós
// É necessário saber percorrer árvores e usar recursividade

/*---------------------------------------------------------------------------------*/
// Algoritmos que dão jeito saber nos testes 

// iSort (dá mais pontos que um buble sort mas menos que um merge sort ou quick sort)

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) { // // Adaptar o campo (ex: c[j].oqueeuquiser > chave.oqueeuquiser)
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// swap (util para trocar posições de elementos em arrays)

void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Quick Sort a mais fácil de perceber entre merge e quick (dão os mesmos pontos) -> a minha preferida é esta

typedef struct {
    int naoImporta, oquequeroordernar;
} Ordena;

void swap (Ordena *a, Ordena *b) {
    Ordena tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (Ordena arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].oquequeroordernar;

    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {i++;} while (arr[i].oquequeroordernar < pivot);
        do {j--;} while (arr[j].oquequeroordernar > pivot);

        if (i >= j) return j;

        swap (&arr[i], &arr[j]);
    }
}

void quickSort (Ordena arr[], int low, int high) {
    if (low < high) {
    int p = partition (arr, low, high);
    quickSort (arr, low, p);
    quickSort (arr, p + 1, high);
    }
}

void ordena (Ordena arr[], int N) {
    quickSort (arr, 0, N - 1);
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
