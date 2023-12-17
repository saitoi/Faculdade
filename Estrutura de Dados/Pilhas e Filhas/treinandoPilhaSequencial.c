#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);

typedef struct no {
    int data;
    struct no *proximo;
} No;

typedef struct pilha {
    No *cabeca;
} Pilha;

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória.");
        exit(1);
    }
}

Pilha *inicializar(void) {
    Pilha *PilhaNova = (Pilha *) malloc(sizeof(Pilha));
    verificar(PilhaNova);

    PilhaNova->cabeca = (No *) malloc(sizeof(No));
    verificar(PilhaNova->cabeca);
    
    PilhaNova->cabeca->proximo = NULL;
    return PilhaNova;
}

// Modificação: Insere no início
void pushPilha(Pilha *minhaPilha, int data) {
    No *novoNo = (No *) malloc(sizeof(No));    
    verificar(novoNo);

    novoNo->data = data;
    novoNo->proximo = minhaPilha->cabeca->proximo;
    minhaPilha->cabeca->proximo = novoNo;
}

int popPilha(Pilha *minhaPilha) {
    No *primeiroNo = minhaPilha->cabeca->proximo; 
    verificar(primeiroNo);

    int primeiroValor = primeiroNo->data;
    minhaPilha->cabeca->proximo = primeiroNo->proximo;
    
    free(primeiroNo);
    return primeiroValor;
}

void imprimirPilha(No *cabeca) {
    while(cabeca != NULL) {
        printf("%d ", cabeca->data);
        cabeca = cabeca->proximo;
    }
    puts("");
}

int main (void) {
    Pilha *minhaPilha = inicializar();

    pushPilha(minhaPilha, 10);
    pushPilha(minhaPilha, 20);
    pushPilha(minhaPilha, 30);

    imprimirPilha(minhaPilha->cabeca->proximo);

    printf("Elemento removido: %d\n", popPilha(minhaPilha));
    printf("Elemento removido: %d\n", popPilha(minhaPilha));

    imprimirPilha(minhaPilha->cabeca->proximo);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
