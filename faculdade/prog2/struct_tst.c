#include <stdio.h>
#include <stdlib>

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
}Pessoa;

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variáveis inteiras */
    int cont = 0;
    struct Pessoa Pedro;    /* Ou simplesmente "Pessoa Pedro" */
    Pedro.nome = (char *) malloc(sizeof(char) * );

 return 0;
}
