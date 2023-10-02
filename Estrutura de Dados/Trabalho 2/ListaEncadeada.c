#include <stdio.h>
#include <stdlib.h>

/* Chamando das funções */
void limpar_buffer(void);

typedef struct no {
    int valor;
    struct no *prox;
} No;

void removerChave(No **lista, int chave) {
    No *aux = *lista;
    No *ant = NULL;
    while (aux != NULL && aux->valor != chave) {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Chave não encontrada!\n");
        return;
    }
    if (ant == NULL) {
        *lista = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    
    free(aux);
}

/* Função principal sem argumentos */
int main (void) {



 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
