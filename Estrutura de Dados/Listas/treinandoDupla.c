#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
    int data;
    struct no *anterior;
    struct no *proximo;
} No;

No *inicializar(void) {
    No *novoNo = (No *) malloc(sizeof(No));
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    novoNo->data = -1;
    return novoNo;
}

void inserirInicio(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));

    if (novoNo == NULL) {
        puts("Erro ao alocar memória.");
        return;
    }

    novoNo->data = data;
    novoNo->anterior = cabeca;
    novoNo->proximo = cabeca->proximo;

    if (cabeca->proximo != NULL) cabeca->proximo->anterior = novoNo;
    cabeca->proximo = novoNo;
}

void inserirFim(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));

    if (novoNo == NULL) {
        puts("Erro ao alocar memória.");
        return;
    }

    novoNo->data = data;
    novoNo->proximo = NULL;
    while (cabeca->proximo != NULL) {
        cabeca = cabeca->proximo;
    }
    cabeca->proximo = novoNo;
    novoNo->anterior = cabeca;
}

void removerInicio(No *cabeca) {
    if (cabeca->proximo == NULL) {
        puts("Lista vazia.");
        return;
    }
    No *auxiliar = cabeca->proximo;
    cabeca->proximo = auxiliar->proximo;
    if (auxiliar->proximo != NULL) auxiliar->proximo->anterior = cabeca;
    free(auxiliar);
}

void removerFim(No *cabeca) {
    if (cabeca->proximo == NULL) {
        puts("Lista vazia.");
        return;
    }
    while (cabeca->proximo->proximo != NULL) cabeca = cabeca->proximo;
    free(cabeca->proximo);
    cabeca->proximo = NULL;
}

void imprimirLista(No *cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
}

/* Função principal sem argumentos */
int main (void) {
    No *cabeca = inicializar();

    inserirInicio(cabeca, 20);
    inserirInicio(cabeca, 10);
    inserirFim(cabeca, 30);
    inserirInicio(cabeca, 40);
    removerInicio(cabeca);
    //removerFim(cabeca); 

    imprimirLista(cabeca->proximo);
 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
