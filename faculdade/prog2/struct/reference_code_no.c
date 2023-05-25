#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Implementando programa com um único struct */
typedef struct _No {
    int valor;
    struct _No *prox;
} No;

void read_no(No *tail) {
    printf("Insira o valor referente ao nó : ");
    scanf("%d", &((tail)->valor));
}

void insert_no(No **head) {
    /* Alocando memória para a estrutura criada */
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->prox = NULL;   
    read_no(novo_no);   //Leitura do nó recém criado

    /* Erro na alocação de memória */
    if (novo_no == NULL) { puts("Erro ao alocar memória para o novo nó.\n"); return; }
    
    /* Número de elementos == 0 */
    if (*head == NULL) *head = novo_no; else {
    /* Número de elementos != 0 */
    No *atual = *head;
    while (atual->prox != NULL) atual = atual->prox;
    atual->prox = novo_no;
    }
}

void remove_no(No **head) {
    No *atual = *head;
    /* Número de elementos == 0 */
    if (*head == NULL) { puts("Lista vazia, não é possível remover elementos.\n"); return;}
    /* Número de elementos == 1 */
    if ((*head)->prox == NULL) {
        free(*head);
        *head = NULL;
    } else {
    /* Número de elementos > 1 */
    while (atual->prox->prox != NULL) atual = atual->prox;
    free(atual->prox);
    atual->prox = NULL;
    }
}

void print_no(No *head) {
    No *atual = head;
    int i = 1;
    while (atual != NULL) {
        printf("\nValor do no %d : %d\n", i, atual->valor);
        atual = atual->prox;
        ++i;
    }
}

/* Função principal não recebe argumentos */
int main (void) {
    /* Inicializando o ponteiro 'head' */
    No *head = NULL;
    /* Inserindo uma quantia de 3 elementos */
    for (int i = 0; i < 3; ++i) {
        insert_no(&head);
        clean_buf(); 
    }
    print_no(head);
    /* Perguntando se usuário deseja remover ultimo elemento */
    puts("Deseja remover o ultimo elemento da lista ? (y/n)\t");
    char resposta = getchar();
    if (resposta == 'y') remove_no(&head); print_no(head);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(void) {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
