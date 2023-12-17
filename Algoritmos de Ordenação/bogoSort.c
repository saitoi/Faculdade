#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para verificar se o array está ordenado
int estaOrdenado(int array[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (array[i - 1] > array[i]) {
            return 0;
        }
    }
    return 1;
}

// Função para embaralhar o array aleatoriamente
void embaralharArray(int array[], int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Função de ordenação Bogo Sort
void bogoSort(int array[], int tamanho) {
    while (!estaOrdenado(array, tamanho)) {
        embaralharArray(array, tamanho);
    }
}

int main() {
    int array[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    bogoSort(array, tamanho);

    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
