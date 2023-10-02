#include <stdio.h>
#include <stdlib.h>

/* Chamando das funções */
void limpar_buffer(void);

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;



/* Função principal sem argumentos */
int main (void) {


 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
