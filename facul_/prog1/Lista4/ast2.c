#include <stdio.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int numl = 0;
    int cont1 = 0, cont2 = 0;

    /* Atribuindo o valor correspondente ao número de linhas à variável "numl" */
    printf("Insira o valor correspondente ao número de linhas a ser impresssa: ");

    /* Validação da entrada para caracteres e valores negativos ou nulos */
    while(scanf("%d", &numl) == 0 || numl <= 0)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
    }
    
    getchar(); /* Função getchar() armazena caractere "\n" presente no buffer */

    printf("\n");

    /* Comando "for" permite a impressão dos caracteres "*", decrementando uma unidade
       a cada linha.
    */
    for (cont1 = 0 ; cont1 <= numl ; ++cont1)
    {
        for (cont2 = 0 ; cont2 <= cont1 ; ++cont2)
            printf("*");

        printf("\n");

    }
    printf("\n");

 return 0;
}

/* 
    (Entrada):
    7


    (Saída):
    Insira o valor correspondente ao número de linhas a ser impresssa: 

    *
    **
    ***
    ****
    *****
    ******
    *******
    ********

*/
