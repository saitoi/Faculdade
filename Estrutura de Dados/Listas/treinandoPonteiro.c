#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
    int data;
    struct no* proximo;
    struct no* anterior;
} No;

No *criarNo(int data) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirOrdenado(No **primeiroNo, int data) {
    No *novoNo = criarNo(data);
    if (*primeiroNo == NULL) {
        *primeiroNo = novoNo;
        return;
    }

    No *noAtual = *primeiroNo;
    while (noAtual != NULL && data > noAtual->data)
        noAtual = noAtual->proximo;
    if (noAtual == NULL) {
        puts("oi");
        No *noUltimo = *primeiroNo;
        while (noUltimo->proximo != NULL)
            noUltimo = noUltimo->proximo;
        novoNo->proximo = NULL;
        novoNo->anterior = noUltimo;
        noUltimo->proximo = novoNo;
    } else if (noAtual == *primeiroNo) {
        puts("entrei");
        novoNo->proximo = *primeiroNo;
        (*primeiroNo)->anterior = novoNo;
        *primeiroNo = novoNo;
    } else {
        novoNo->proximo = noAtual;
        novoNo->anterior = noAtual->anterior;
        noAtual->anterior->proximo = novoNo;
        noAtual->anterior = novoNo;
    }
}

void removerOrdenado(No *primeiroNo, int data) {
    if (primeiroNo == NULL) {
        puts("Lista vazia");
        return;
    }
    No *noAtual = primeiroNo;
    while (noAtual != NULL && data > noAtual->data)
        noAtual = noAtual->proximo;
    

}

void imprimirLista(No *primeiroNo) {
    while (primeiroNo != NULL) {
        printf("%d ", primeiroNo->data);
        primeiroNo = primeiroNo->proximo;
    }
}

int main (void) {
    No *primeiroNo = NULL;

    inserirOrdenado(&primeiroNo, 30);
    inserirOrdenado(&primeiroNo, 20);
    inserirOrdenado(&primeiroNo, 10);
    inserirOrdenado(&primeiroNo, 50);
    inserirOrdenado(&primeiroNo, 15);

    imprimirLista(primeiroNo);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
