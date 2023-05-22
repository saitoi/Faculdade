#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
    int valor;
    struct _No *prox;
}No;

void remove_no(No **head);
void insert(No **head);
void read_no(No **tail);
void print_list(No **head);

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

void remove_no(No **head) {
    No *no_atual = *head;
    for (;no_atual->prox->prox != NULL; no_atual = no_atual->prox);
    free(no_atual->prox->prox);
    no_atual->prox->prox = NULL;
}

void read_no(No **tail) {
    //Atribuir valores à struct criada
    printf("Insira um valor numérico à struct criada : ");
    scanf("%d", &((*tail)->valor));
}

void insert(No **head) {
    // Criação do novo nó
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->prox = NULL;

    if (*head == NULL) {
        // Lista vazia, o novo nó será o primeiro e último nó
        *head = novo_no;
    } else {
        // Procura o último nó da lista
        No *current = *head;
        while (current->prox != NULL) {
            current = current->prox;
        }
        // Insere o novo nó no final da lista
        current->prox = novo_no;
    }
		read_no(&novo_no);
}

void print_list(No **head) {
    int i = 0;
    No *no_atual = *head;
/*    for (int i = 0;no_atual != NULL; no_atual = no_atual->prox, i++)
        printf("O valor da no %d é %d\n", i+1, no_atual->valor);*/
    while (no_atual->prox == NULL) {
        printf("O valor do no %d é %d\n", ++i, no_atual->valor);
        no_atual = no_atual->prox;
    }
}

/* Função principal não recebe argumentos */
int main (void) {
    /* Declarando e inicializando variáveis inteiras */
    No *head = NULL;
    for (int i = 0; i < 3; ++i)
        insert(&head);
    printf("\n\n");
    print_list(&head);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
