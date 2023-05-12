#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Funções situadas após "int main()" */
void pause();
void cls();
int *alloc(int tam);

/* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variávies inteiras */
    int fat = 0,
        cand = 2,
        cont = -1;
    int *seq,
        tam = 0;

    setlocale(LC_ALL, "Portuguese");
    cls();

    /* Passo 1 : */
    printf("Insira o valor natural correspondente ao número que deseja fatorar : ");
    while(scanf("%d", &fat) == 0)
    {
        getchar();
        printf("\n [ Valor inválido ] \n\n>");
    }
    getchar();

    /* Passo 2 : */
    while (fat != 1)
    {
        if ((fat % cand) == 0)
        {
            ++tam;
            seq = alloc(tam);
            seq[cont] = cand;
            ++cont;
            fat /= cand;
        }
        else
            ++cand;
    }

    printf("A sequência correspondente de primos é : ");
    for (cont = 0 ; cont < tam ; ++cont)
    {
        printf("%d, ", seq[cont]);
    }

    printf(".\n\n");


 return 0;
}

int *alloc(int tam)
{
    /* Declarando e inicializando ponteiro */
    int *v;

    /* Memória é alocada e ponteiro recebe endereço de memória */
    v = (int *) malloc ( tam * sizeof (int) );

    /* Ponteiro incrementado é retornado */
    return v; 
}

void cls()
{
    printf("\x1B[2J\x1B[H");
}

void pause()
{
    getchar();
}
