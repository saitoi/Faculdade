#include <stdio.h>

/* Chamando das funções */
void limpar_buffer(void);

void realocar(int *arr, int *tamanho) {
    int *aux = realloc(sizeof(int)*(*tamanho + 5));
    int i = 0;

    for (i = 0; i < *tamanho; i++) {
        aux[i] = arr[i];
    }

    free(arr);
    arr = aux;
    *tamanho += 5;
}

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *arr, int inicio, int fim) {
    int pivo = arr[fim];
    int i = inicio - 1;
    int j = inicio;
    int aux = 0;

    for (j = inicio; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[fim]);

    return i + 1;
}

/* Função principal sem argumentos */
int main (void) {
    int *arr = malloc(sizeof(int)*5);


 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
