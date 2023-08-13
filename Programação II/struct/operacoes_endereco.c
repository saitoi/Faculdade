#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

typedef int Meuinteiro;
typedef  ola;

/* Função principal não recebe argumentos */
Meuinteiro main (void) {

    int i = 2;
    Meuinteiro j = 10;
    printf("A soma é %d\n", i+j);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear) {
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
