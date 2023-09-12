#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Struct base para o empilhamento */
typedef struct pilhas {
    int data;
    struct pilhas *prox;
} Pilhas;

/* Struct referente ao topo da pilha */
typedef struct stack {
    Pilhas *topo;
} Stack;

/* Verificação caso lista esteja vazia */
int isEmpty(Stack *stack) {
    return (stack->topo == NULL);
}

/* Função para empilhar novo elemento */
void push(Stack *stack, int data) {
    Pilhas *novo_dado = (Pilhas *) malloc(sizeof(Pilhas));

    if (novo_dado == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    novo_dado->prox = stack->topo;
    novo_dado->data = data;
    stack->topo = novo_dado;
    printf("%d empilhado com sucesso.\n", data);
}

/* Função para remover primeiro elemento */
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        puts("A pilha está vazia.");
        exit(1);
    }

    //Pilhas *temp = stack->topo;
    stack->topo = stack->topo->prox;
    //free(temp);
    puts("Elemento removido com sucesso.");
}

/* Função para imprimir a pilha */
void imprimir_pilha(Stack stack) {
    int i = 0;
    while (stack.topo != NULL) {
        printf("Elemento %d da pilha: %d\n", i, stack.topo->data);
        stack.topo = stack.topo->prox;
        ++i;
    }
}

/* Função principal não recebe argumentos */
int main(void) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->topo = NULL;
    
    push(stack, 10);        /* Inserindo novos elementos na pilha */  
    push(stack, 20);
    push(stack, 30);

    printf("O elemento do topo da pilha é o %d\n", stack->topo->data);
    pop(stack);
    printf("O novo topo da pilha é o %d\n", stack->topo->data);
    puts("Imprimindo a lista: \n");
    imprimir_pilha(*stack);

    return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(void) {
    int clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
