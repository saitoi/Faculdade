#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void limpar_buffer(void);

typedef struct fila {
    unsigned inicio,
             fim,
             usado,
             tam;
    int *dados;
} Fila;

void verificar(void *estrutura) {
    if (estrutura == NULL) {
        puts("Erro ao alocar memória.");
        exit(1);
    }
}

void overflow(Fila *minhaFila) {
    minhaFila->tam *= 2;
    int *temp = (int  *) realloc(minhaFila->dados, sizeof(Fila)*minhaFila->tam);
    verificar(temp);
    minhaFila->dados = temp;
}

Fila inicializar(void) {
    Fila *novaFila = (Fila *) malloc(sizeof(novaFila));
    verificar(novaFila);
    novaFila->dados = (int *) malloc(sizeof(int)*TAM);
    verificar(novaFila->dados);
    novaFila->inicio = 0;
    novaFila->fim = 0;
    novaFila->tam = TAM;
    novaFila->usado = 0;
    return *novaFila;
}

void inserirFila(Fila *minhaFila, int data) {
    if (minhaFila->usado == minhaFila->tam)
        overflow(minhaFila);
    minhaFila->dados[minhaFila->fim] = data;
    (minhaFila->fim) = (++minhaFila->fim) % minhaFila->tam;
    (minhaFila->usado)++;
}

void inserirInicio(Fila *minhaFila, int data) {
    if (minhaFila->usado == minhaFila->tam) 
        overflow(minhaFila);
    for (int i = minhaFila->fim; (i % minhaFila->tam) > minhaFila->inicio; i = abs(--i))
        minhaFila->dados[i] = minhaFila->dados[i-1];
    minhaFila->dados[minhaFila->inicio] = data;
    (minhaFila->usado)++;
    (minhaFila->fim)++;
}

int removerFila(Fila *minhaFila) {
    if (minhaFila->usado == 0) {
        puts("Fila vazia..");
        return -1;
    }
    int removido = minhaFila->dados[minhaFila->inicio];
    minhaFila->inicio = ++(minhaFila->inicio) % minhaFila->tam;
    (minhaFila->usado)--;
    return removido;
}

int removerFim(Fila *minhaFila) {
    if (minhaFila->usado == 0) {
        puts("Fila vazia..");
        return -1;
    }
    minhaFila->fim = (minhaFila->fim - 1 + minhaFila->tam) % minhaFila->tam;
    int removido = minhaFila->dados[minhaFila->fim];
    (minhaFila->usado)--;
    return removido;
}

void imprimir(Fila minhaFila) {
    for (int i = minhaFila.inicio; (i % minhaFila.tam) < minhaFila.fim; ++i)
        printf("%d ", minhaFila.dados[i]);
}

int main (void) {
    Fila minhaFila = inicializar();

    inserirFila(&minhaFila, 10);
    inserirFila(&minhaFila, 20);
    inserirFila(&minhaFila, -90);
    inserirInicio(&minhaFila, 30);
    inserirInicio(&minhaFila, 50);
    printf("Valor removido: %d\n", removerFila(&minhaFila));
    printf("Valor do fim removido: %d\n", removerFim(&minhaFila));

    imprimir(minhaFila);
 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
