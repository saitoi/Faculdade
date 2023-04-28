/* Exercício 9 */

#include <stdio.h>
#include <locale.h> /* Biblioteca "locale.h" permite a impressão de caracteres especiais. */
#include <stdlib.h>

/* Chamando a função situda após a "int main()." */
void pause();
int maior_zero(int n1, int n2, int n3, int n4, int n5, int n6);
int num_correto(int n1, int n2, int n4, int n5);

/* Função principal não recebe argumentos. */
int main(void)
{
    /* Declaração e inicialização de variáveis inteiras. */
    int dia1 = 0, mes1 = 0, ano1 = 0;
    int dia2 = 0, mes2 = 0, ano2 = 0;

    /* Configuração do idioma em português.*/
    setlocale(LC_ALL, "Portuguese");

    do
    {
        printf("Primeira data de nascimento seguida de um espaço entre dia, mês e ano: \n");
        scanf("%d %d %d", &dia1, &mes1, &ano1); /* Inserção de valor inteiro nas variáveis da data de nascimento */
        printf("Segunda data de nascimento seguida de um espaço entre dia, mês e ano: \n");
        scanf("%d %d %d", &dia2, &mes2, &ano2); /* Inserção de valor inteiro em data de nascimento */

        if ((maior_zero(dia1, mes1, ano1, dia2, mes2, ano2) == 0) || (num_correto(dia1, mes1, dia2, mes2) == 0))
        {
            printf("Valores incorretos.. Tente novamente, aperte 'ENTER'.");
            pause();
        }

    } while ((maior_zero(dia1, mes1, ano1, dia2, mes2, ano2) == 0) || (num_correto(dia1, mes1, dia2, mes2) == 0));

    if ((ano1 == ano2) && (mes1 == mes2) && (dia1 == dia2))
        printf("Mesmo dia.\n");
    else if ((ano1 < ano2) || ((ano1 == ano2) && (mes1 < mes2)) || ((ano1 == ano2) && (mes1 == mes2) && (dia1 < dia2)))
        printf("Primeiro é mais velho.\n");
    else
        printf("Segundo é mais velho.\n");

    return 0;
}

void pause()
{
    /* Função permite "pausar" tela até identificação de caractere. */
    getchar();
    getchar();
}

int num_correto(int n1, int n2, int n4, int n5)
{
    if ((n1 > 31) || (n2 > 12) || (n4 > 31) || (n5 > 12))
        return 0;
    else
        return 1;
}

int maior_zero(int n1, int n2, int n3, int n4, int n5, int n6)
{
    if ((n1 < 0) || (n2 < 0) || (n3 < 0) || (n4 < 0) || (n5 < 0) || (n6 < 0))
        return 0;
    else
        return 1;
}

/*
    Valores testados no programa:

    (Entradas):
    30
    10
    2004
    13
    11
    2002


    (Saídas):
    Primeira data de nascimento seguida de um espaço entre dia, mês e ano:
    Segunda data de nascimento seguida de um espaço entre dia, mês e ano:

    Segundo é mais velho.

    X --------------------------------------------------------- X

    (Entradas - Tratamento de erro):
    44
    12
    2001
    -5
    21
    1001

    30
    11
    2005
    4
    8
    2022

    (Saídas):
    Primeira data de nascimento seguida de um espaço entre dia, mês e ano:
    Segunda data de nascimento seguida de um espaço entre dia, mês e ano:
    Valores incorretos.. Tente novamente, aperte 'ENTER'.

    Primeira data de nascimento seguida de um espaço entre dia, mês e ano:
    Segunda data de nascimento seguida de um espaço entre dia, mês e ano:

    Primeiro é mais velho.

*/
