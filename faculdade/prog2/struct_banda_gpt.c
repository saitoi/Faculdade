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
void aloca_banda(Banda **p_aux);
void adiciona_banda(Banda **p_banda);

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

void aloca_banda(Banda **p_aux)
{
    *p_aux = (Banda *) malloc(sizeof(Banda));
    if (!(*p_aux))
    {
        printf("ERRO!");
        exit(1);
    }
}

void adiciona_banda(Banda **p_banda)
{
    char opcao;
    do {
        aloca_banda(&((*p_banda)->pt_banda));
        le_banda((*p_banda)->pt_banda);
        (*p_banda) = (*p_banda)->pt_banda;

        printf("Deseja adicionar outra banda? (s/n): ");
        scanf(" %c", &opcao);
        clean_buf();
    } while (opcao == 's');
}

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */
    Banda *p_banda = NULL,
          *p_aux,
          *p1;

    aloca_banda(&p_banda);
    le_banda(p_banda);
    adiciona_banda(&p_banda);

    // Imprime as informações das bandas
    p1 = p_banda;
    while (p1 != NULL)
    {
        printf("Nome: %s\n", p1->nome);
        printf("Estilo: %s\n", p1->estilo);
        printf("Numero de integrantes: %d\n", p1->numero_integrantes);
        printf("Ranking: %d\n\n", p1->ranking);

        p1 = p1->pt_banda;
    }

    return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(void)
{
    /* Conclui após buffer estiver limpo */
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
