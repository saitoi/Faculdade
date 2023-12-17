#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

typedef struct No {
    int data;
    struct No *prox;
} No;

/* Função principal não recebe argumentos */
int main (void) {
    /* Declarando as variáevis */
    No no1;
    No *pont = NULL;

    /* Alocando memória */
    pont = (No *) malloc(sizeof(No));

    /* Acessando os campos das variáveis */
    no1.data = 10;  // Notação de "." ponto
    pont->data = 5; // Notação de "->" ponteiro

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear) {
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
