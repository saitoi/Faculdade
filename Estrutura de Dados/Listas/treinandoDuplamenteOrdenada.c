#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node *criarNo(int data) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

// Função para inserir um nó na lista ordenada
void inserirOrdenado(Node *cabeca, int data) {
    Node *novoNo = criarNo(data);
    Node *atual = cabeca->next;

    while (atual != NULL && atual->data < data) {
        atual = atual->next;
    }

    if (atual != NULL) {
        novoNo->prev = atual->prev;
        novoNo->next = atual;
        atual->prev->next = novoNo;
        atual->prev = novoNo;
    } else {
        Node *ultimo = cabeca;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        novoNo->prev = ultimo;
        novoNo->next = NULL;
        ultimo->next = novoNo;
    }
}

void removerChave(Node *cabeca, int data) {
    Node *atual = cabeca->next;
    Node *anterior = NULL;
    while(atual->data != data && atual != NULL) {
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL) {
        puts("Chave não foi encontrada.");
        return;
    } else if (atual->next == NULL) {
        
    }
}

// Função para imprimir a lista
void imprimirLista(Node *cabeca) {
    Node *atual = cabeca->next;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    // Criação do nó cabeça da lista
    Node *cabeca = criarNo(-1);

    // Inserção de elementos na lista ordenada
    inserirOrdenado(cabeca, 30);
    inserirOrdenado(cabeca, 10);
    inserirOrdenado(cabeca, 20);
    inserirOrdenado(cabeca, 5);

    // Impressão da lista
    imprimirLista(cabeca);

    // Liberação da memória alocada
    Node *atual = cabeca;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
