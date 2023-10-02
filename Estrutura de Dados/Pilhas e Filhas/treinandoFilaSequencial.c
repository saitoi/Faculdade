#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void limpar_buffer(void);

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória.");
        exit(1);
    }
}

typedef struct fila {
    unsigned inicio,
             fim,
             usado;
    int *dados;
} Fila;

Fila inicializar() {
    Fila minhaFila;
    minhaFila.inicio = 0;
    minhaFila.fim = 0;
    minhaFila.usado = 0;
    minhaFila.dados = (int *) malloc(sizeof(int)*TAM);
    verificar(minhaFila.dados);

    return minhaFila;
}

int buscar(Fila *minhaFila, int data) {
    if (minhaFila->usado == 0) {
        puts("Fila vazia.");
        return -1;
    }
    int i = minhaFila->inicio;
    int elementosRestantes = minhaFila->usado;
    
    while (elementosRestantes > 0) {
        if (minhaFila->dados[i] == data) {
            return i;
        }
        i = (i + 1) % TAM;
        elementosRestantes--;
    }
    return -1;
}

void adicionarPosicao(Fila *minhaFila, int data, int posicao) {
    if (minhaFila->usado == 10)
        overflow(minhaFila);
    int i = minhaFila->fim;
    int elementosRestantes = minhaFila->usado;
    while (elementosRestantes > posicao) {
        minhaFila->dados[i] = minhaFila->dados[i - 1];
        i = (i - 1) % TAM;
        elementosRestantes--;
    }
    minhaFila->dados[i] = data;
    minhaFila->fim = ++(minhaFila->fim) % 10;
    (minhaFila->usado)++;
}

void overflow(Fila *minhaFila) {
    minhaFila->dados = (int *) realloc(minhaFila->dados, sizeof(int)*(minhaFila->usado)*2);
    verificar(minhaFila->dados);
}

void pushFila(Fila *minhaFila, int data) {
    if (minhaFila->usado == 10)
        overflow(minhaFila);
    minhaFila->dados[minhaFila->fim] = data;
    minhaFila->fim = ++(minhaFila->fim) % 10;
    (minhaFila->usado)++;
}

void popFila(Fila *minhaFila) {
    if (minhaFila->usado == 0) {
        puts("Lista vazia.");
        exit(1);
    }
    printf("Valor removido: %d\n", minhaFila->dados[minhaFila->inicio]);
    minhaFila->dados[minhaFila->inicio] = 0;
    minhaFila->inicio = ++(minhaFila->inicio) % 10;
    (minhaFila->usado)--;
}

void imprimirFila(Fila *minhaFila) {
    if (minhaFila->usado == 0) {
        puts("Fila vazia.");
        return;
    }
    int i = minhaFila->inicio;
    int elementosRestantes = minhaFila->usado;
    
    while (elementosRestantes > 0) {
        printf("%d ", minhaFila->dados[i]);
        i = (i + 1) % TAM;
        elementosRestantes--;
    }
    printf("\n");
}

void imprimirCorreto(Fila *minhaFila) {
    if (minhaFila->usado == 0) {
        puts("Fila vazia.");
        return;
    }
    for (int i = minhaFila->inicio; i < minhaFila->fim; ++i) {
        printf("%d ", minhaFila->dados[i]);
    }
    puts("");
}

int main (void) {
    Fila minhaFila = inicializar();

    pushFila(&minhaFila, 10);
    pushFila(&minhaFila, 20);
    pushFila(&minhaFila, 30);

    imprimirCorreto(&minhaFila);

    popFila(&minhaFila);

    imprimirCorreto(&minhaFila);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
