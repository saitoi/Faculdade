#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 1000

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Struct para definição da pilha */
typedef struct pile {
    int data[MAX_TAM];
    int topo;
} Pile;

void init_pile(Pile *pilhas) {
    pilhas->topo = -1;
}

/* Verifica se a pilha está vazia */
int isEmtpy(Pile *pilhas) {
    return pilhas->topo == -1;
}

/* Verifica se a pilha está cheia */
int isFull(Pile *pilhas) {
    return pilhas->topo == MAX_TAM - 1;
}

/* Incrementa o topo e adiciona um valor à pilha */
void push(Pile *pilhas, int valor) {
    if (isFull(pilhas)) {
        puts("Erro ao adicionar valor à pilha, está cheia.");
        return;
    }
    pilhas->topo++;
    pilhas->data[pilhas->topo] = valor;
}

/* Decrementa o topo e remove um valor da pilha */
int pop(Pile *pilhas) {
    if (isEmtpy(pilhas)) {
        puts("Erro ao remover valor da pilha, está vazia.");
        return -1;
    }
    int valor = pilhas->topo;
    pilhas->topo--;
    return valor;
}

void seek(Pile *pilhas) {
    if (isEmtpy(pilhas)) {
        puts("Erro ao abrir pilha, está vazia.");
        return;
    }
    printf("O valor do topo da pilha é %d\n", pilhas->data[pilhas->topo]);
}

void print_pile(Pile *pilhas) {
    if (isEmtpy(pilhas)) {
        puts("Erro ao abrir pilha, está vazia.");
        return;
    }
    for (; pilhas->topo  >= 0; --(pilhas->topo)) {
        printf("Valor [%d] da pilha: %d\n", pilhas->topo, pilhas->data[pilhas->topo]);
    }
}

/* Função principal não recebe argumentos */
int main (void) {
    Pile pilhas;
    init_pile(&pilhas);

    push(&pilhas, 10);
    push(&pilhas, 20);
    push(&pilhas, 30);

    int removed = pop(&pilhas);
    printf("O valor removido foi %d\n", removed);
    printf("O valor do topo é %d\n", pilhas.topo);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
