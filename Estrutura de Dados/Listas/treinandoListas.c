#include <stdio.h>
#include <stdlib.h>

/* Chamando das funções */
void limpar_buffer(void);

typedef struct no {
    int data;
    struct no *proximo;
} No;

void inicializar(No **cabeca) {
    *cabeca = (No*) malloc(sizeof(No));
    (*cabeca)->proximo = NULL;
}

void inserirInicio(No *cabeca, int data) {
    No *novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {
        puts("Erro ao alocar memória.");
        return;
    }

    novoNo->data = data;
    novoNo->proximo = cabeca->proximo;
    cabeca->proximo = novoNo;
}

void inserirFim(No *cabeca, int data) {
    No *novoNo = (No*) malloc(sizeof(No*));

    if (novoNo == NULL) {
        puts("Erro ao alocar memória.");
        return;
    }

    novoNo->proximo = NULL;
    novoNo->data = data;

    No *auxiliar = cabeca;
    while(auxiliar->proximo != NULL) {
        auxiliar = auxiliar->proximo;
    }
    auxiliar->proximo = novoNo;
}

void removerInicio(No *cabeca) {
    if (cabeca->proximo == NULL) {
        puts("Lista vazia.");
        return;
    }
    No *auxiliar = cabeca->proximo;
    cabeca->proximo = auxiliar->proximo;
    free(auxiliar);
}

void removerFim(No *cabeca) {
    if (cabeca->proximo == NULL) {
        puts("Lista vazia.");
        return;
    }
    while (cabeca->proximo->proximo != NULL) {
        cabeca = cabeca->proximo;
    }
    free(cabeca->proximo);
    cabeca->proximo = NULL;
}


void imprimirLista(No *cabeca) {
    No *auxiliar = cabeca;
    while(auxiliar != NULL) {
        printf("%d ", auxiliar->data);
        auxiliar = auxiliar->proximo;
    }
}

/* Função principal sem argumentos */
int main (void) {
    No *cabeca = NULL;
    inicializar(&cabeca);

    removerInicio(cabeca);
    inserirInicio(cabeca, 20);
    inserirInicio(cabeca, 10);
    inserirFim(cabeca, 30);
    removerFim(cabeca);
    inserirInicio(cabeca, 90);
    inserirFim(cabeca, 40);
    

    imprimirLista(cabeca);
 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
