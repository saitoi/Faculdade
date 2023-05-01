#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */
    char letras = 'a';

    printf("O número de bytes da variável \"a\" é %lu\n", sizeof(letras));

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
