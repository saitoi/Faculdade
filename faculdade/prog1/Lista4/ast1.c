/*

Programa: Lista 4A ;
Autor: Pedro Henrique Honorio Saito ;
Data : 29/09/2022 ;
Descrição: Praticar comandos de teste e repetição ;

*/

#include <stdio.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int numl = 0, numc = 0;
    int cont1 = 0, cont2 = 0;

    /* Atribuindo o número de linhas e colunas respectivamente às variáveis "numl" e "numc" */
    printf("Insira o valor correspondente ao número de linhas a ser impressa: ");
    
    /* Validação da entrada para caracteres e valores negativos ou nulos */
    while(scanf("%d", &numl) == 0 || numl <= 0)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
    }
    printf("Insira o valor correspondente ao número de linhas a ser impressa: ");

    /* Validação da entrada para caracteres, valores negativos ou nulos */
    while(scanf("%d", &numc) == 0 || numc <= 0)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
    }

    getchar(); /* Função getchar() pega caractere "\n" armazenado no buffer */

    printf("\n");

    /* 
        O comando "for" mais externo altera permite a alteração da linha de impressão dos
        asteriscos, enquanto o segundo "for" permite a impressão dos asteriscos continuamente.
    */
    for (cont1 = 0 ; cont1 < numl ; ++cont1)
    {
        for (cont2 = 0 ; cont2 < numc ; ++cont2)
        printf("*");

        printf("\n");
    }
    printf("\n");

 return 0;
}

/*
    Valores testados para o programa:

    (Entradas):
    5
    10


    (Saída):
    Insira o valor correspondente ao número de linhas a ser impressa:
    Insira o valor correspondente ao número de linhas a ser impressa:
    
    **********
    **********
    **********
    **********
    **********

*/
