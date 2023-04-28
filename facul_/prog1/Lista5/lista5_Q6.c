#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */
    char clear;
    float mtrz[5][4],
          nt[5] = {},
          max = 0.,
          media = 0.;
    int cont1 = 0,
        cont2 = 0,
        rec = 0;

    /* Inicializando cada posição da matriz com zero */
    for (cont1 = 0; cont1 < 5; ++cont1)
        for (cont2 = 0; cont2 < 4; ++cont2)
            mtrz[cont1][cont2] = 0;

    /* Alterando primeira coluna da matriz - Matrícula */
    printf("\nInsira o número da matrícula dos alunos na Coluna 1:");

    for (cont1 = 0; cont1 < 5; ++cont1)
    {
        printf("\n\n> ");

        /* Validação para entrada de caracteres */
        while (scanf("%f", &mtrz[cont1][0]) == 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n> ");
        }
    }

    /* Alterando segunda coluna da matriz - Média das provas */
    printf("\n\nInsira a média das provas de cada aluno na Coluna 2:");

    for (cont1 = 0; cont1 < 5; ++cont1)
    {
        printf("\n\n> ");

        while (scanf("%f", &mtrz[cont1][1]) == 0 || mtrz[cont1][1] < 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n> ");
        }
    }

    /* ALterando terceira coluna da matriz - Média dos trabalhos */
    printf("\n\nInsira a média dos trabalhos na Coluna 3:");

    for (cont1 = 0; cont1 < 5; ++cont1)
    {
        printf("\n\n> ");

        while (scanf("%f", &mtrz[cont1][2]) == 0 || mtrz[cont1][2] < 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n> ");
        }
    }

    printf("\n");

    /* Cálculo da onta final + Impressão das notas de caad aluno */
    for (cont1 = 0; cont1 < 5; ++cont1)
    {
        nt[cont1] = (mtrz[cont1][1] + mtrz[cont1][2]) / 2; 

        printf("Nota final do Aluno %d : %.2f\n\n", cont1 + 1, nt[cont1]);
    }

    /* Variável "max" recebe um valor aleatório dentre os alunos */
    max = nt[0];

    /* Armazenar a maior nota final, bem como sua posição */
    for (cont1 = 0; cont1 < 5; ++cont1)
    {
        if (nt[cont1] > max)
        {
            max = nt[cont1];
            rec = cont1;    /* Variável "rec" recebe posição do aluno com maior nota */
        }
    }

    printf("Número da matrícula do aluno com a maior nota final: %d\n\n", (int)(mtrz[rec][0]));

    /* Somatório das notas finais */
    for (cont1 = 0; cont1 < 5; ++cont1)
        media += nt[cont1];
    
    printf("A média aritmética das notas finais é : %.2f\n\n", media / 5.);

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
    12
    23
    34
    45
    56
    3.4
    5.8
    1.2
    9.8
    5.4
    3
    6
    8.5
    9.4
    1.2



    (Saídas):
    Insira o número da matrícula dos alunos na Coluna 1:

    > 12


    > 23


    > 34


    > 45


    > 56


    Insira a média das provas de cada aluno na Coluna 2:

    > 3.4


    > 5.8


    > 1.2


    > 9.8


    > 5.4


    Insira a média dos trabalhos na Coluna 3:

    > 3


    > 6


    > 8.5


    > 9.4


    > 1.2

    Nota final do Aluno 1 : 3.20

    Nota final do Aluno 2 : 5.90

    Nota final do Aluno 3 : 4.85

    Nota final do Aluno 4 : 9.60

    Nota final do Aluno 5 : 3.30

    Número da matrícula do aluno com a maior nota final: 45

    A média aritmética das notas finais é : 5.37


X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    q
    12
    23
    34
    45
    t
    56
    4.5
    6.7
    3.9
    8.1
    4.9
    3
    6
    5
    8.5
    9.0
    


    (Saídas):
    Insira o número da matrícula dos alunos na Coluna 1:

    > q

     [ Valor Inválido ] 

    > 12


    > 23


    > 34


    > 45


    > t

     [ Valor Inválido ] 

    > 56


    Insira a média das provas de cada aluno na Coluna 2:

    > 4.5


    > 6.7


    > 3.9


    > 8.1


    > 4.9


    Insira a média dos trabalhos na Coluna 3:

    > 3


    > 6


    > 5


    > 8.5


    > 9.0

    Nota final do Aluno 1 : 3.75

    Nota final do Aluno 2 : 6.35

    Nota final do Aluno 3 : 4.45

    Nota final do Aluno 4 : 8.30

    Nota final do Aluno 5 : 6.95

    Número da matrícula do aluno com a maior nota final: 45

    A média aritmética das notas finais é : 5.96


*/
