#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < tamanho; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&(arr[i]), &(arr[minIdx]));
    }
}

void bubbleSort(int *arr, int tamanho) {
    for (int i = 0; i < tamanho-1; ++i)   
        for (int j = 0; j < tamanho-i-1; ++j)
            if (arr[j] > arr[j+1])
                swap(&(arr[j]), &(arr[j+1]));
}

void insertionSort(int *arr, int tamanho) {
    for (int i = 1; i < tamanho; ++i) {
        int chave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = chave;
    }
}

void selectionSort2(int arr[], int n) {
	for (int i = 0; i < n-1; ++i)
		for (int j = i+1; j < n; ++j)
			if (arr[j] < arr[i])
				swap(&(arr[i]), &(arr[j]));
}

void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main (void) {
    int arr[] = {5, 4, 3, 2, 1};

    selectionSort2(arr, (int) sizeof(arr)/sizeof(int));
    imprimirVetor(arr, (int) sizeof(arr)/sizeof(int));

 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
