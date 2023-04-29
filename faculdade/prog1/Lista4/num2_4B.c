#include <stdio.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variávies inteiras */
    int idade = 0, cont = 0, menor = 0, maior = 0;
    float media = 0.;
    
    printf("Insira os valores correspondentes à idades das pessoas:\n> ");
    
    /* Validação da entrada para caracteres */
    while(scanf("%d", &idade) == 0)
    {
        getchar();
        printf(" [ Valor inválido ] \n");
    }

    printf("\n");
    
    ++cont;
    menor = idade;
    /* "Enquanto idade não for zero" */
    while (idade)
    {
        /* Atualização da menor idade presente na amostra */
        if (idade < menor)
        menor = idade;

        /* Atualização da maior idade presente na amostra */
        if (idade > maior)
        maior = idade;

        printf("> ");

        /* Validação da entrada para valores negativos ou caracteres */
        while(scanf("%d", &idade) == 0)
        {
            getchar();
            printf(" [ Valor inváido ] \n");
        }

        if (idade <= 0) break;

        /* Adição consecutiva de cada idade inserida na variável media */
        media += idade;

        getchar();
        printf("\n");

        /* Contador para identificar o número de indivíduos na amostra */
        ++cont;
    }

    /* Impressão do resultado referente à média, ao número de pessoas, bem como as maiores 
       e menores idades presentes. 
    */ 
    printf("A média das idades coletadas foi %.1f\n", (media/cont));
    printf("O número total de pessoas foi %d\n", cont);
    printf("A maior idade entre as coletadas foi %d\n", maior);
    printf("A menor idade entre as coletadas foi %d\n\n", menor);

 return 0;
}

/* 
    (Entrada):
    12
    76
    54
    0



    (Saída):
    Insira os valores correspondentes à idades das pessoas:
    > 
    
    > 
    
    > 
    
    > 
    A média das idades coletadas foi 43.3
    O número total de pessoas foi 3
    A maior idade entre as coletadas foi 76
    A menor idade entre as coletadas foi 12

*/
