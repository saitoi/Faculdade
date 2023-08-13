#include <stdio.h>
#include <locale.h>

int main()
{
    /* Declarando e inicializando variáveis inteiras e decimais */
    float compra = 0.;
    int select = 0;

    /* Atribuindo o valor correspondente ao preço da compra à variável "compra" */
    printf("Insira o valor referente a sua compra: ");
    while (scanf("%f", &compra) == 0 || compra < 0)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
         
    }

    printf("Selecione qual modalidade de cliente você se encaixa: \n");
    printf("| 1. Cliente comum | | 2. Funcionário | | 3. Cliente vip |\n>"); 
    scanf("%d", &select);  

    getchar();

    switch(select)
    {
        case 1:
        printf("O valor total a ser pago é %.2f\n\n", compra);
        break;

        case 2:
        printf("O valor total a ser pago é %.2f\n\n", (compra * 0.9));
        break;

        case 3:
        printf("O valor total a ser pago é %.2f\n\n", (compra * 0.5));
        break;

        default:
        printf(" [Valor inserido inválido] \n\n");
        break;
    }


 return 0;
}

/*
    (Entrada):
    13.5
    2
    12.15
    
    
    (Saída):
    Insira o valor referente a sua compra:
    Selecione qual modalidade de cliente você se encaixa: 
    | 1. Cliente comum | | 2. Funcionário | | 3. Cliente vip |
    >
    O valor total a ser pago é 12.15

*/
