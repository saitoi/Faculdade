#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

/* Função principal não recebe argumentos */
int main(void)
{
    char str[] = "pessoa";
    char *c = (char *)malloc(sizeof(char) * 10);
    int i = 5, j = 10,
        *pi = &i, *pj = &j;
    
    ++c;
    printf("O valor de c é %s\n", c);

    c = &str[3];
    printf("O valor de str[i] é %s\n", c);

    return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf()
{
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
