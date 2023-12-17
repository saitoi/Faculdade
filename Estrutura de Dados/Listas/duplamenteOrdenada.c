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

// Função para inserir um novo nó no início da lista
void inserirInicio(Node *cabeca, int data) {
    Node *novoNo = criarNo(data);
    novoNo->next = cabeca->next;
    if (cabeca->next != NULL) {
        cabeca->next->prev = novoNo;
    }
    cabeca->next = novoNo;
    novoNo->prev = cabeca;
}

// Função para remover um nó com chave x da lista
void removerChave(Node *cabeca, int x) {
    Node *atual = cabeca->next;

    while (atual != NULL) {
        if (atual->data == x) {
            //if (atual->prev != NULL) {
            atual->prev->next = atual->next;
            //}
            if (atual->next != NULL) {
                atual->next->prev = atual->prev;
            }
            free(atual);
            return; // Chave encontrada e removida
        }
        atual = atual->next;
    }

    // Chave não encontrada na lista
    printf("Chave %d não encontrada na lista.\n", x);
}

void inserirOrdenado(Node *cabeca, int data) {
    Node *novoNo = criarNo(data);
    Node *atual = cabeca->next;
    Node *anterior = cabeca;
    while (atual != NULL) {
        if (data < atual->data) {
            novoNo->next = atual;
            novoNo->prev = atual->prev;
            atual->prev->next = novoNo;
            atual->prev = novoNo;
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
    if (atual == NULL) {
        novoNo->next = NULL;
        novoNo->prev = anterior;
        anterior->next = novoNo;
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

    // Inserção de elementos na lista
    inserirOrdenado(cabeca, 30);
    inserirInicio(cabeca, 20);
    inserirInicio(cabeca, 10);

    // Impressão da lista antes da remoção
    printf("Lista antes da remoção: ");
    imprimirLista(cabeca);

    // Remoção da chave 10
    removerChave(cabeca, 30);

    // Impressão da lista após a remoção
    printf("Lista após a remoção: ");
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
