#include <stdio.h>
#include <stdlib.h>

/* Chamando das funções */
void limpar_buffer(void);

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inicializarLista(No *cabeca) {
    cabeca = (No *) malloc(sizeof(No));
    (cabeca)->prox = NULL;
}

void inserirInicio(No **cabeca, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = (*cabeca)->prox;
    (*cabeca)->prox = novo;
}

void inserirFim(No *cabeca, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    No *aux = cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

void removerFim(No *cabeca) {
    No *aux = cabeca;
    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
}

void removerInicio(No *cabeca) {
    No *aux = (cabeca)->prox;
    (cabeca)->prox = aux->prox;
    free(aux);
}

void removerValor(No *cabeca, int valor) {
    No *aux = cabeca;
    while (aux->prox != NULL && aux->prox->valor != valor) {
        aux = aux->prox;
    }
    if (aux->prox != NULL) {
        No *remover = aux->prox;
        aux->prox = remover->prox;
        free(remover);
    }
}

void imprimirLista(No *lista) {
    No *aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

/* Função principal sem argumentos */
int main (void) {
    No *cabeca = (No *) malloc(sizeof(No));
    cabeca->prox = NULL;

    inserirInicio(&cabeca, 1);
    inserirFim(cabeca, 2);
    inserirFim(cabeca, 3);
    removerFim(cabeca);
    printf("Conteúdo do cabeca->prox: %d\n", cabeca->prox->valor);
    inserirFim(cabeca, 10);
    inserirFim(cabeca, 20);
    imprimirLista(cabeca->prox);

 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
