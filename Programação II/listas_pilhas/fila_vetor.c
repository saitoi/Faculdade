#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 1000

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Struct base para a fila */
typedef struct fila {
    int frente;
    int tras;
    int data[MAX_TAM];
} Fila;

/* Função para inicializar a fila */
void initialize (Fila *fila1) {
    fila1->frente = -1;
    fila1->tras = -1;
}

/* Verificação se a fila está vazia */
int isEmtpy (Fila fila1) {
    return (fila1.frente == -1 && fila1.tras == -1);
}

/* Verificação se a fila está lotada */
int isFull (Fila fila1) {
    return (fila1.tras == (MAX_TAM - 1));
}

void enqueue(Fila *fila1, int data) {
    if (isFull(*fila1)) {
        printf("A fila está cheia, não é possível adicionar nenhum elemento.\n");
        exit(1);
    }

    if(isEmtpy(*fila1)) {
        fila1->frente = 0;
        fila1->tras = 0;
    } else {
        ++(fila1->tras);
    }

    fila1->data[fila1->tras] = data;
    printf("%d foi enfileirado com sucesso.\n", data);
}

void dequeue(Fila *fila1) {
    if (isEmtpy(*fila1)) {
        printf("A fila está vazia, não é possível remover nenhum elemento.\n");
        exit(1);
    }

    int removido = fila1->data[fila1->frente];
    ++(fila1->frente);
    printf("O valor removido foi %d.\n", removido);
}

void imprimir_fila(Fila fila1) {
    if (isEmtpy(fila1)) {
        puts("A fila está vazia, não é possível imprimir ela.\n");
        exit(1);
    }
    puts("Impressão na ordem: Frente -> Trás.\n");
    for (int i = fila1.frente; i <= fila1.tras ; ++i) {
        printf("Elemento %d: %d\n", i, fila1.data[i]);
    }
}

/* Função principal não recebe argumentos */
int main (void) {
    Fila fila1;

    initialize(&fila1);
    enqueue(&fila1, 10);
    enqueue(&fila1, 20);
    enqueue(&fila1, 30);

    printf("O primeiro valor da fila é o %d.\n", fila1.data[fila1.frente]);
    dequeue(&fila1);
    dequeue(&fila1);
    printf("O novo primeiro elemento da fila é o %d.\n", fila1.data[fila1.frente]);
    printf("O elemento de trás da fila é o %d.\n", fila1.data[fila1.tras]);
    imprimir_fila(fila1);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
