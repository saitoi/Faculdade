#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int data;
    struct no *proximo;
    struct no *anterior;
} No;

void verificarNo(No *novoNo) {
    if (novoNo == NULL) {
        puts("Erro ao alocar memória");
        exit(1);
    }
}

void inserirInicio(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));
    
    verificarNo(novoNo);

    novoNo->data = data;
    novoNo->anterior = NULL;
    novoNo->proximo = cabeca;

    if(cabeca != NULL) cabeca->anterior = novoNo;
    cabeca = novoNo;
}

void inserirFim(No *cabeca, int data) {
    No *novoNo = (No *) malloc(sizeof(No));

    verificarNo(novoNo);

    novoNo->data = data;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (cabeca == NULL) cabeca = novoNo;
    else {
        while(cabeca->proximo != NULL)
            cabeca = cabeca->proximo;
        cabeca->proximo = novoNo;
        novoNo->anterior = cabeca;
    }
}

void removerInicio(No *cabeca) {
    if (cabeca == NULL) {
        puts("Lista vazia.");
        return;
    }
    No *auxiliar = cabeca;
    auxiliar = auxiliar->proximo;
    auxiliar->anterior = NULL;
    free(cabeca);
}

/*
void removerFim(No *cabeca) {
    if (cabeca == NULL) {
        puts("Lista vazia.");
        return;
    }
    while 
}
*/

void imprimirLista(No *cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
}

int main(void) {
    No *cabeca = NULL;

    inserirInicio(cabeca, 20);
    inserirInicio(cabeca, 10);

    imprimirLista(cabeca);
 return 0;
}

void limparBuffer() {
    char clear;
    while ((clear  = getchar()) != '\n' && clear != EOF);
}