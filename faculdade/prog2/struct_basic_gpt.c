#include <stdio.h>
#include <stdlib.h>

/* Definição da estrutura do nó da lista */
typedef struct Node {
    int data;           /* Dado armazenado no nó */
    struct Node* next;  /* Ponteiro para o próximo nó da lista */
} Node;

/* Função para inserir um novo nó no início da lista */
void insert(Node** head, int data) {
    /* Cria um novo nó */
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Função para imprimir os dados armazenados na lista */
void printList(Node* head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Função principal */
int main() {
    /* Inicializa a lista como vazia */
    Node* head = NULL;

    /* Insere alguns nós na lista */
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    /* Imprime os dados armazenados na lista */
    printList(head);

    return 0;
}
