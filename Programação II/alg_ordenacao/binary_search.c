#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Pesquisa binaria */
int PesquisaBinaria(int arr[], int left, int right, int valor) {
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (arr[mid] == valor)
            return mid;
        if (arr[mid] > valor)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int PesquisaBinaria_recursiva(int arr[], int left, int right, int valor) {
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (arr[mid] == valor)
            return mid;
        if (arr[mid] > valor)
            PesquisaBinaria_recursiva(arr, left, mid - 1, valor);
        else
            PesquisaBinaria_recursiva(arr, mid + 1, right, valor);
    }
    return -1;
}

/* Função principal não recebe argumentos */
int main (void) {
    // Lista ordenada
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int valor;

    printf("Escolha um valor entre 1 - 5: ");
    scanf("%d", &valor);

    int indice = PesquisaBinaria(arr, 0, n - 1, valor);
    if (indice == -1)
        printf("O valor escolhido não está na lista.\n");
    else
        printf("O valor selecionado está na posição: %d\n", indice);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
