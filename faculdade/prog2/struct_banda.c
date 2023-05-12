#include <stdio.h>
#include <stdlib.h>

typedef struct Banda
{
    /* Declarando as variáveis para a estrutura Banda */
    char nome[50],
         estilo[50];
    int numero_integrantes,
        ranking;
    struct Banda *pt_banda;

}Banda;

/* Chamando funções situadas após "int main" */
void clean_buf(void);
void le_banda(Banda *p_banda);
void aloca_banda(Banda *p_aux);

void le_banda(Banda *p_banda)
{
    printf("Insira o nome da banda: ");
    scanf("%s", p_banda->nome);
    clean_buf();
    
    printf("Insira o tipo musical: ");
    scanf("%s", p_banda->estilo);
    clean_buf();

    printf("Insira o numero de integrantes: ");
    scanf("%d", &p_banda->numero_integrantes);
    clean_buf();

    printf("Insira o ranking: ");
    scanf("%d", &p_banda->ranking);
    clean_buf();


}

void aloca_banda(Banda *p_aux)
{
    p_aux = (Banda *) malloc(sizeof(Banda));
    if (!p_aux)
    {
        printf("ERRO!");
        exit(1);
    }
}

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */
    Banda *p_banda, *p_aux,
          *p1;
    aloca_banda(&p_aux);
    le_banda(&p_banda);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(void)
{
    /* Conclui após buffer estiver limpo */
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
