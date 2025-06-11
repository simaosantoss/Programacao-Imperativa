#include <stdio.h> 
#include <string.h> 

// iSort (dá mais pontos que um buble sort mas menos que um merge sort ou quick sort)

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) { // // Adaptar o campo (ex: c[j].sup > chave.sup pu qualquer coisa que se queira ordenar).
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

// Quick Sort a mais fácil de decorar entre merge e quick (dão os mesmos pontos)

typedef struct {
    int inf,sup;
} Intervalo; // adaptada a este tipo

// --- Função de PARTIÇÃO (única parte crítica a decorar) ---
int partition(Intervalo arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].inf;  // Pivô do meio (evita pior caso)
    // ATENÇÃO: Mudar ".inf" para o campo que se quer ordenar (ex: ".sup", ".idade", etc.)
    
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do { i++; } while (arr[i].inf < pivot);  // Comparação: trocar "<" para ">" se quiser decrescente
        do { j--; } while (arr[j].inf > pivot);  // Igual aqui
        
        if (i >= j) return j;  // Ponto de divisão do array
        
        swap(&arr[i], &arr[j]);  // Troca os elementos fora de ordem
    }
}

// --- QuickSort (recursivo) ---
void quickSort(Intervalo arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Obtém o pivô
        quickSort(arr, low, p);      // Ordena a metade esquerda
        quickSort(arr, p + 1, high); // Ordena a metade direita
    }
}

// --- Função de ordenação final (chama o QuickSort) ---
void ordena(Intervalo arr[], int N) {
    quickSort(arr, 0, N - 1);  // Inicia a ordenação
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