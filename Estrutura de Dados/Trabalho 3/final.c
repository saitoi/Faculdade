#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int id;
    int rank;
    struct vertice* prox;
} Vertice;

typedef struct aresta {
    Vertice* u;
    Vertice* v;
    int peso;
} Aresta;

typedef struct grafo {
    int n;
    Aresta* arestas;
} Grafo;

Grafo* criarGrafo(int n) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->n = n;
    grafo->arestas = (Aresta*)malloc(((n - 1) * n / 2) * sizeof(Aresta));
    return grafo;
}

void criarAresta(Grafo* grafo, int u, int v, int peso, int index) {
    Aresta* aresta = &grafo->arestas[index];
    aresta->u = (Vertice*)malloc(sizeof(Vertice));
    aresta->v = (Vertice*)malloc(sizeof(Vertice));
    aresta->u->id = u;
    aresta->v->id = v;
    aresta->peso = peso;
}

Vertice* find(Vertice* v) {
    Vertice* aux = v;
    while (aux->prox != aux) {
        aux = aux->prox;
    }
    while (v->prox != aux) {
        Vertice* aux2 = v->prox;
        v->prox = aux;
        v = aux2;
    }
    return aux;
}

void une(Vertice* u, Vertice* v) {
    if (u->rank > v->rank) {
        v->prox = u;
    } else {
        u->prox = v;
        if (u->rank == v->rank) {
            v->rank++;
        }
    }
}

int calcularPesoArvore(Aresta* arvoreGeradora, int tamanho) {
    int peso = 0;
    for (int i = 0; i < tamanho; i++) {
        peso += arvoreGeradora[i].peso;
    }
    return peso;
}

void kruskal(Grafo* grafo) {
    int n = grafo->n;
    Aresta* arestas = grafo->arestas;
    Aresta* arvoreGeradoraMinima = (Aresta*)malloc((n - 1) * sizeof(Aresta));
    Vertice* vertices = (Vertice*)malloc(n * sizeof(Vertice));
    for (int i = 0; i < n; i++) {
        vertices[i].id = i;
        vertices[i].rank = 0;
        vertices[i].prox = &vertices[i];
    }
    int i = 0;
    int j = 0;
    while (i < n - 1) {
        Aresta aresta = arestas[j++];
        Vertice* u = find(&vertices[aresta.u->id]);
        Vertice* v = find(&vertices[aresta.v->id]);
        if (u != v) {
            arvoreGeradoraMinima[i++] = aresta;
            une(u, v);
        }
    }

    int pesoArvore = calcularPesoArvore(arvoreGeradoraMinima, n - 1);
    printf("%d\n", pesoArvore);

    free(arvoreGeradoraMinima);
    free(vertices);
}

int main(void) {
    int n;
    scanf("%d", &n);

    Grafo* grafo = criarGrafo(n);

    int u, v, peso, index = 0;
    while (!feof(stdin)) {
        scanf("%d %d %d", &u, &v, &peso);
        criarAresta(grafo, u, v, peso, index);
        index++;
    }

    kruskal(grafo);

    free(grafo->arestas);
    free(grafo);

    return 0;
}
