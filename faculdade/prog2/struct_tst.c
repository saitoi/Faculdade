#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia,
        mes,
        ano;
}Data;

typedef struct Pessoa
{
    char *nome;
    Data nascimento;
    struct Pessoa *proximo;
}Pessoa;

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int cont;
    struct Pessoa cara[5];    /* Ou simplesmente "Pessoa Pedro" */

    for (cont = 0; cont < 5; ++cont)
    {
        cara[cont].nome = (char *) malloc(sizeof(char)*10);
        printf("Insira o nome da pessoa %d : ",cont);
        scanf("%s", cara[cont].nome);
    }
    

 return 0;
}
