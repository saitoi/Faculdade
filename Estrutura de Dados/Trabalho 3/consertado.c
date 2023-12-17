#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int* visitado;  // Array para marcar nós visitados durante a DFS
    int* parent;    // Array para armazenar o pai de cada nó durante a DFS
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
    grafo->visitado = (int*)malloc(numVertices * sizeof(int));
    grafo->parent = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; ++i) {
        grafo->vetorListas[i].cabeca = NULL;
        grafo->visitado[i] = 0;
        grafo->parent[i] = -1;
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

void dfs(struct Grafo* grafo, int node) {
    grafo->visitado[node] = 1;

    struct Node* atual = grafo->vetorListas[node].cabeca;
    while (atual) {
        int adjacente = atual->destino;
        if (!grafo->visitado[adjacente]) {
            grafo->parent[adjacente] = node;
            dfs(grafo, adjacente);
        }
        atual = atual->proximo;
    }
}

int verificaCiclo(struct Grafo* grafo, int origem, int destino) {
    grafo->visitado = (int*)calloc(grafo->numVertices, sizeof(int));
    for (int i = 0; i < grafo->numVertices; ++i) {
        grafo->parent[i] = -1;
    }

    dfs(grafo, origem);

    int atual = destino;
    while (grafo->parent[atual] != -1) {
        if (atual == origem) {
            free(grafo->visitado);
            return 1;  // Ciclo encontrado
        }
        atual = grafo->parent[atual];
    }

    free(grafo->visitado);
    return 0;  // Nenhum ciclo encontrado
}

void calcularPeso(struct Grafo* grafo) {
    int peso = 0;
    for (int i = 0; i < grafo->numVertices; ++i) {
        struct Node* atual = grafo->vetorListas[i].cabeca;
        while (atual) {
            peso += atual->peso;
            atual = atual->proximo;
        }
    }
    printf("Peso: %d\n", peso / 2);
}

struct Grafo* algoritmoKruskal(struct Grafo* grafo) {
    struct Grafo* grafoGerador = criarGrafo(grafo->numVertices);
    int menorPeso = INT_MAX;
    int origem = -1, destino = -1;

    for (int i = 0; i < grafo->numVertices; ++i) {
        struct Node* atual = grafo->vetorListas[i].cabeca;
        while (atual) {
            if (!verificaCiclo(grafoGerador, i, atual->destino) && atual->peso < menorPeso) {
                menorPeso = atual->peso;
                origem = i;
                destino = atual->destino;
            }
            atual = atual->proximo;
        }
    }

    if (origem != -1 && destino != -1) {
        adicionarAresta(grafoGerador, origem, destino, menorPeso);
    }

    return grafoGerador;
}

void imprimirGrafo(struct Grafo* grafo) {
    for (int v = 0; v < grafo->numVertices; ++v) {
        struct Node* atual = grafo->vetorListas[v].cabeca;
        printf("%d", v);
        while (atual) {
            printf(" -> %d (Peso %d)", atual->destino, atual->peso);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

int main() {
    int numVertices;
    scanf("%d", &numVertices);
    struct Grafo* grafo = criarGrafo(numVertices);
    char comando[100];
    while (fgets(comando, sizeof(comando), stdin) != NULL) {
        adicionarAresta(grafo, atoi(comando), atoi(comando + 2), atoi(comando + 4));
    }
    calcularPeso(grafo);
    calcularPeso(algoritmoKruskal(grafo));

    free(grafo->visitado);
    free(grafo->parent);
    free(grafo->vetorListas);
    free(grafo);

    return 0;
}
