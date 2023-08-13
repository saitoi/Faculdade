#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf();

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
    printf("\nInsira o nome da banda : ");
    scanf("%s", tail->nome);
    printf("\nInsira o estilo da banda : ");
    scanf("%s", tail->estilo);
    printf("\nInsira o numero de integrantes : ");
    scanf("%d", &tail->numero_integrantes);
    printf("\nInsira o ranking da banda : ");
    scanf("%d", &tail->ranking);

}

/* Função para adicionar banda ao final da lista */
void adiciona_banda(Lista *p_lista) {
    /* Separa em dois casos */
    /* 1. Lista vazia, sem elemento */
    /* 2. Lista já possui algum elemento */
    if (p_lista->head == NULL ) {
        p_lista->head = p_lista->tail = (Banda*) malloc(sizeof(Banda));
    }else {
        p_lista->tail->prox = (Banda*) malloc(sizeof(Banda));
        p_lista->tail = p_lista->tail->prox;
        p_lista->tail->prox = NULL;
        /*  
        p_lista->tail->prox == NULL <- malloc()
        Ou seja, a macro NULL não está mais presente na estrutura
        */
    }
    le_banda(p_lista->tail);
    
}

void remover_banda(Lista *p_lista) {
    Banda *p_atual = p_lista->head;

    /* N(p_lista) = 0 */
    if (p_lista->head == NULL) return;

    /* N(p_lista) = 1 */
    if (p_lista->head == p_lista->tail) {
        free(p_lista->tail);
        p_lista->head = p_lista->tail = NULL; return;
    }
        
    /* N(p_lista) ≥ 2 */
    while (p_atual->prox != NULL) {
        if (p_atual->prox == p_lista->tail) {
            free(p_lista->tail);
            p_lista->tail = p_atual->prox;
            p_lista->tail->prox = NULL;
        }
    p_atual = p_atual->prox;
    }
}

void imprimir_lista(Lista *p_lista) {
    Banda *temp = p_lista->head;
    while (temp != NULL) {
        printf("Nome da banda : %s\n\n", temp->nome);
        printf("Estilo musical : %s\n\n", temp->estilo);
        printf("Número de integrantes : %d\n\n", temp->numero_integrantes);
        printf("Ranking : %d\n\n", temp->ranking);
        /* (Impressao da posicao do elemento na lista) */

        /* percorrendo a lista com p_lista->head */
        temp = temp->prox;
    }
}

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando variáveis inteiras */
    Lista *banda_1 = (Lista *) malloc(sizeof(Lista)); 
    int i, tam;
    char resposta;

    /* Inicializando as variáveis */
    banda_1->head = banda_1->tail = NULL;

    printf("Escolha quantas alocações deseja realizar : ");
    scanf("%d", &tam);
    for (i = 0; i < tam; ++i) {
        adiciona_banda(banda_1);
    }
    printf("Situação atual da lista : \n"); imprimir_lista(banda_1);
    printf("Deseja remover o ultimo elemento da lista ? (y/n)\n");
    clean_buf();
    scanf(" %c", &resposta);
    if (resposta == 'y') remover_banda(banda_1);
    imprimir_lista(banda_1);
    
 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf()
{
    /* Conclui após buffer estiver limpo */
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
