#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Bubble Sort simples */
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; ++i)
        for (j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

}

/* Bubble sort recursivo */
void bubble_sort_recursivo(int arr[], int n) {
    if (n <= 1) {
        return;
    }
    
    int i, swapped = 0, temp;

    for (i = 0; i < n-1; ++i) {
        if (arr[i] > arr[i+1]) {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            swapped = 1;
        }
    }
    if (swapped)
        bubble_sort_recursivo(arr, n-1);
}

/* Insertion Sort simples */
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n-1; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

/* Imprimir vetor ordenado */
void imprimir_vetor(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge_sort() {

}

void merge() {

}

/* Função principal não recebe argumentos */
int main (void) {
    int arr[] = {5, 4, 3, 2, 1};
    int valor;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("O vetor desordenado é: ");
    imprimir_vetor(arr, n);
    bubble_sort_recursivo(arr, n);
    printf("O vetor ordenado é: ");
    imprimir_vetor(arr, n);    


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
