#include <stdio.h>
#define TAM 10

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int n[10] = {}, cont = 0,
        min = 0, max = 0,
        par = 0, sum = 0,
        value = 0;
    char clear;
    
    for (cont = 0; cont < TAM; ++cont)   
        n[cont] = 0;
    
    printf("Insira uma sequência de dez números inteiros: \n> ");

    /* Inicializando a sequência de dez números inteiros pelo usuário */
    for (cont = 0; cont < TAM; ++cont)
    {
        while(scanf("%d", &n[cont]) == 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n> ");
        }
        printf("\n\n> ");
    }

    /* Inicializando o valor mínimo e máximo com um valor aleatório da sequência */
    min = n[0];
    max = n[0];

    /* Avaliando máximo e mínimo valores entre a sequência de dez termos */
    for (cont = 0; cont < TAM; ++cont)
    {
        if (n[cont] < min)
            min = n[cont];
        if (n[cont] > max)
            max = n[cont];

        /* Determinando número de termos pares */
        if ((n[cont] % 2) == 0)
            ++par;
        
        /* Determinando a soma de todos os termos da sequência */
        sum += n[cont];
    }

    /* Impressão dos resultados esperados pelo enunciado */
    printf("O valor mínimo da sequência a seguir é : %d\n", min);
    printf("O valor máximo da sequência a seguir é : %d\n", max);
    printf("A quantidade de termos pares da sequência são : %d\n", par);
    printf("A soma de todos os termos da sequência é : %d\n\n", sum);
    
    printf("Deseja encontrar algum valor na sequência de termos? \n\n> ");
    while (scanf("%d", &value) == 0)
    {
        clean_buf(clear);
        printf("\n [ Valor Inválido ] \n\n");
    }

    for (cont = 0; cont < TAM; ++cont)
        if (n[cont] == value) printf("\nO termo %d está na posição %d da sequência.\n\n", value, cont);

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
    5



    (Saídas):
    Insira uma sequência de dez números inteiros: 
    > 1


    > 2


    > 3


    > 4


    > 5


    > 6


    > 7


    > 8


    > 9


    > 0


    > O valor mínimo da sequência a seguir é : 0
    O valor máximo da sequência a seguir é : 9
    A quantidade de termos pares da sequência são : 5
    A soma de todos os termos da sequência é : 45

    Deseja encontrar algum valor na sequência de termos? 

    > 5
    O termo 5 está na posição 4 da sequência.

X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    11
    w
    3
    6
    y
    34
    r
    kjkj
    7
    7
    9
    0
    1
    23
    34


    (Saídas):
    Insira uma sequência de dez números inteiros: 
    > 11


    > w

     [ Valor Inválido ] 

    > 3


    > 6


    > y

     [ Valor Inválido ] 

    > 34


    > r

     [ Valor Inválido ] 

    > kjkj

     [ Valor Inválido ] 

    > 7


    > 7


    > 9


    > 0


    > 1


    > 23


    > O valor mínimo da sequência a seguir é : 0
    O valor máximo da sequência a seguir é : 34
    A quantidade de termos pares da sequência são : 3
    A soma de todos os termos da sequência é : 101

    Deseja encontrar algum valor na sequência de termos? 

    > 34
    O termo 34 está na posição 3 da sequência.

*/
