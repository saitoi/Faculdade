#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para inserir um novo nó no início da lista
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Função para exibir a lista
void displayList(Node* head) {
    Node* current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Função para remover um elemento no meio da lista
void removeElement(Node** head, int valor_removed) {
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // Caso especial

    // Encontra o nó a ser removido
    while ((temp->data) != valor_removed && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Caso especial: posição inválida
    if (temp == NULL) {
        printf("Valor não encontrado.\n");
        return;
    }

    // Remove o nó da lista
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    int choice, value, valor_removed;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Inserir nó no início\n");
        printf("2. Remover elemento do meio\n");
        printf("3. Exibir lista\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor_removed);
                removeElement(&head, valor_removed);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
