#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);


/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int mtrz1[2][3] = {},
        mtrz2[2][3] = {},
        cont1 = 0,
        cont2 = 0;
    char clear;

    /* Inserção de valores na primeira matriz */
    for (cont1 = 0; cont1 < 2; ++cont1)
        for (cont2 = 0; cont2 < 3; ++cont2)
        {
            printf("Altere o valor na Linha %d e Coluna %d na Matriz 1: ",cont1 ,cont2);
            
            /* Comando de repetição para validação de caracteres */
            while(scanf("%d", &mtrz1[cont1][cont2]) == 0)
            {
                clean_buf(clear);
                printf("\n [ Valor Inválido ].. \n\n>");
            }

            printf("\n");
        }

    /* Inserção de valores na segunda matriz */
    for (cont1 = 0; cont1 < 2; ++cont1)
        for (cont2 = 0; cont2 < 3; ++cont2)
        {
            printf("Altere o valor na Linha %d e Coluna %d na Matriz 2: ",cont1 ,cont2);
            
            /* Comando de repetição para validação de caracteres */
            while(scanf("%d", &mtrz2[cont1][cont2]) == 0)
            {
                clean_buf(clear);
                printf("\n [ Valor Inválido ].. \n\n>");
            }

            printf("\n");
        }

    printf("A matriz resultante está exibida abaixo: \n");

    /* Impressão dos valores da soma de ambas as matrizes */
    for (cont1 = 0; cont1 < 2; ++cont1)
    {
        for (cont2 = 0; cont2 < 3; ++cont2)
            printf("%d  ", mtrz1[cont1][cont2] + mtrz2[cont1][cont2]);
        
        printf("\n");
    }
    
    printf("\n\n");

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}

/*
    Valores testados no programa:

    (Entradas):
    1
    2
    3
    4
    5
    6
    7
    8
    9
    0
    1
    2



    (Saídas):
    Altere o valor na Linha 0 e Coluna 0 na Matriz 1: 1

    Altere o valor na Linha 0 e Coluna 1 na Matriz 1: 2

    Altere o valor na Linha 0 e Coluna 2 na Matriz 1: 3

    Altere o valor na Linha 1 e Coluna 0 na Matriz 1: 4

    Altere o valor na Linha 1 e Coluna 1 na Matriz 1: 5

    Altere o valor na Linha 1 e Coluna 2 na Matriz 1: 6

    Altere o valor na Linha 0 e Coluna 0 na Matriz 2: 7

    Altere o valor na Linha 0 e Coluna 1 na Matriz 2: 8

    Altere o valor na Linha 0 e Coluna 2 na Matriz 2: 9

    Altere o valor na Linha 1 e Coluna 0 na Matriz 2: 0

    Altere o valor na Linha 1 e Coluna 1 na Matriz 2: 1

    Altere o valor na Linha 1 e Coluna 2 na Matriz 2: 2

    A matriz resultante está exibida abaixo: 
    8  10  12  
    4  6  8  


X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    1
    2
    3
    w
    4
    5
    6
    yu
    8
    9
    0
    5
    e
    3


    (Saídas):
    Altere o valor na Linha 0 e Coluna 0 na Matriz 1: 1

    Altere o valor na Linha 0 e Coluna 1 na Matriz 1: 2

    Altere o valor na Linha 0 e Coluna 2 na Matriz 1: 3

    Altere o valor na Linha 1 e Coluna 0 na Matriz 1: w

     [ Valor Inválido ].. 

    >4

    Altere o valor na Linha 1 e Coluna 1 na Matriz 1: 5

    Altere o valor na Linha 1 e Coluna 2 na Matriz 1: 6

    Altere o valor na Linha 0 e Coluna 0 na Matriz 2: yu

     [ Valor Inválido ].. 

    >7

    Altere o valor na Linha 0 e Coluna 1 na Matriz 2: 8

    Altere o valor na Linha 0 e Coluna 2 na Matriz 2: 9

    Altere o valor na Linha 1 e Coluna 0 na Matriz 2: 0

    Altere o valor na Linha 1 e Coluna 1 na Matriz 2: 5

    Altere o valor na Linha 1 e Coluna 2 na Matriz 2: e

     [ Valor Inválido ].. 

    >3

    A matriz resultante está exibida abaixo: 
    8  10  12  
    4  10  9  


*/
