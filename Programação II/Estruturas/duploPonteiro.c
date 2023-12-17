#include <stdio.h>

/* Chamando das funções */
void limpar_buffer(void);

void trocarValor(int *valor) {
    (*valor)++;
}

void trocarPonteiro(int **ponteiro) {
    (**ponteiro)++;
}

/* Função principal sem argumentos */
int main (void) {
    int x, *pointer, **doublePointer;

    x = 1;
    pointer = &x;
    doublePointer = &pointer;

    printf("O conteúdo de x é %d\n", x);
    printf("O endereço de x é %p\n", &x);
    printf("O endereço armazenado por doublePointer é %p\n", *doublePointer);
    printf("O conteúdo inteiro de doublePointer é %d\n", **doublePointer);
    //trocarValor(*doublePointer);
    trocarPonteiro(&pointer);
    printf("O novo conteúdo de x é %d\n", x);

 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
