#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int id;
    int rank;
    int peso;
    struct vertice* prox;
} Vertice;

Vertice *inicializarVertice(int n) {
    Vertice* vertice = (Vertice*)malloc(n*sizeof(Vertice));
    int i; 
    for (i = 0; i < n; i++) {
        vertice[i].id = i;
        vertice[i].rank = 0;
        vertice[i].peso = 0;
        vertice[i].prox = &vertice[i];
    }
    return vertice;
}

Vertice* find(Vertice* v) {
    Vertice* aux = v;
    while (aux->prox != aux) {
        aux = aux->prox;
    }
    return aux;
}

void une(Vertice* u, Vertice* v, int peso) {
    if (u->rank > v->rank) {
        v->prox = u;
        v->peso = peso;
    } else {
        u->prox = v;
        u->peso = peso;
        if (u->rank == v->rank) {
            v->rank++;
        }
    }
}

void calcularPeso(Vertice* vertices, int n) {
    int pesoTotal = 0;
    int i;
    for (i = 0; i < n; i++) {
        pesoTotal += vertices[i].peso;
    }
    printf("%d\n", pesoTotal);
}

void criarAresta(Vertice *vertices, int u, int v, int peso) {
    Vertice* verticeU = find(&vertices[u]);
    Vertice* verticeV = find(&vertices[v]);
    if (verticeU != verticeV) {
        une(verticeU, verticeV, peso);
    }
}

int main (void) {
    int n;
    scanf("%d", &n);

    Vertice* vertices = inicializarVertice(n);

    int u, v, peso;
    while (scanf("%d %d %d", &u, &v, &peso) == 3) {
        criarAresta(vertices, u-1, v-1, peso);
    }
    calcularPeso(vertices, n);

    return 0;
}
