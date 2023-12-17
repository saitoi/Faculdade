#include <stdio.h>
#include <stdlib.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

/* Struct para definição da banda */
typedef struct _Jogador {
    char nome[50], estilo[50];
    int numero_integrantes, ranking;
    struct Banda *prox;
}Banda;

typedef struct _Lista {
    struct Banda *head, *tail;
    int tam;
}

void adiciona_banda(Banda *tail) {

}

/* Função principal não recebe argumentos */
int main (void)
{
    /* Declarando e inicializando variáveis inteiras */

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear)
{
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
