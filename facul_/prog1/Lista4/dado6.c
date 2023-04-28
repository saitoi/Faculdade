#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define vzs 6000000.

int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int i = 0, dado = 0; 
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

    /* Inicializa o gerador de números aleatórios */
    srand(time(NULL));

    /* Permite a geração de números aleatórios para a variável dado ("faces do dado") */
    for(i = 0 ; i < vzs ; ++i)
    {
        /* Restringe os valores gerados para o intervalo de 0 a 5 */
        dado = (rand() % 6) + 1;

        /* Incrementa cada variável correspondente às diferentes faces do dado numeradas de 1 a 6 */
        switch(dado)
        {
            case 1:
            ++f1;
            break;

            case 2:
            ++f2;
            break;

            case 3:
            ++f3;
            break;

            case 4:
            ++f4;
            break;

            case 5:
            ++f5;
            break;

            case 6:
            ++f6;
            break;
        }
    }

    /* Imprime a frequência de aparição de cada face do dado */
    printf("A frequência com que a face 1 do dado apareceu foi %.2f\n", (f1 / vzs) * 100);
    printf("A frequência com que a face 2 do dado apareceu foi %.2f\n", (f2 / vzs) * 100);
    printf("A frequência com que a face 3 do dado apareceu foi %.2f\n", (f3 / vzs) * 100);
    printf("A frequência com que a face 4 do dado apareceu foi %.2f\n", (f4 / vzs) * 100);
    printf("A frequência com que a face 5 do dado apareceu foi %.2f\n", (f5 / vzs) * 100);
    printf("A frequência com que a face 6 do dado apareceu foi %.2f\n\n", (f6 / vzs) * 100);
    
 return 0;
}

/*
    (Saída):
    A frequência com que a face 1 do dado apareceu foi 16.64
    A frequência com que a face 2 do dado apareceu foi 16.68
    A frequência com que a face 3 do dado apareceu foi 16.68
    A frequência com que a face 4 do dado apareceu foi 16.64
    A frequência com que a face 5 do dado apareceu foi 16.70
    A frequência com que a face 6 do dado apareceu foi 16.67

*/
