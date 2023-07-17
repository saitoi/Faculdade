#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // Imprimir vetor ordenado
    printf("Vetor ordenado por bubble sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

/* Bubble sort recursivo */
void bubbleSortRecursive(int arr[], int size) {
    if (size <= 1)
        return;

    int i;
    int swapped = 0;

    for (i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swapped = 1;
        }
    }

    if (swapped)
        bubbleSortRecursive(arr, size - 1);
}

/* Insertion sort */
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos maiores que a chave para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }   // Termino do algoritmo

    // Imprimir vetor ordenado
    printf("Vetor ordenado por insertion sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca os elementos
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    // Imprimir vetor ordenado
    printf("Vetor ordenado por selection sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

/* Função principal não recebe argumentos */
int main(void) {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int opcao = 0;

    printf("Escolha o algoritmo de ordenação:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Sair\n");
    

    while (1) {
        printf("\nSelecione uma opção: ");
        scanf("%d", &opcao);
        clean_buf();
        switch (opcao) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                break;
            case 4:
                mergeSort(arr, n);
                printf("Vetor ordenado por Merge Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
    return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
