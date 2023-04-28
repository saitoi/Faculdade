/* Exercício 6 */
#include <stdio.h>
#include <locale.h> /* Biblioteca "locale.h" permite a impressão de caracteres especiais. */

/* Chamando a função situda após a "int main()." */
void pause();

/* Função principal não recebe argumentos. */
int main(void)
{
    /* Declaração e inicialização da variável inteira. */
    int n = 0;

    /* Configuração do idioma em português.*/
    setlocale(LC_ALL, "Portuguese");

    do
    {
        printf("Insira um valor qualquer inteiro e positivo: ");
        scanf("%d", &n);

        /* Tratamento de erro caso usuário insira valor menor que zero */
        if (n < 0)
        {
            printf("Valor incorreto.. Tente novamente, aperte 'ENTER'.\n");
            pause();
        }

    } while (n < 0);

    /* Fórmula de somatório de todos os termos de uma progressão aritmética (PA). */
    printf("O somatório dos termos entre 0 e %d é: %d\n", n, (n * (n + 1)) / 2);

    return 0;
}

void pause()
{
    /* Função para "pausar" tela até identificaçãp de caractere */
    getchar();
    getchar();
}

/*
    Valores testados no programa:

    (Entradas):
    44


    (Saídas):
    Insira um valor qualquer inteiro e positivo:
    O somatório dos termos entre 0 e 44 é: 990
    

X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    -1

    30

    (Saídas):
    Insira um valor qualquer inteiro e positivo:
    Valor incorreto.. Tente novamente, aperte 'ENTER'.

    Insira um valor qualquer inteiro e positivo:
    O somatório dos termos entre 0 e 30 é: 465

*/
