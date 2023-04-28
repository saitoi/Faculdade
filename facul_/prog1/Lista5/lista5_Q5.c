#include <stdio.h>
#define TAM 5

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    char clear;
    int x[5] = {},
        y[5] = {},
        c[5] = {},
        d[5] = {},
        cont1 = 0,
        cont2 = 0;

    printf("\nInsira uma sequência de números inteiros distintos no Vetor X:");
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        printf("\n\n> ");

        /* Validação para a entrada de caracteres */
        while (scanf("%d", &x[cont1]) == 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n>");
        }
    }

    printf("\n\nInsira uma sequência de números inteiros distintos no Vetor Y:");
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        printf("\n\n> ");

        /* Mais validação para a entrada de caracteres */
        while (scanf("%d", &y[cont1]) == 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n>");
        }
    }

    /* Soma de cada posição do vetor X com sua posição correspondente em Y */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        printf("\nA soma da posição [%d] das matrizes X e Y: %d\n\n", cont1, x[cont1] + y[cont1]);

    printf("\n\n");

    /* Produto de cada posição do vetor X com sua posição correspondente em Y */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        printf("O produto da posição [%d] das matrizes X e Y: %d\n\n", cont1, x[cont1] * y[cont1]);

    printf("\n\n");
    printf("A sequência de termos contida em X que não pertence a Y é:\n\n");

    /* "Marca" quais valores são repetidos tanto na matriz X quanto na Y */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            if (x[cont1] == y[cont2])
                ++c[cont1];
            if (y[cont1] == x[cont2])
                ++d[cont1];
        }

    for (cont1 = 0; cont1 < TAM; ++cont1)
        if (c[cont1] == 0)
            printf("O valor X [%d] = %d\n\n", cont1, x[cont1]);

    printf("A sequência de termos pertencentes tanto a X quanto a Y :\n\n");

    /* Avalia a intersecção dos valroes contidos tanto em X quanto em Y */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        if (c[cont1] > 0)
            printf("O valor X [%d] = %d\n\n", cont1, x[cont1]);

    printf("A união da sequência de termos contida tanto em X quanto em Y :\n\n");

    /* União dos vetores X e Y equivalente aos termos contidos apenas em X
       apenas em Y e na intersecção de ambos os vetores.
    */
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        if (c[cont1] == 0)
            printf("A união de termos contidos em (X U Y) [%d] = %d\n\n", cont1, x[cont1]);
        if (d[cont1] == 0)
            printf("A união de termos contidos em (X U Y) [%d] = %d\n\n", cont1, y[cont1]);
        if (c[cont1] > 0)
            printf("A união de termos contidos em (X U Y) [%d] = %d\n\n", cont1, x[cont1]);
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
    8
    7
    6
    5
    4


    (Saídas):
    Insira uma sequência de números inteiros distintos no Vetor X:

    > 1


    > 2


    > 3


    > 4


    > 5


    Insira uma sequência de números inteiros distintos no Vetor Y:

    > 8


    > 7


    > 6


    > 5


    > 4

    A soma da posição [0] das matrizes X e Y: 9


    A soma da posição [1] das matrizes X e Y: 9


    A soma da posição [2] das matrizes X e Y: 9


    A soma da posição [3] das matrizes X e Y: 9


    A soma da posição [4] das matrizes X e Y: 9



    O produto da posição [0] das matrizes X e Y: 8

    O produto da posição [1] das matrizes X e Y: 14

    O produto da posição [2] das matrizes X e Y: 18

    O produto da posição [3] das matrizes X e Y: 20

    O produto da posição [4] das matrizes X e Y: 20



    A sequência de termos contida em X que não pertence a Y é:

    O valor X [0] = 1

    O valor X [1] = 2

    O valor X [2] = 3

    A sequência de termos pertencentes tanto a X quanto a Y :

    O valor X [3] = 4

    O valor X [4] = 5

    A união da sequência de termos contida tanto em X quanto em Y :

    A união de termos contidos em (X U Y) [0] = 1

    A união de termos contidos em (X U Y) [0] = 8

    A união de termos contidos em (X U Y) [1] = 2

    A união de termos contidos em (X U Y) [1] = 7

    A união de termos contidos em (X U Y) [2] = 3

    A união de termos contidos em (X U Y) [2] = 6

    A união de termos contidos em (X U Y) [3] = 4

    A união de termos contidos em (X U Y) [4] = 5


X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    pp
    3
    4
    5
    q
    1
    2
    9
    7
    g
    6
    5
    43



    (Saídas):
    Insira uma sequência de números inteiros distintos no Vetor X:

    > pp

     [ Valor Inválido ] 

    >3


    > 4


    > 5


    > q

     [ Valor Inválido ] 

    >1


    > 2


    Insira uma sequência de números inteiros distintos no Vetor Y:

    > 9


    > 7


    > g

     [ Valor Inválido ] 

    >6


    > 5


    > 43

    A soma da posição [0] das matrizes X e Y: 12


    A soma da posição [1] das matrizes X e Y: 11


    A soma da posição [2] das matrizes X e Y: 11


    A soma da posição [3] das matrizes X e Y: 6


    A soma da posição [4] das matrizes X e Y: 45



    O produto da posição [0] das matrizes X e Y: 27

    O produto da posição [1] das matrizes X e Y: 28

    O produto da posição [2] das matrizes X e Y: 30

    O produto da posição [3] das matrizes X e Y: 5

    O produto da posição [4] das matrizes X e Y: 86



    A sequência de termos contida em X que não pertence a Y é:

    O valor X [0] = 3

    O valor X [1] = 4

    O valor X [3] = 1

    O valor X [4] = 2

    A sequência de termos pertencentes tanto a X quanto a Y :

    O valor X [2] = 5

    A união da sequência de termos contida tanto em X quanto em Y :

    A união de termos contidos em (X U Y) [0] = 3

    A união de termos contidos em (X U Y) [0] = 9

    A união de termos contidos em (X U Y) [1] = 4

    A união de termos contidos em (X U Y) [1] = 7

    A união de termos contidos em (X U Y) [2] = 6

    A união de termos contidos em (X U Y) [2] = 5

    A união de termos contidos em (X U Y) [3] = 1

    A união de termos contidos em (X U Y) [4] = 2

    A união de termos contidos em (X U Y) [4] = 43


*/
