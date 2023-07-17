#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 0; i < n-1; ++i) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] < key) {
            arr[j+1] = arr[j];
            --j;            
        }
    arr[j+1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    int temp;
    for (i = 0; i < n - 1; ++i) {
        min_idx = i;
        for (j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void imprimir_vetor(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Função principal não recebe argumentos */
int main (void) {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    puts("Vetor original:");
    imprimir_vetor(arr, n);
    puts("Vetor ordenado:");
     insertion_sort(arr, n);
    imprimir_vetor(arr, n);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
