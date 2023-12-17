#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_INICIAL 15

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} MeuVetor;

typedef struct {
    int primeiro;
    int segundo;
} Par;

typedef struct {
    int primeiro;
    int segundo;
    int terceiro;
} Tripla;

void inicializarVetor(MeuVetor* vec, int capacidade) {
    vec->tamanho = 0;
    vec->capacidade = capacidade;
    vec->elementos = (int*)malloc(capacidade * sizeof(int));
}

void liberarVetor(MeuVetor* vec) {
    free(vec->elementos);
    vec->elementos = NULL;
    vec->tamanho = 0;
    vec->capacidade = 0;
}

void adicionarElemento(MeuVetor* vec, int x) {
    if (vec->tamanho == vec->capacidade) {
        vec->capacidade *= 2;
        vec->elementos = (int*)realloc(vec->elementos, vec->capacidade * sizeof(int));
    }

    vec->elementos[vec->tamanho++] = x;
}

void inicializarAdjacencias(MeuVetor* adjacencias, int n) {
    int i;
    for (i = 0; i < n; i++) {
        inicializarVetor(&adjacencias[i], CAPACIDADE_INICIAL);
    }
}

void adicionarEmAdjacencias(MeuVetor* adjacencias, int u, int v) {
    adicionarElemento(&adjacencias[u], v);
    adicionarElemento(&adjacencias[v], u);
}

int encontrarPai(int v, int parent[]) {
    if (parent[v] == -1)
        return v;
    return encontrarPai(parent[v], parent);
}

void unirConjuntos(int x, int y, int parent[]) {
    int xSet = encontrarPai(x, parent);
    int ySet = encontrarPai(y, parent);
    parent[xSet] = ySet;
}

int kruskal(Tripla* arestas, int E, int V) {
    int* parent = (int*)malloc(V * sizeof(int));
    int i;
    for (i = 0; i < V; i++) {
        parent[i] = -1;
    }

    int pesoMinimo = 0;

    for (i = 0; i < E; i++) {
        int u = arestas[i].primeiro;
        int v = arestas[i].segundo;
        int peso = arestas[i].terceiro;

        int setU = encontrarPai(u, parent);
        int setV = encontrarPai(v, parent);

        if (setU != setV) {
            pesoMinimo += peso;
            unirConjuntos(setU, setV, parent);
        }
    }

    free(parent);
    return pesoMinimo;
}

int main() {
    int n;
    scanf("%d", &n);

    Tripla* arestas = NULL;
    int E = 0;

    int u, v, peso;
    while (scanf("%d %d %d", &u, &v, &peso) == 3) {
        arestas = (Tripla*)realloc(arestas, (E + 1) * sizeof(Tripla));
        arestas[E].primeiro = u;
        arestas[E].segundo = v;
        arestas[E].terceiro = peso;
        E++;
    }

    printf("%d\n", kruskal(arestas, E, n));

    free(arestas);

    return 0;
}
