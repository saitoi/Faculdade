#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
   int data;
   struct no *anterior;
   struct no *proximo;
} No;

typedef struct lista {
   No *cabeca;
   No *fim;
} Lista;

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória");
        exit(1);
    }
}

No *criarNo(int data) {
    No *novoNo = (No *) malloc(sizeof(No));
    verificar(novoNo);
    novoNo->data = data;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
 return novoNo;
}

Lista *inicializar() {
    Lista *novaLista = (Lista *) malloc(sizeof(Lista));
    verificar(novaLista);
    
    novaLista->cabeca = criarNo(-1);
    novaLista->fim = novaLista->cabeca;
 return novaLista;
}

void inserirInicio(Lista *minhaLista, int data) {
    No *novoNo = criarNo(data);
    novoNo->proximo = minhaLista->cabeca->proximo;
    novoNo->anterior = minhaLista->cabeca;
    if (minhaLista->cabeca->proximo != NULL) {
        minhaLista->cabeca->proximo->anterior = novoNo;
    } else minhaLista->fim = novoNo;
    minhaLista->cabeca->proximo = novoNo;
}

// Precisa mudar
void removerInicio(Lista *minhaLista) {
    if (minhaLista->cabeca == minhaLista->fim) {
        puts("Lista vazia..");
        return;
    }
    No *auxiliar = minhaLista->cabeca->proximo;
    minhaLista->cabeca->proximo = auxiliar->proximo;
    free(auxiliar);
    if (minhaLista->cabeca->proximo != NULL)
        minhaLista->cabeca->proximo->anterior = minhaLista->cabeca;
}

void removerFim(Lista *minhaLista) {
    if (minhaLista->cabeca == minhaLista->fim) {
        puts("Lista vazia..");
        return;
    }
    No *auxiliar = minhaLista->fim;
    minhaLista->fim->anterior->proximo = NULL;
    minhaLista->fim = minhaLista->fim->anterior;
    free(auxiliar);
}

// Continuar..
/*
void insereOrdenado(Lista *minhaLista, int data) {
    No *novoNo = criarNo(data);
    No *noAtual = minhaLista->cabeca;
    while (noAtual != NULL && data > noAtual->data) {
        noAtual = noAtual->proximo;
    }
    if (noAtual == NULL) {
        No *ultimo = noAtual
    }
}
*/


void imprimir(No *primeiro) {
    while (primeiro != NULL) {
        printf("%d ", primeiro->data);
        primeiro = primeiro->proximo;
    }
}

int main (void) {
    Lista *minhaLista = inicializar();

    inserirInicio(minhaLista, 30);
    //inserirInicio(minhaLista, 20);
    //inserirInicio(minhaLista, 10);
    removerInicio(minhaLista);

    imprimir(minhaLista->cabeca->proximo);

 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
 