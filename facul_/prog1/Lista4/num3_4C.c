#include <stdio.h>

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras e em ponto flutuante */
    float nota = 0., media = 0.;
    int cont = 0;
  
    printf("Insira o valor correspondente a cada nota (maiores que zero):");

    /* Permite a adição de no máximo 3 valores à variável media, desde que não seja inserido
       um valor nulo. 
    */
    while(nota >= 0 && cont < 3)
    {
        printf("\n> ");

        /* Validação da entrada para caracteres */
        while(scanf("%f", &nota) == 0);

        if (nota < 0)
        {
            printf("Programa encerrado..\n\n");
            return 0;
        }

        media += nota;
        ++cont;
    }

    printf("Média resultante das notas coletadas : %.1f\n\n", (media/cont));

 return 0;
}

/*
    (Entrada):
    6
    5.5
    3

    (Saída):
    Insira o valor correspondente a cada nota (maiores que zero):
    > 
    
    > 
    
    > 

    Média resultante das notas coletadas : 4.8

*/
