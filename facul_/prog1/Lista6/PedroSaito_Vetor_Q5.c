#include <stdio.h>

/* Função situada após "int main" */
void space(int cont1);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e para caracteres */
    char mtrz[3][3],
        clear; /* Para limpar buffer */
    int cont1 = 0,
        cont2 = 0,
        alert1[3] = {0, 0, 0}, /* Para Linhas */
        alert2[3] = {0, 0, 0}, /* Para Colunas */
        alertd[2] = {0, 0};    /* Para Diagonais */
    int TAM = 3, select = 0;

    printf("Selecione o tamanho da matriz dentre as seguintes opções : \n");
    printf("\n|  (1). 3 x 3  |  (2). 20 x 20  |\n\n>");

    while (scanf("%d", &select) == 0 || select != 1 && select != 2)
    {
        /* Conclui após buffer estiver limpo */
        while ((clear = getchar()) != '\n' && clear != EOF);

        printf("\n [ Valor Inválido ] \n\n");
    }

    /* Converte a matriz 3 x 3 para 20 x 20 */
    if (select == 2)
        TAM = 20;

    getchar();

    /* Atribuindo caracteres entre '0' e '1' nas posições da matriz */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        for (cont2 = 0; cont2 < TAM; ++cont2)
        {
            printf("Insira um caracter entre '0' e '1' da Linha %d e Coluna %d : ", cont1, cont2);
            scanf("%c", &mtrz[cont1][cont2]);

            /* Conclui após buffer estiver limpo */
            while ((clear = getchar()) != '\n' && clear != EOF);

            /* Validação para entrada de caracteres diferentes de '0' ou '1' */
            while (mtrz[cont1][cont2] != '0' && mtrz[cont1][cont2] != '1')
            {
                printf("\n [ Valor Inválido ] \n\n>");
                scanf("%c", &mtrz[cont1][cont2]);

                /* Conclui após buffer estiver limpo */
                while ((clear = getchar()) != '\n' && clear != EOF);

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

    /* Variável 'alertd' para indicar diferenças entre caracteres da mesma diagonal. */
    for (cont1 = 0; cont1 < TAM; ++cont1)
    {
        if (mtrz[0][0] != mtrz[cont1][cont1])
            ++alertd[0];
        if (mtrz[1][1] != mtrz[2 - cont1][cont1])
            ++alertd[1];
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

    /* Imprimi caracteres idênticos de uma dada Coluna */
    for (cont1 = 0; cont1 < TAM; ++cont1)
        if (alert2[cont1] == 0)
        {
            printf("Coluna %d : \n", cont1);
            for (cont2 = 0; cont2 < TAM; ++cont2)
                printf("%c\n", mtrz[cont2][cont1]);

            printf("\n\n");
        }

    /* Imprimi caracteres idênticos da "primeira" diagonal */
    if (alertd[0] == 0)
    {
        printf("Diagonal %d : \n", 0);
        for (cont1 = 0; cont1 < TAM; ++cont1)
        {
            space(TAM + cont1);
            printf("%c\n", mtrz[cont1][cont1]);
        }
    }

    /* Imprimi caracteres idênticos da "segunda" diagonal */
    if (alertd[1] == 0)
    {
        printf("Diagonal %d : \n", 1);
        for (cont1 = 0; cont1 < TAM; ++cont1)
        {
            space(2 * TAM - cont1);
            printf("%c\n", mtrz[2 - cont1][cont1]);
        }
    }

    return 0;
}

/* Função para impressão do espaço ' ' um número de vezes igual a "cont1" */
void space(int cont1)
{
    int i;
    for (i = 0; i < cont1; ++i)
        printf(" ");
}

/*
    (Valores testados no programa):

    Entradas:
    1
    1
    1
    0
    1
    0
    1
    0
    1
    1




    Saídas:
    Selecione o tamanho da matriz dentre as seguintes opções :

    |  (1). 3 x 3  |  (2). 20 x 20  |

    >1
    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 0 : 1


    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 1 : 1


    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 2 : 0


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 0 : 1


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 1 : 0


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 2 : 1


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 0 : 0


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 1 : 1


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 2 : 1





    Diagonal 1 :
          0
         0
        0



X --------------------------------------------------------------------- X

    (Entradas - Tratamento de Erro):
    qw
    1
    9
    1
    0
    1
    1
    p
    0
    1
    2
    1
    0
    1




    Saídas:
    Selecione o tamanho da matriz dentre as seguintes opções :

    |  (1). 3 x 3  |  (2). 20 x 20  |

    >qw

     [ Valor Inválido ]

    1
    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 0 : 9

     [ Valor Inválido ]

    >1


    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 1 : 0


    Insira um caracter entre '0' e '1' da Linha 0 e Coluna 2 : 1


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 0 : 1


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 1 : p

     [ Valor Inválido ]

    >0


    Insira um caracter entre '0' e '1' da Linha 1 e Coluna 2 : 1


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 0 : 2

     [ Valor Inválido ]

    >1


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 1 : 0


    Insira um caracter entre '0' e '1' da Linha 2 e Coluna 2 : 1





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