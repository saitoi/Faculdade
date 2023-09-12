#include <stdio.h>

/* Chamando das funções */
void limpar_buffer(void);

typedef struct node {
  int valor;
  struct node *proximo;
} Node;

typedef struct lista {
  Node *inicio;
  Node *fim;
} Lista;

void inverterElementos(Lista *node) {
  
}

/* Função principal sem argumentos */
int main (void) {
  Lista *cabeca = (Lista*) malloc(sizeof(Lista));

 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
