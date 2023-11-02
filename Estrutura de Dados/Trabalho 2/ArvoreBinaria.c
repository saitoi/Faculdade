/*
Nome: Pedro Henrique Honorio Saito
DRE: 122149392
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 100

typedef struct no {
    int chave;
    struct no *esquerda;
    struct no *direita;
} No;

typedef struct nofila {
    No *noArvore;
    struct nofila *proximo;
} NoFila;

typedef struct fila {
    NoFila *inicio;
    NoFila *final;
} Fila;

No *criarNo(int chave);
void inserirNo(No **raiz, int valor);
void emNivel(Fila *minhaFila, No *raiz);
void insereFila(Fila *minhaFila, No *raiz);
No *tiraFila(Fila *minhaFila);

int main(void) {
    No *raiz = NULL;
    Fila minhaFila;
    minhaFila.inicio = minhaFila.final = NULL;

    char comando[100];

    while (fgets(comando, sizeof(comando), stdin) != NULL) {
        switch (comando[0]) {
            case 'i':
                inserirNo(&raiz, atoi(comando + 1));
                break;
            case 'p':
                emNivel(&minhaFila, raiz);
                break;
            default:
                printf("Comando inválido\n");
        }
    }

    return 0;
}

No *criarNo(int chave) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserirNo(No **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return;
    }
    if (valor < (*raiz)->chave)
        inserirNo(&(*raiz)->esquerda, valor);
    else if (valor > (*raiz)->chave)
        inserirNo(&(*raiz)->direita, valor);
    else
        printf("Valor já consta\n");
}

void insereFila(Fila *minhaFila, No *raiz) {
    NoFila *novoNoFila = (NoFila *)malloc(sizeof(NoFila));
    if (novoNoFila == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novoNoFila->noArvore = raiz;
    novoNoFila->proximo = NULL;
    
    if (minhaFila->inicio == NULL) {
        minhaFila->inicio = minhaFila->final = novoNoFila;
    } else {
        minhaFila->final->proximo = novoNoFila;
        minhaFila->final = novoNoFila;
    }
}

No *tiraFila(Fila *minhaFila) {
    if (minhaFila->inicio == NULL) {
        return NULL;
    }
    NoFila *temp = minhaFila->inicio;
    minhaFila->inicio = minhaFila->inicio->proximo;
    No *raiz = temp->noArvore;
    free(temp);
    return raiz;
}

void emNivel(Fila *minhaFila, No *raiz) {
    if (raiz != NULL)
        insereFila(minhaFila, raiz);
    while (minhaFila->inicio != NULL) {
        No *ponteiro = tiraFila(minhaFila);
        printf("%d ", ponteiro->chave);
        if (ponteiro->esquerda != NULL)
            insereFila(minhaFila, ponteiro->esquerda);
        if (ponteiro->direita != NULL)
            insereFila(minhaFila, ponteiro->direita);
    }
}
