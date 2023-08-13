#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Struct da estrutura básica do nó */
typedef struct node {
    int data;
    struct node *prox;
} node;

/* Struct para definição do "head" e "tail" */
typedef struct lista {
    node *head;
    node *tail;
} Lista;

int isEmpty(Lista *p_lista) {
    return (p_lista->head == NULL);
}

void le_node(node *aux) {
    printf("Insira o valor do node criado : ");
    scanf("%d", &(aux->data));
}

void adicionar_elemento_final(Lista *p_lista) {
    node *novo_dado = (node *) malloc(sizeof(node));
    
    /* Verificação para alocação */
    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        return;
    }

    novo_dado->prox = NULL;
    le_node(novo_dado);

    /* Lista vazia */
    if (isEmpty(p_lista))
        p_lista->head = p_lista->tail = novo_dado;
    else {
    /* Inserção do "novo_dado" no final da lista */
        p_lista->tail->prox = novo_dado;
        p_lista->tail = novo_dado;
    }
}

void adicionar_elemento_inicio(Lista *p_lista) {
    node *novo_dado = (node *) malloc(sizeof(node));
    
    /* Verificação para alocação */
    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        return;
    }

    le_node(novo_dado);

    /* Lista vazia */
    if (isEmpty(p_lista))
        p_lista->head = p_lista->tail = novo_dado;
    else {
    /* Inserção do "novo_dado" no final da lista */
        novo_dado->prox = p_lista->head;
        p_lista->head = novo_dado;
    }
}

/* Função para imprimir lista encadeada */
void imprimir_lista(Lista p_lista) {
    /* Verificação para lista vazia */
    if (isEmpty(&p_lista)) {
        puts("Lista está vazia, não é possível imprimi-la.\n");
        return;
    }
    /* Impressão da lista */
    while (p_lista.head != NULL) {
        printf("Data do node %d : %d.\n", p_lista.head->data);
        p_lista.head = p_lista.head->prox;
    }
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
