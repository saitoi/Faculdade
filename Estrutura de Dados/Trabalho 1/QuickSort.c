#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Chamada das funções */
void quickSort(int *vetor, int inicio, int fim);
int particionar(int *vetor, int inicio, int fim);
int escolherPivoAleatorio(int *vetor, int inicio, int fim);
int *overflow(int *vetor, int tamanho);
void imprimirVetor(int *vetor, int tamanho);
void trocar(int *a, int *b);
void limparBuffer(void);

/* Função principal sem argumentos */
int main(void) {

    /* Variáveis */
    int tamanho = 1;                         /* Inicializa o tamanho como 1 */
    int *vetor = (int*) malloc(sizeof(int)); /* Aloca uma posição para o vetor */
    int entrada = 0;                         /* Indica quantidade de valores lidos */

    while (!feof(stdin)) {
        int numero; 
        ++entrada;
        if (scanf("%d\n", &numero) < 1) {
            puts("Caractere invalido!");
            limparBuffer();
        } else {
            if (tamanho < entrada) {
                vetor = overflow(vetor, tamanho);
                vetor[entrada - 1] = numero;
                tamanho *= 2;
            } else {
                vetor[entrada - 1] = numero;
            } 
        }
    }


    quickSort(vetor, 0, entrada - 1);
    puts("");
    imprimirVetor(vetor, entrada);

    free(vetor);

    return 0;
}

int *overflow(int *vetor, int tamanho) {
    int *novoVetor = (int *) realloc(vetor, sizeof(int) * tamanho * 2);
    
    if (novoVetor == NULL) {
        puts("Falha ao alocar memória!");
        exit(1);
    } else return novoVetor;
}

int escolherPivoAleatorio(int *vetor, int inicio, int fim) {
    srand(time(NULL)); /* Inicialize a semente de números aleatórios */
    return inicio + rand() % (fim - inicio + 1);
}

int particionar(int *vetor, int inicio, int fim) {
    int indice_pivo = escolherPivoAleatorio(vetor, inicio, fim);
    int pivo = vetor[indice_pivo];
    trocar(&vetor[indice_pivo], &vetor[fim]); /* Move o pivô para o fim */
    int i = inicio - 1;
    int j;
    for (j = inicio; j < fim; j++) {
    if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[fim]); /* Retorna o pivô no lugar certo */
    return i + 1;
}

void quickSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, indice_pivo - 1);
        quickSort(vetor, indice_pivo + 1, fim);
    }
}

void imprimirVetor(int *vetor, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }
    puts("");
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void limparBuffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}