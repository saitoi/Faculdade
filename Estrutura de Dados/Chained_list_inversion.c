#include <stdio.h>
#include <stdlib.h>

/* Chamando das funções */
void limpar_buffer(void);

struct Node {
    int data;
    struct Node* next;
};

struct Node* desafio(struct Node* ptr_recursao, struct Node** ptr_lista) {
    if (ptr_recursao->next == NULL) {
        *ptr_lista = ptr_recursao;
        return ptr_recursao;
    }
        struct Node* ptr = desafio(ptr_recursao->next, ptr_lista);
        ptr->next = ptr_recursao;
        ptr_recursao->next = NULL;
        return ptr_recursao;
}

struct Node* newNode(int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void imprimirVetor(struct Node *vetor) {
    struct Node *ptr = vetor;
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

/* Função principal sem argumentos */
int main (void) {
    struct Node *head = NULL;
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    imprimirVetor(head);
    desafio(head, &head);
    puts("\nVetor ordenado:\n");
    imprimirVetor(head);

 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
