#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após a "int main" */
void clean_buf(char clear);
int size_str(char str[100]);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e cadeias de caracteres */
    int cont1 = 0,
        cont2 = 0,
        cont3 = 0,
        select = 0;
    char str1[100] = {},
         str2[100] = {},
         str3[100] = {},
         clear, /* Permite "limpar" o buffer */
         wrd;

    printf("\n\nDigite o conteúdo referente a primeira string (sem espaço): \n> ");
    scanf("%s", str1);

    /* Função permite limpar buffer */
    clean_buf(clear);

    /* Modificando conteúdo de string 2 ("str2") */
    printf("Digite o conteúdo referente a segunda string (sem espaço): \n> ");
    scanf("%s", str2);
    clean_buf(clear);

    /* Impressão do menu principal com cada função */
    printf("\n [ MENU ]\n\n");
    printf(" 1 - Inversão das strings\n");
    printf(" 2 - Concatenação das strings\n");
    printf(" 3 - Comparação de strings\n");
    printf(" 4 - Aparição de dado caractere\n");
    printf(" 5 - ENCERRE \n\n");

    printf("Selecione a opção referente a função desejada: \n> ");
    while (scanf("%d", &select) == 0 || select < 0 || select > 5)
    {
        clean_buf(clear);
        printf("\n [ Valor Inválido ] \n\n> ");
    }

    /* Seleção da função desejada */
    switch (select)
    {
    case 1:
        printf("A inversão da primeira string resulta em: \n");

        /* Contador que "vai" do último caractere para o primeiro na string 1 */
        for (cont1 = size_str(str1); cont1 > -1; --cont1)
            printf("%c", str1[cont1]);

        printf("\n\nA inversão da segunda string resulta em: \n");

        /* Contador "vai" do último caractere para o primeiro na string 2 */
        for (cont2 = size_str(str2); cont2 > -1; --cont2)
            printf("%c", str2[cont2]);

        break;
    case 2:

        for (cont1 = 0; str1[cont1] != '\0'; ++cont1, ++cont2)
            str3[cont2] = str1[cont1];
        cont1 = 0;

        for (cont1 = 0; str2[cont1] != '\0'; ++cont1, ++cont2)
            str3[cont2] = str2[cont1];

        printf("\nA concatenação de ambas strings resulta em: \n> %s", str3);

        break;
    case 3:

        if (size_str(str1) > size_str(str2))
            printf("\nA primeira string \"str1\" é maior que a segunda \"str2\".\n\n");
        else if (size_str(str1) == size_str(str2))
            printf("\nAs duas strings \"str1\" e \"str2\" possuem o mesmo tamanho.\n\n");
        else
            printf("\nA segunda string \"str2\" é maior que a primeira \"str1\".\n\n ");

        break;
    case 4:
        clean_buf(clear);

        /* Informando qual caractere o programa necessita avaliar o número de repetições */
        printf("Selecione o caractere que deseja contar o número de repetições: \n>");
        scanf("%c", &wrd);
        clean_buf(clear);

        /* Informa a posição do caractere + número de ocorrências */
        while (str1[cont1] != '\0')
        {
            if (str1[cont1] == wrd)
            {
                ++cont2;
                printf("Posições do caractere %c na primeira string: %d\n", wrd, cont1);
           }
            ++cont1;
        }

        printf("Número de repetições do caractere %c na primeira string: %d\n\n", wrd, cont2);
        cont2 = 0;
        cont1 = 0;

        while (str2[cont1] != '\0')
        {
            if (str2[cont1] == wrd)
            {
                ++cont2;
                printf("Posições do caractere %c na segunda string: %d\n", wrd, cont1);
           }
            ++cont1;
        }

        printf("Número de repetições do caractere %c na segunda string: %d\n\n", wrd, cont2);

        break;
    case 5:

        /* Encerramento do programa */
        printf("Programa encerrado..\n\n");
        return 0;

        break;
    default:

        printf("\n [ Valor Inválido ] ..\n\nPrograma encerrado..");
        break;
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

/* Função para contar número de caracteres da string */
int size_str(char str[100])
{
    int cont = 0;
    while (str[cont] != '\0')
        ++cont;

    return cont;
}

/*
    Valores testados no programa:

    (Entradas):
    palavra
    word
    1


    (Saídas):
    Digite o conteúdo referente a primeira string (sem espaço): 
    > palavra 
    Digite o conteúdo referente a segunda string (sem espaço): 
    > word

     [ MENU ]

     1 - Inversão das strings
     2 - Concatenação das strings
     3 - Comparação de strings
     4 - Aparição de dado caractere
     5 - ENCERRE 

    Selecione a opção referente a função desejada: 
    > 1
    A inversão da primeira string resulta em: 
    arvalap

    A inversão da segunda string resulta em: 
    drow


X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):
    cadeia
    decaracteres
    -1
    9
    4
    a


    (Saídas):
    Digite o conteúdo referente a primeira string (sem espaço): 
    > cadeia 
    Digite o conteúdo referente a segunda string (sem espaço): 
    > decaracteres

     [ MENU ]

     1 - Inversão das strings
     2 - Concatenação das strings
     3 - Comparação de strings
     4 - Aparição de dado caractere
     5 - ENCERRE 

    Selecione a opção referente a função desejada: 
    > -1

     [ Valor Inválido ] 

    > 9

     [ Valor Inválido ] 

    > 4
    Selecione o caractere que deseja contar o número de repetições: 
    >a
    Posições do caractere a na primeira string: 1
    Posições do caractere a na primeira string: 5
    Número de repetições do caractere a na primeira string: 2

    Posições do caractere a na segunda string: 3
    Posições do caractere a na segunda string: 5
    Número de repetições do caractere a na segunda string: 2

*/
