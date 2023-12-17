#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);



/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
