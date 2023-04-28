#include <stdio.h>

int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int mes = 0;
    
    printf("Insira o valor correspondente ao mês : ");

    /* Validação da entrada para caracteres e valores compreeendidos fora do 
       intervalo de 0 a 12. Atribuição do valor correspondente ao mês à variável "mes".
    */
    while(scanf("%d", &mes) == 0 || mes <= 0 || mes > 12)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
    }

    /* Comando "switch" para imprimir o mês correspondente ao número atribuído a essa variável */
    switch(mes)
    {
        case 1:
        printf("O mês correspondente é Janeiro.\n\n");

        break;
        case 2:
        printf("O mês correspondente é Fevereiro.\n\n");

        break;
        case 3:
        printf("O mês correspondente é Março.\n\n");

        break;
        case 4:
        printf("O mês correspondente é Abril.\n\n");

        break;
        case 5:
        printf("O mês correspondente é Maio.\n\n");

        break;
        case 6:
        printf("O mês correspondente é Junho.\n\n");

        break;
        case 7:
        printf("O mês correspondente é Julho.\n\n");

        break;
        case 8:
        printf("O mês correspondente é Agosto.\n\n");

        break;
        case 9:
        printf("O mês correspondente é Setembro.\n\n");

        break;
        case 10:
        printf("O mês correspondente é Outubro.\n\n");

        break;
        case 11:
        printf("O mês correspondente é Novembro.\n\n");

        break;
        default:
        printf("O mês correspondente é Dezembro.\n\n");

        break;
    }

 return 0;
}

/*
    (Entrada):
    10


    (Saída):
    Insira o valor correspondente ao mês : 
    O mês correspondente é Outubro.

*/
