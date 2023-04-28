#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int i = 0, n = 0;
    int max = 100;

    /* Inicializa o gerador de números aleatórios */
    srand(time(NULL));

    /* Permite a geração de números aleatórios atribuídos à variável "n" */
    for (i = 0 ; i < 10 ; ++i)
    {
        /* Valores para a variável "n" estão compreendidos entre 0 e 100 */
        n = rand() % max;

        /* Impressão desses resultados */
        printf("O valor \"aleatório\" a ser impresso é %d\n\n", n);
    }

 return 0;
}

/*
    (Saída):
    O valor "aleatório" a ser impresso é 36

    O valor "aleatório" a ser impresso é 53
    
    O valor "aleatório" a ser impresso é 52
    
    O valor "aleatório" a ser impresso é 16
    
    O valor "aleatório" a ser impresso é 77
    
    O valor "aleatório" a ser impresso é 24
    
    O valor "aleatório" a ser impresso é 53
    
    O valor "aleatório" a ser impresso é 2
    
    O valor "aleatório" a ser impresso é 18
    
    O valor "aleatório" a ser impresso é 92

*/
