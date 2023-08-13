#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct lista {
    node *head;
    node *tail;
} Lista;

void initialize(Lista *p_lista) {
    p_lista->head = p_lista->tail = NULL;
}

int isEmpty(Lista *p_lista) {
    return (p_lista->head == NULL);
}

int tamanho_lista(Lista *p_lista) {
    int cont;
    node *aux = p_lista->head;
    while (aux != NULL) {
        aux = aux->next;
        ++cont;
    }
    return cont;
}

void imprimir_lista(Lista *p_lista) {
    node *aux = p_lista->head;
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void adicionar_posicao_n(Lista *p_lista, int posicao) {
    int cont = 0;
    node *aux = p_lista->head;
    node *novo_dado = (node *) malloc(sizeof(node));

    /* Verificação para alocação */
    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        return;
    }

    /* Lista vazia */
    if (isEmpty(p_lista)) {
        puts("Lista vazia, inserindo no início.\n");
        p_lista->head = p_lista->tail = novo_dado;
    } else {
        /* Inserindo na posição selecionada */
        if (posicao >= tamanho_lista(p_lista)) {
            puts("Posição inválida, inserindo no final.\n");
            p_lista->tail->next = novo_dado;
            novo_dado->prev = p_lista->tail;
            p_lista->tail = novo_dado;
        } else {
            while (cont < posicao - 1) {
                aux = aux->next;
                ++cont;
            }

            novo_dado->next = aux->next;
            aux->next = novo_dado;
            (novo_dado->next)->prev = novo_dado;
        }
    }
}


/* Função principal não recebe argumentos */
int main (void) {
    Lista *p_lista;


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
