#include <stdio.h>
#include <stdlib.h>

struct Node {
    int destino;
    int peso;
    struct Node* proximo;
};

struct ListaAdjacencia {
    struct Node* cabeca;
};

struct Grafo {
    int numVertices;
    struct ListaAdjacencia* vetorListas;
};

struct Node* criarNo(int destino, int peso) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

struct Grafo* criarGrafo(int numVertices) {
    if (numVertices == 0) {
        puts("O grafo dado é nulo..");
        exit(1);
    }

    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;
    grafo->vetorListas = (struct ListaAdjacencia*)malloc(numVertices * sizeof(struct ListaAdjacencia));

    for (int i = 0; i < numVertices; ++i) {
        grafo->vetorListas[i].cabeca = NULL;
    }

    return grafo;
}

void adicionarAresta(struct Grafo* grafo, int origem, int destino, int peso) {
    struct Node* novoNo = criarNo(destino, peso);
    novoNo->proximo = grafo->vetorListas[origem].cabeca;
    grafo->vetorListas[origem].cabeca = novoNo;

    novoNo = criarNo(origem, peso);
    novoNo->proximo = grafo->vetorListas[destino].cabeca;
    grafo->vetorListas[destino].cabeca = novoNo;
}

void calcularPeso(struct Grafo* grafo) {
    int peso = 0;
    for (int v = 0; v < grafo->numVertices; ++v) {
        struct Node* atual = grafo->vetorListas[v].cabeca;
        while (atual) {
            peso += atual->peso;
            atual = atual->proximo;
        }
    }
    printf("%d\n", peso / 2); // Divida por 2 para evitar contagem duplicada de arestas
}

struct Grafo* algoritmoKruskal(struct Grafo* grafo) {
    struct Grafo* grafoGerador = criarGrafo(grafo->numVertices);

    // Array para marcar se um vértice está na árvore geradora mínima
    int* naArvore = (int*)malloc(grafo->numVertices * sizeof(int));

    for (int i = 0; i < grafo->numVertices; i++) {
        naArvore[i] = 0; // Inicialmente, nenhum vértice está na árvore
    }

    int numArestasAdicionadas = 0;

    // Vetor para armazenar todas as arestas do grafo original
    struct Node** todasArestas = (struct Node**)malloc(grafo->numVertices * sizeof(struct Node*));

    for (int i = 0; i < grafo->numVertices; i++) {
        struct Node* atual = grafo->vetorListas[i].cabeca;
        while (atual) {
            todasArestas[numArestasAdicionadas] = atual;
            numArestasAdicionadas++;
            atual = atual->proximo;
        }
    }

    // Ordenar todas as arestas por peso
    for (int i = 0; i < numArestasAdicionadas - 1; i++) {
        for (int j = i + 1; j < numArestasAdicionadas; j++) {
            if (todasArestas[i]->peso > todasArestas[j]->peso) {
                // Trocar as arestas
                struct Node* temp = todasArestas[i];
                todasArestas[i] = todasArestas[j];
                todasArestas[j] = temp;
            }
        }
    }

    // Algoritmo de Kruskal
    for (int i = 0; i < numArestasAdicionadas; i++) {
        struct Node* aresta = todasArestas[i];
        int origem = aresta->destino;
        int destino = i;

        if (!naArvore[origem] || !naArvore[destino]) {
            adicionarAresta(grafoGerador, origem, destino, aresta->peso);
            naArvore[origem] = 1;
            naArvore[destino] = 1;
        }
    }

    free(naArvore);
    free(todasArestas);

    return grafoGerador;
}

int main() {
    int numVertices;
    scanf("%d", &numVertices);
    struct Grafo* grafo = criarGrafo(numVertices);
    int origem, destino, peso;
    while (scanf("%d %d %d", &origem, &destino, &peso) == 3) {
        adicionarAresta(grafo, origem, destino, peso);
    }
    
    struct Grafo* grafoGerador = algoritmoKruskal(grafo);
    calcularPeso(grafoGerador);

    free(grafo);
    free(grafoGerador);

    return 0;
}
