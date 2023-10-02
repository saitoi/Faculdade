#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
    int data;
    struct no *proximo;
} No;

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória");
        exit(1);
    }
}

No *inicializar(void) {
    No *novoNo = (No *) malloc(sizeof(No));
    verificar(novoNo);

    novoNo->data = 0;
    novoNo->proximo = novoNo;
    return novoNo;
}

void inserirInicio(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));
    verificar(novoNo);

    novoNo->data = data;
    novoNo->proximo = cabeca->proximo;
    cabeca->proximo = novoNo;
}

void inserirFim(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));
    verificar(novoNo);

    novoNo->data = data;
    novoNo->proximo = cabeca;

    No *ultimoNo = cabeca->proximo;
    while(ultimoNo->proximo != cabeca) ultimoNo = ultimoNo->proximo;
    ultimoNo->proximo = novoNo;
}

void removerInicio(No *cabeca, int data) {
    if (cabeca->proximo == cabeca) {
        puts("Lista vazia.");
        return;
    }
    No *primeiroNo = cabeca->proximo;
    cabeca->proximo = primeiroNo->proximo;
    free(primeiroNo);
}

void removerFinal(No *cabeca) {
    if (cabeca->proximo == cabeca) {
        puts("Lista vazia.");
        return;
    }
    No *ultimoNo = cabeca;
    while(ultimoNo->proximo->proximo != cabeca)
        ultimoNo = ultimoNo->proximo;
    free(ultimoNo->proximo);
    ultimoNo->proximo = cabeca;
}

void imprimirLista(No *cabeca) {
    No *primeiroNo = cabeca->proximo;
    while(primeiroNo != cabeca) {
        printf("%d ", primeiroNo->data);
        primeiroNo = primeiroNo->proximo;
    }
    puts("");
}

int main (void) {
    No *cabeca = inicializar();

    inserirInicio(cabeca, 10);
    inserirInicio(cabeca, 20);

    imprimirLista(cabeca);

    inserirFim(cabeca, 70);
    inserirFim(cabeca, 80);
    removerFinal(cabeca);

    imprimirLista(cabeca);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
