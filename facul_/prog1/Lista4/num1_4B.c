#include <stdio.h>

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int i = 1;

    while (i <= 20)
    {
        if (i == 2)
        {
            ++i; 
            continue;
        }
        
        if (i == 5)
        break;

        printf("i = %d\n", i);
        ++i;        
    }

 return 0;
}

/*
    (Saída):
    i = 1
    i = 3
    i = 4
    
*/
