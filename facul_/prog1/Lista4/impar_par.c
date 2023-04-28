#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define vzs 1000000. /* Definindo a constante vzs ("vezes") como 1000000 em ponto flutuante */

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e em ponto flutuante */
    int i = 0, numr = 0; 
    float contp = 0;

    /* Inicializa o gerador de números aleatórios */
    srand(time(NULL));

    /* Permite a geração de 1000000 de números "aleatórios" */
    for(i = 0 ; i < vzs ; ++i)
    {
        /* Valores compreendidos no intervalo de 0 a RAND_MAX (= valor máximo retornado pela função "rand()") */
        numr = rand() % RAND_MAX;

        /* Verifica se número gerado é par e, portanto, incrementa + 1 em contp ("contador de pares") */
        if(numr % 2 == 0)
        ++contp;
    }

    /* Imprime o número de pares determinado pela variável contador de números pares */
    printf("A quantidade de pares é %.0f\n", contp);
    printf("A quantidade de ímpares é %.0f\n\n", vzs - contp);

    /* Calcula a frequência (porcentagem) da aparição de valores pares e ímpares */
    printf("A frequência de números pares foi de %.2f%%\n", (contp / vzs) * 100);
    printf("A frequência de números ímpares foi de %.2f%%\n\n", ((vzs - contp) / vzs) * 100);

 return 0;
}

/*
    (Saída):
    A frequência de números pares foi de 50.05
    A frequência de números ímpares foi de 49.95

*/
