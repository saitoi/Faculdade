#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
    int data;
    struct no *proximo;
} No;

typedef struct fila {
    No *cabeca;
    No *ultimo;
} Fila;

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória.");
        exit(1);
    }
}

Fila *inicializar(void) {
    Fila *filaNova = (Fila *) malloc(sizeof(Fila));
    verificar(filaNova);

    filaNova->cabeca = (No *) malloc(sizeof(No));
    verificar(filaNova->cabeca);
    
    filaNova->cabeca->proximo = NULL;
    filaNova->ultimo = filaNova->cabeca;
    return filaNova;
}

void pushFila(Fila *minhaFila, int data) {
    No *novoNo = (No *) malloc(sizeof(No));
    
    verificar(novoNo);

    novoNo->data = data;
    minhaFila->ultimo->proximo = novoNo;
    minhaFila->ultimo = novoNo;
}

int popFila(Fila *minhaFila) {
    No *primeiroNo = minhaFila->cabeca->proximo; 
    verificar(primeiroNo);

    int primeiroValor = primeiroNo->data;
    minhaFila->cabeca->proximo = primeiroNo->proximo;
    
    if (minhaFila->ultimo == primeiroNo)
        minhaFila->ultimo = minhaFila->cabeca;
    free(primeiroNo);
    return primeiroValor;
}

void imprimirFila(No *cabeca) {
    while(cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
    puts("");
}

int main (void) {
    Fila *minhaFila = inicializar();

    pushFila(minhaFila, 10);
    pushFila(minhaFila, 20);
    pushFila(minhaFila, 30);

    imprimirFila(minhaFila->cabeca->proximo);

    printf("Elemento removido: %d\n", popFila(minhaFila));
    printf("Elemento removido: %d\n", popFila(minhaFila));

    imprimirFila(minhaFila->cabeca->proximo);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
