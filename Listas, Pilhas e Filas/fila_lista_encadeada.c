#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Struct base para enfileiramento */
typedef struct node {
    int data;
    struct node *prox;
} Node;

/* Struct referente ao início/fim da fila */
typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

/* Inicializando a fila com NULL */
void initialize(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data) {
    Node *novo_dado = (Node *) malloc(sizeof(Node));

    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    novo_dado->prox = NULL;
    novo_dado->data = data;

    if (isEmpty(queue)) {
        queue->front = novo_dado;
        queue->rear = novo_dado;
    } else {
        queue->rear->prox = novo_dado;
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
    if (queue->front->prox == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->prox;
    }
    printf("%d removido com sucesso.\n", removido);
}

/* Função principal não recebe argumentos */
int main (void) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    initialize(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("O primeiro elemento da fila é o %d.\n", queue->front->data);
    dequeue(queue);
    printf("O novo primeiro elemento é o %d.\n", queue->front->data);


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
