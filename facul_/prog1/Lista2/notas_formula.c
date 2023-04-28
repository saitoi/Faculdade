/*

Programas: entrada_saida.c ;
Autor: Pedro Henrique Honorio Saito ;
Data : 29/09/2022 ;
Descrição: Resolução da lista de exercícios do 5 ao 9 ;

*/

/* Exercício 5 */
#include <stdio.h>
#include <locale.h> /* Biblioteca "locale.h" permite a impressão de caracteres especiais. */

/* Chamando a função situda após a "int main()." */
void pause();

/* Função principal não recebe argumentos. */
int main(void)
{
    /* Declaração e inicialização das variáveis em ponto flutuante. */
    float tst1 = 0., tst2 = 0., tst3 = 0.; /* "teste 1", "teste 2" e "teste 3".*/
    float prova = 0., ntfinal = 0.;

    /* Configuração do idioma em português.*/
    setlocale(LC_ALL, "Portuguese");

    /* Comando "do while" empregado para tratamento de erro. */
    do
    {
        printf("Insira o valor correspondente a prova: ");
        scanf("%f", &prova); /* Inserção de valor na variável "prova". */
        printf("Insira o valor referente ao primeiro teste: ");
        scanf("%f", &tst1); /* Inserção de valor na variável "tst1". */
        printf("Insira o valor referente ao segundo teste: ");
        scanf("%f", &tst2); /* Inserção de valor em "tst2". */
        printf("Insira o valor referente ao terceiro teste: ");
        scanf("%f", &tst3); /* Inserção de valor em "tst3". */

        /* Condicional para valores incorretos. */
        if ((tst1 < 0) || (tst2 < 0) || (tst3 < 0) || (prova < 0))
        {
            printf("Valores incorretos.. Tente novamente, aperte 'ENTER'.\n");
            pause();
        }
    } while ((tst1 < 0) || (tst2 < 0) || (tst3 < 0) || (prova < 0));

    /* Cáculo da nota final pela forma indicada. */
    ntfinal = ((0.8 * prova) + 0.2 * ((tst1 + tst2 + tst3) / 3));

    /* Impressão dos resutlados de saída: */
    printf("Prova: %.1f\n", prova);
    printf("Teste 1: %.1f\n", tst1);
    printf("Teste 2: %.1f\n", tst2);
    printf("Teste 3: %.1f\n", tst3);
    printf("Nota final: %.1f\n", ntfinal);

    return 0;
}

void pause()
{
    /* Função permite "pausar" tela até identificação de caractere. */
    getchar();
    getchar();
}

/*
    Valores testados no programa:

    (Entradas):
    6
    5
    7
    8


    (Saídas):
    Insira o valor referente ao primeiro teste:
    Insira o valor referente ao segundo teste:
    Insira o valor referente ao terceiro teste:
    Insira o valor correspondente a prova:

    Prova: 8.0
    Teste 1: 6.0
    Teste 2: 5.0
    Teste 3: 7.0
    Nota final: 7.6

 X --------------------------------------------------------- X

    (Entradas - Tratamento de erro):
    -1
    3 
    7
    -5

    4
    5
    9
    10


    (Saídas):
    Insira o valor referente ao primeiro teste:
    Insira o valor referente ao segundo teste:
    Insira o valor referente ao terceiro teste:
    Insira o valor correspondente a prova:
    Valores incorretos.. Tente novamente, aperte 'ENTER'.

    Prova: 10.0
    Teste 1: 4.0
    Teste 2: 5.0
    Teste 3: 9.0
    Nota final: 9.2

*/
