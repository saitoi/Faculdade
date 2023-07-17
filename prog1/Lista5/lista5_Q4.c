#include <stdio.h>
#define TAM 5

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */
    int mtrz1[5][5] = {}, mtrz2[5][5] = {}, mtrzr[5][5] = {},
    cont1 = 0, cont2 = 0, cont3 = 0,
    aux = 0;
    char clear;

    /* Inserindo valores inteiros na primeira matriz */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            printf("Altere o valor na Linha %d e Coluna %d na Matriz 1 : ", cont1, cont2);
            while (scanf("%d", &mtrz1[cont1][cont2]) == 0)
            {
                clean_buf(clear);
                printf("\n [ Valor Inváido ] \n\n>");
            }
        }

    /* Inserindo valores inteiros na segunda matriz */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            printf("Altere o valor na Linha %d e Coluna %d na Matriz 2 : ", cont1, cont2);
            while (scanf("%d", &mtrz2[cont1][cont2]) == 0)
            {
                clean_buf(clear);
                printf("\n [ Valor Inváido ] \n\n>");
            }
        }
    
    /* Algoritmo para multiplicação de ambas as matrizes */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            aux = 0;
            for (cont3 = 0; cont3 < TAM; ++cont3)
                aux = mtrz1[cont1][cont3] * mtrz2[cont3][cont2];
            mtrzr[cont1][cont2] = aux;
        }
    
    printf("\n\nA matriz resultante está exibida abaixo: \n");

    /* Impressão da matriz resultante */
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        for (cont2 = 0; cont2 < TAM; ++cont2)
            printf("%d  ", mtrzr[cont1][cont2]);
        
        printf("\n");
    }
        

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
    3
    4
    5
    6
    7
    8
    9
    0
    


    (Saídas):
    Altere o valor na Linha 0 e Coluna 0 na Matriz 1 : 1
    Altere o valor na Linha 0 e Coluna 1 na Matriz 1 : 2
    Altere o valor na Linha 0 e Coluna 2 na Matriz 1 : 3
    Altere o valor na Linha 0 e Coluna 3 na Matriz 1 : 4
    Altere o valor na Linha 0 e Coluna 4 na Matriz 1 : 5
    Altere o valor na Linha 1 e Coluna 0 na Matriz 1 : 6
    Altere o valor na Linha 1 e Coluna 1 na Matriz 1 : 7
    Altere o valor na Linha 1 e Coluna 2 na Matriz 1 : 8
    Altere o valor na Linha 1 e Coluna 3 na Matriz 1 : 9
    Altere o valor na Linha 1 e Coluna 4 na Matriz 1 : 0
    Altere o valor na Linha 2 e Coluna 0 na Matriz 1 : 1
    Altere o valor na Linha 2 e Coluna 1 na Matriz 1 : 2
    Altere o valor na Linha 2 e Coluna 2 na Matriz 1 : 3
    Altere o valor na Linha 2 e Coluna 3 na Matriz 1 : 4
    Altere o valor na Linha 2 e Coluna 4 na Matriz 1 : 5
    Altere o valor na Linha 3 e Coluna 0 na Matriz 1 : 6
    Altere o valor na Linha 3 e Coluna 1 na Matriz 1 : 7
    Altere o valor na Linha 3 e Coluna 2 na Matriz 1 : 8
    Altere o valor na Linha 3 e Coluna 3 na Matriz 1 : 9
    Altere o valor na Linha 3 e Coluna 4 na Matriz 1 : 0
    Altere o valor na Linha 4 e Coluna 0 na Matriz 1 : 1
    Altere o valor na Linha 4 e Coluna 1 na Matriz 1 : 2
    Altere o valor na Linha 4 e Coluna 2 na Matriz 1 : 3
    Altere o valor na Linha 4 e Coluna 3 na Matriz 1 : 4
    Altere o valor na Linha 4 e Coluna 4 na Matriz 1 : 5
    Altere o valor na Linha 0 e Coluna 0 na Matriz 2 : 6
    Altere o valor na Linha 0 e Coluna 1 na Matriz 2 : 7
    Altere o valor na Linha 0 e Coluna 2 na Matriz 2 : 8
    Altere o valor na Linha 0 e Coluna 3 na Matriz 2 : 9
    Altere o valor na Linha 0 e Coluna 4 na Matriz 2 : 0
    Altere o valor na Linha 1 e Coluna 0 na Matriz 2 : 1
    Altere o valor na Linha 1 e Coluna 1 na Matriz 2 : 2
    Altere o valor na Linha 1 e Coluna 2 na Matriz 2 : 3
    Altere o valor na Linha 1 e Coluna 3 na Matriz 2 : 4
    Altere o valor na Linha 1 e Coluna 4 na Matriz 2 : 5
    Altere o valor na Linha 2 e Coluna 0 na Matriz 2 : 6
    Altere o valor na Linha 2 e Coluna 1 na Matriz 2 : 7
    Altere o valor na Linha 2 e Coluna 2 na Matriz 2 : 8
    Altere o valor na Linha 2 e Coluna 3 na Matriz 2 : 9
    Altere o valor na Linha 2 e Coluna 4 na Matriz 2 : 0
    Altere o valor na Linha 3 e Coluna 0 na Matriz 2 : 1
    Altere o valor na Linha 3 e Coluna 1 na Matriz 2 : 2
    Altere o valor na Linha 3 e Coluna 2 na Matriz 2 : 3
    Altere o valor na Linha 3 e Coluna 3 na Matriz 2 : 4
    Altere o valor na Linha 3 e Coluna 4 na Matriz 2 : 5
    Altere o valor na Linha 4 e Coluna 0 na Matriz 2 : 6
    Altere o valor na Linha 4 e Coluna 1 na Matriz 2 : 7
    Altere o valor na Linha 4 e Coluna 2 na Matriz 2 : 8
    Altere o valor na Linha 4 e Coluna 3 na Matriz 2 : 9
    Altere o valor na Linha 4 e Coluna 4 na Matriz 2 : 0


    A matriz resultante está exibida abaixo: 
    30  35  40  45  0  
    0   0   0   0   0  
    30  35  40  45  0  
    0   0   0   0   0  
    30  35  40  45  0

*/
