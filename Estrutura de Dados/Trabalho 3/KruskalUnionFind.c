#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int id;
    int rank;
    struct vertice *prox;
} Vertice;

typedef struct aresta{
    Vertice *u;
    Vertice *v;
    int peso;
} Aresta;

Vertice *find(Vertice *v) {
    Vertice *aux = v;
    while (aux->prox != aux) {
        aux = aux->prox;
    }
    while (v->prox != aux) {
        Vertice *aux2 = v->prox;
        v->prox = aux;
        v = aux2;
    }
    return aux;
}

void une(Vertice *u, Vertice *v) {
    if (u->rank > v->rank) {
        v->prox = u;
    } else {
        u->prox = v;
        if (u->rank == v->rank) {
            v->rank++;
        }
    }
}

void criarArestas(Aresta *arestas, Vertice *u, Vertice *v, int peso) {
    Aresta *aresta = (Aresta*)malloc(sizeof(Aresta));
    aresta->u = u;
    aresta->v = v;
    aresta->peso = peso;
}



int main (void) {
    int n;
    scanf("%d", &n);

    Aresta arestas[n];
    int u, v, peso;
    while (scanf("%d %d %d", &u, &v, &peso) == 3) {
        une(find(u), find(v));
        criarArestas(u, v, peso);
    }

    free();

    return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
