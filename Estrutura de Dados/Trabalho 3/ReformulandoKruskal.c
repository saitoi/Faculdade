#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no {
    int indice;
    int visitado;
} No;

No nosVisitados[1000];

typedef struct aresta {
    int peso;
    No nos[2]; // Agora armazena um array de dois nós
    int selecionada;
} Aresta;

typedef struct grafo {
    int numVertices;
    int n;
    Aresta* arestas;
} Grafo;

No* criarNo(int indice) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->indice = indice;
    return novoNo;
}

Grafo* criarGrafo(int numVertices) {
    if (numVertices == 0) {
        puts("O grafo dado é nulo..");
        exit(1);
    }

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->arestas = (Aresta*)malloc((numVertices * (numVertices - 1) / 2) * sizeof(Aresta));
    grafo->numVertices = numVertices;
    grafo->n = 0;
    for (int i = 0; i < numVertices; ++i)
        grafo->arestas[grafo->n].selecionada = 0;

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    Aresta novaAresta;
    novaAresta.peso = peso;
    novaAresta.nos[0] = *criarNo(origem);
    novaAresta.nos[1] = *criarNo(destino);
    grafo->arestas[grafo->n] = novaAresta;
    grafo->n++;
}

int buscaNosRelacionados(Grafo arvoreGeradoraMinima, No verticeOrigem, No verticeDestino) {
    No* nosRelacionados = (No*)malloc(arvoreGeradoraMinima.numVertices * sizeof(No));
    int numNosRelacionados = 0;
    verticeOrigem.visitado = 1;
    for (int i = 0; i < arvoreGeradoraMinima.n; ++i) {
        if (arvoreGeradoraMinima.arestas[i].nos[0].indice == verticeOrigem.indice) {
            if (arvoreGeradoraMinima.arestas[i].nos[1].indice == verticeDestino.indice) {
                return 1;
            } else if (!arvoreGeradoraMinima.arestas[i].nos[1].visitado)
                return buscaNosRelacionados(arvoreGeradoraMinima, arvoreGeradoraMinima.arestas[i].nos[1], verticeDestino);
        } else if (arvoreGeradoraMinima.arestas[i].nos[1].indice == verticeOrigem.indice) {
            if (arvoreGeradoraMinima.arestas[i].nos[0].indice == verticeDestino.indice) {
                return 1;
            } else if (!arvoreGeradoraMinima.arestas[i].nos[1].visitado)
                return buscaNosRelacionados(arvoreGeradoraMinima, arvoreGeradoraMinima.arestas[i].nos[0], verticeDestino);
        }
    }
    return 0; // Retornar 0 se nenhum caminho for encontrado
}

int buscaNosRelacionados1(Grafo arvoreGeradoraMinima, No verticeOrigem, No verticeDestino) {
    verticeOrigem.visitado = 1;

    for (int i = 0; i < arvoreGeradoraMinima.n; ++i) {
        No adjacente;

        if (arvoreGeradoraMinima.arestas[i].nos[0].indice == verticeOrigem.indice) {
            adjacente = arvoreGeradoraMinima.arestas[i].nos[1];
        } else if (arvoreGeradoraMinima.arestas[i].nos[1].indice == verticeOrigem.indice) {
            adjacente = arvoreGeradoraMinima.arestas[i].nos[0];
        } else {
            continue;  // Aresta não está relacionada ao vérticeOrigem
        }

        if (adjacente.indice == verticeDestino.indice) {
            return 1;  // Caminho encontrado
        } else if (!adjacente.visitado) {
            int resultado = buscaNosRelacionados(arvoreGeradoraMinima, adjacente, verticeDestino);
            if (resultado) {
                return resultado;
            }
        }
    }

    return 0; // Nenhum caminho encontrado
}


void ordenarArestas(Grafo* grafo) {
    for (int i = 0; i < grafo->n; ++i) {
        for (int j = i + 1; j < grafo->n; ++j) {
            if (grafo->arestas[j].peso < grafo->arestas[i].peso) {
                Aresta temp = grafo->arestas[i];
                grafo->arestas[i] = grafo->arestas[j];
                grafo->arestas[j] = temp;
            }
        }
    }
}

Grafo* algoritmoKruskal(Grafo* grafo) {
    Grafo* arvoreGeradoraMinima = criarGrafo(grafo->numVertices);
    ordenarArestas(grafo);

    for (int i = 0; i < grafo->n; ++i) {
        if (!buscaNosRelacionados1(*arvoreGeradoraMinima, grafo->arestas[i].nos[0], grafo->arestas[i].nos[1])) {
            adicionarAresta(arvoreGeradoraMinima, grafo->arestas[i].nos[0].indice, grafo->arestas[i].nos[1].indice, grafo->arestas[i].peso);
        }
        for (int j = 0; j < grafo->n; ++j) {
            //grafo->arestas[j].nos[0].visitado = 0;
            //grafo->arestas[j].nos[1].visitado = 0;
        }
    }
    return arvoreGeradoraMinima;
}

void calcularPeso(Grafo* grafo) {
    int pesoTotal = 0;
    for (int i = 0; i < grafo->n; ++i) {
        if (grafo->arestas[i].selecionada) {
            pesoTotal += grafo->arestas[i].peso;
        }
    }
    printf("%d\n", pesoTotal);
}

int main(void) {
    int numVertices;
    scanf("%d", &numVertices);
    Grafo* grafo = criarGrafo(numVertices);

    int origem, destino, peso;
    while (!feof(stdin)) {
        scanf("%d %d %d", &origem, &destino, &peso);
        adicionarAresta(grafo, origem, destino, peso);
    }
    calcularPeso(algoritmoKruskal(grafo));

    return 0;
}
