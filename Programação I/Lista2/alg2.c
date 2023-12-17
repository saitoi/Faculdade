/* Exercício 8 */

#include <stdio.h>
int main(void)
{
    /* Declaração e inicialização das variáveis em ponto flutuante e inteiras. */
    float notaAluno = 0., mediaAlunos = 0.;
    int notasLidas = 0, quantasProvas = 0;

    /* Especifica número de provas a ser lida */
    printf("Quantas provas? : ");
    scanf("%d", &quantasProvas);    

    /* Ler as notas pela entrada de fluxo padrão (teclado) */
    while(notasLidas < quantasProvas)
    {
        printf("Digite a nota %d: ", notasLidas+1);
        scanf("%f", &notaAluno);
        mediaAlunos += notaAluno;
        ++notasLidas;
    }

    mediaAlunos /= quantasProvas;
    printf("A média do aluno foi %.1f", mediaAlunos);
    if( mediaAlunos >= 5.0 )
    {
        printf (" \nAprovado \n");
    }
    else
    {
        printf (" \nReprovado \n");
    }

 return 0;
}

/*
    Valores testados no programa:

    (Entradas):
    4
    5.2
    6
    7.5
    9


    (Saídas):
    Quantas provas? : 
    Digite a nota 1: 
    Digite a nota 2:  
    Digite a nota 3: 
    Digite a nota 4: 
    A média do aluno foi 6.9 
    Aprovado 

X ----------------------------------------------------- X

    (Entradas - Tratamento de erro):



    (Saídas):



*/
