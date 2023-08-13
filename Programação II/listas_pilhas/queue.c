#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data) {
    node *novo_dado = (node *) malloc(sizeof(node));

    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    novo_dado->next = NULL;
    novo_dado->data = data;

    if (isEmpty(queue)) {
        queue->front = novo_dado;
        queue->rear = novo_dado;
    } else {
        queue->rear->next = novo_dado;
        queue->rear = novo_dado;
    }
    printf("Valor %d enfileirado com sucesso.\n", data);
}

/* Função para remover primeiro elemento da fila */
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        puts("Erro ao remover elemento, fila está vazia.\n");
        exit(1);
    }

    int removido = queue->front->data;
    if (queue->front->next == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    printf("Valor %d removido com sucesso.\n", removido);
}

/* Função para remover ultimo elemento */
void dequeue_last(Queue *queue) {
    if (isEmpty(queue)) {
        puts("Erro ao remover elemento, fila está vazia.\n");
        exit(1);
    }

    int removido = queue->rear->data;
    /* Lista com 1 elemento */
    if (queue->front->next == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
    /* Lista com mais de 1 elemento */
        node *aux = queue->front;
        while (aux->next != queue->rear) {
            aux = aux->next;
        }
        free(queue->rear);
        queue->rear = aux;
        queue->rear->next = NULL;
    }
    printf("Valor %d removido com sucesso.\n", removido);
}


/* Função principal não recebe argumentos */
int main (void) {


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
