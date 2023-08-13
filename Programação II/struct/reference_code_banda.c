#include <stdio.h>
#include <stdlib.h>

/* Struct para definição da banda */
typedef struct _Banda {
    char nome[50], estilo[50];
    int numero_integrantes, ranking;
    struct _Banda *prox;
} Banda;

typedef struct _Lista {
    Banda *head, *tail;
    int tam;
} Lista;

void le_banda(Banda *tail) {
    /* Le os dados para a banda recém inserida */
    printf("\nInsira o nome da banda: ");
    scanf("%s", tail->nome);
    printf("Insira o estilo da banda: ");
    scanf("%s", tail->estilo);
    printf("Insira o número de integrantes: ");
    scanf("%d", &tail->numero_integrantes);
    printf("Insira o ranking da banda: ");
    scanf("%d", &tail->ranking);
}

/* Função para adicionar banda ao final da lista */
void adiciona_banda(Lista *p_lista) {
    Banda *nova_banda = (Banda*) malloc(sizeof(Banda));
    if (nova_banda == NULL) {
        printf("Erro ao alocar memória para a nova banda.\n");
        return;
    }

    le_banda(nova_banda);
    nova_banda->prox = NULL;

    if (p_lista->head == NULL) {
        p_lista->head = p_lista->tail = nova_banda;
    } else {
        p_lista->tail->prox = nova_banda;
        p_lista->tail = nova_banda;
    }

    p_lista->tam++;
}

void remover_banda(Lista *p_lista) {
    if (p_lista->head == NULL) {
        printf("A lista está vazia. Não há banda para remover.\n");
        return;
    }

    if (p_lista->head == p_lista->tail) {
        free(p_lista->head);
        p_lista->head = p_lista->tail = NULL;
    } else {
        Banda *p_atual = p_lista->head;
        while (p_atual->prox != p_lista->tail) {
            p_atual = p_atual->prox;
        }

        free(p_lista->tail);
        p_lista->tail = p_atual;
        p_lista->tail->prox = NULL;
    }

    p_lista->tam--;
}

void imprimir_lista(Lista *p_lista) {
    Banda *temp = p_lista->head;
    while (temp != NULL) {
        printf("Nome da banda: %s\n", temp->nome);
        printf("Estilo musical: %s\n", temp->estilo);
        printf("Número de integrantes: %d\n", temp->numero_integrantes);
        printf("Ranking: %d\n", temp->ranking);
        printf("\n");

        temp = temp->prox;
    }
}

void remove_sbanda(Lista *p_lista, int pos) {
    int cont = 1;
    Banda *atual = p_lista->head;
    Banda *anterior = NULL;

    if (pos == 1) {
        free(p_lista->head);
        p_lista->head = atual->prox;
    } else {
        while (cont != pos && atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            ++cont;
        }
        if (atual != NULL) {
            anterior->prox = atual->prox;
            free(atual);
        }
    }
}

/* Função principal não recebe argumentos */
int main(void) {
    Lista banda_1;
    banda_1.head = banda_1.tail = NULL;
    banda_1.tam = 0;

    int tam;
    char resposta;

    printf("Escolha quantas alocações deseja realizar: ");
    scanf("%d", &tam);

    for (int i = 0; i < tam; ++i) {
        adiciona_banda(&banda_1);
    }

    printf("Situação atual da lista:\n");
    imprimir_lista(&banda_1);

    printf("Deseja remover o último elemento da lista? (y/n)\n");
    scanf(" %c", &resposta);

    if (resposta == 'y') {
        remover_banda(&banda_1);
    }

    puts("Deseja remover qual elemento da lista? (int)\n");
    scanf(" %d", &resposta);

    remove_sbanda(&banda_1, atoi(resposta));

    imprimir_lista(&banda_1);
    
    return 0;
}
