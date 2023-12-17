#include <stdio.h>
#define TAM 3

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e para caracteres */
    char mtrz[3][3],
        clear; /* Para limpar buffer */
    int cont1 = 0,
        cont2 = 0,
        alert1[3] = {0, 0, 0}, /* Para Linhas */
        alert2[3] = {0, 0, 0}; /* Para Colunas */

    /* Atribuindo caracteres entre '0' e '1' nas posições da matriz */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            printf("Insira um valor entre '0' e '1' da Linha %d e Coluna %d : ", cont1, cont2);
            scanf("%c", &mtrz[cont1][cont2]);

            /* Conclui após buffer estiver limpo */
            while ((clear = getchar()) != '\n' && clear != EOF)
                ;

            /* Validação para entrada de caracteres diferentes de '0' ou '1' */
            while (mtrz[cont1][cont2] != '0' && mtrz[cont1][cont2] != '1')
            {
                printf("\n [ Valor Inválido ] \n\n>");
                scanf("%c", &mtrz[cont1][cont2]);

                /* Conclui após buffer estiver limpo */
                while ((clear = getchar()) != '\n' && clear != EOF)
                    ;

                /* Permite a "quebra" do loop caso as entradas forem válidas */
                if (mtrz[cont1][cont2] == '0' || mtrz[cont1][cont2] == '1')
                    break;
            }

            printf("\n\n");
        }

    /* Variável 'alert1' para indicar diferença entre caracteres da mesma linha,
       Variável 'alert2' para indicar diferença entre caracteres da mesma coluna. */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            if (mtrz[cont1][cont1] != mtrz[cont1][cont2])
                ++alert1[cont1];
            if (mtrz[0][cont1] != mtrz[cont2][cont1])
                ++alert2[cont1];
        }

    /* Imprimi caracteres idênticos de uma dada Linha */
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        if (alert1[cont1] == 0)
        {
            printf("Linha %d : ", cont1);

            for (cont2 = 0; cont2 < TAM; ++cont2)
                printf("%c  ", mtrz[cont1][cont2]);
        }

        printf("\n");
    }

    printf("\n\n"); /* Espaçamento */

    /* Imprimi caracteres idênticos de uma dada Coluna */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        if (alert2[cont1] == 0)
        {
            printf("Coluna %d : \n", cont1);
            for (cont2 = 0; cont2 < TAM; ++cont2)
            {
                printf("%c\n", mtrz[cont2][cont1]);
            }

            printf("\n\n");
        }

    return 0;
}

/*
    (Valores testados no programa):

    Entradas:
    0
    0
    1
    0
    0
    1
    1
    1
    1




    Saídas:
    Insira um valor entre '0' e '1' da Linha 0 e Coluna 0 : 0


    Insira um valor entre '0' e '1' da Linha 0 e Coluna 1 : 0


    Insira um valor entre '0' e '1' da Linha 0 e Coluna 2 : 1


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 0 : 0


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 1 : 0


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 2 : 1


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 0 : 1


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 1 : 1


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 2 : 1




    Linha 2 : 1  1  1


    Coluna 2 :
    1
    1
    1




X --------------------------------------------------------------------- X

    (Entradas - Tratamento de Erro):
    22
    1
    0
    1
    3
    1
    0
    1
    1
    0
    w
    1




    Saídas:
    Insira um valor entre '0' e '1' da Linha 0 e Coluna 0 : 22

    [ Valor Inválido ]

    >1


    Insira um valor entre '0' e '1' da Linha 0 e Coluna 1 : 0


    Insira um valor entre '0' e '1' da Linha 0 e Coluna 2 : 1


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 0 : 3

    [ Valor Inválido ]

    >1


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 1 : 0


    Insira um valor entre '0' e '1' da Linha 1 e Coluna 2 : 1


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 0 : 1


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 1 : 0


    Insira um valor entre '0' e '1' da Linha 2 e Coluna 2 : w

    [ Valor Inválido ]

    >1







    Coluna 0 :
    1
    1
    1


    Coluna 1 :
    0
    0
    0


    Coluna 2 :
    1
    1
    1


*/