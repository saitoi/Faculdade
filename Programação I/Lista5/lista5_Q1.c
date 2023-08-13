#include <stdio.h>
#include <string.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);
int count_char(char wrd, char strn[100]);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e vetores */
    int cont1 = 0,
        cont2 = 0,
        select = 0;
    char str1[100] = {},
         str2[100] = {},
         clear,
         wrd;

    /* Modificando conteúdo de string 1 ("str1") */
    printf("Digite o conteúdo referente a primeira string (sem espaço): \n> ");
    scanf("%s", str1);

    /* Chamando função para limpar buffer */
    clean_buf(clear);

    /* Modificando conteúdo de string 2 ("str2") */
    printf("Digite o conteúdo referente a segunda string (sem espaço): \n> ");
    scanf("%s", str2);
    clean_buf(clear);

    /* Função "strlen" para contar número de caracteres na string 1 & 2 */
    cont1 = strlen(str1);
    cont2 = strlen(str2);

    do
    {
        /* Menu principal com cada função */
        printf("\n  [ MENU ]  \n\n");
        printf(" 1 - Inversão das strings\n");
        printf(" 2 - Concatenação das strings\n");
        printf(" 3 - Comparação de strings\n");
        printf(" 4 - Aparição de dado caractere\n");
        printf(" 5 - ENCERRE \n\n");

        printf("Selecione a opção referente a função deseajda: \n> ");
        while (scanf("%d", &select) == 0)
        {
            clean_buf(clear);
            printf("\n [ Valor Inválido ] \n\n");
        }

        switch (select)
        {
        case 1:
            printf("A inversão da primeira string resulta em: \n");

            /* Contador que "vai" do último caractere para o primeiro na string 1 */
            for (; cont1 > -1; --cont1)
                printf("%c", str1[cont1]);

            printf("\n\nA inversão da segunda string resulta em: \n");

            /* Contador "vai" do último caractere para o primeiro na string 2 */
            for (; cont2 > -1; --cont2)
                printf("%c", str2[cont2]);

            break;

        case 2:

            /* Função para concatenar as duas strings inseridas */
            strcat(str1, str2);
            printf("A concatenação de ambas strings resulta em: \n> %s", str1);

            break;

        case 3:
            if (cont1 > cont2)
                printf("A primeira string \"str1\" é maior que a segunda string \"str2\".\n");
            else if (cont1 == cont2)
                printf("As duas strings \"str1\" e \"str2\" tem o mesmo tamanho.\n");
            else
                printf("A segunda string string \"str2\" é maior que a primeira string \"str1\".\n");

            break;

        case 4:
            printf("Escolha o caractere que deseja contar o número de repetições: \n> ");
            wrd = getchar();
            clean_buf(clear);

            /* Função "count_char(..)" retorna valor inteiro correspondente ao número de caracteres repetidos */
            printf("O número de vezes que o caractere %c aparece na primeira string é %d\n", wrd, count_char(wrd, str1));
            printf("O número de vezes que o caractere %c aparece na primeira string é %d\n\n", wrd, count_char(wrd, str2));

            break;

        case 5:
            printf("Processo encerrado..\n");
            return 0;
            
            break;
        }

        printf("\n\n");
    } while (1);

    return 0;
}

void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF)
        ;
}

int count_char(char wrd, char strn[100])
{
    int cont1, cont2 = 0;
    for (cont1 = 0; cont1 != '\0'; ++cont1)
        if (strn[cont1] == wrd)
            ++cont2;

    return cont2;
}
