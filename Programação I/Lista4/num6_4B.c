#include <stdio.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int num = 0,
        select = 0,
        num2 = 0;

    do{
    /* Tabela para selecionar tipo de conversão de base */
    printf("Selecione o método de conversão de base da tabela :\n\n");
    printf(" < Conversão de Base >\n");
    printf("1: Decimal para hexadecimal\n");
    printf("2: Hexadecimal para decimal\n");
    printf("3: Decimal para octal\n");
    printf("4: Octal para decimal\n");
    printf("5: Encerra\n\n>");

    /* Validação da entrada para caracteres e números que não estão compreendidos no intervalo de 1 a 5 */
    while((scanf("%d", &select) == 0) || select < 1 || select > 5)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n> ");
    }
    
    /* 
       Comando "switch" seleciona qual a forma de conversão, permitindo que tanto as
       entradas quanto as bases de destino estejam de acordo.
    */
    switch(select)
    {
        case 1:
        printf("Digite o número da base de origem : ");
        scanf("%d", &num);
        getchar();

        printf("O número decimal %d na base hexadecimal é : %#x\n\n", num, num);
        
        break;
        case 2:
        printf("Digite o número da base de origem : ");
        scanf("%xd", &num);
        getchar();

        printf("O número hexadecimal %#x na base decimal é : %d\n\n", num, num);
        
        break;
        case 3:
        printf("Digite o número da base de origem : ");
        scanf("%d", &num);
        getchar();

        printf("O número decimal %d na base octal é : %o\n\n", num, num);
        
        break;
        case 4:
        printf("Digite o número da base de origem : ");
        scanf("%od", &num);
        getchar();

        printf("O número octal %o na base decimal é : %d\n\n", num, num);
        
        break;
        case 5:

        printf(" [ Programa encerrado ]\n\n");
        return 0;
        break;

        default:
        printf(" [ Valor inserido não é válido ]\n\n");
        break;
    }

    printf("Caso deseja retornar ao menu, aperte '1', caso deseja encerrar o programa, aperte '0'.\n> ");
    
    /* Validação para entrada de caracteres */
    while(scanf("%d", &num2) == 0)
    {
        getchar();
        printf(" [ Valor inválido ] \n\n> ");
    }

    }while(num2 == 1);

 return 0;
}

/* 
    (Entrada):
    2
    12a
    0


    (Saída):
    < Conversão de Base >
    1: Decimal para hexadecimal
    2: Hexadecimal para decimal
    3: Decimal para octal
    4: Octal para decimal
    5: Encerra
    
    >
    Digite o número da base de origem : 
    O número hexadecimal 0x12a na base decimal é : 298
    Caso deseja retornar ao menu, aperte '1', caso deseja encerrar o programa, aperte '0'.
    >
    
*/
