#include <stdio.h>
#include <stdlib.h>

/* Definição da estrutura de um nó */
typedef struct No {
    int dado;
    struct No* antes;
    struct No* prox;
} No;

/* Chamada das funções do programa */
void clean_buf(void);
No* criarNo(int dado);
void adicionar_inicio(No** cabeca, int dado);
void adicionar_final(No** cabeca, int dado);
void imprimir_lista_direita(No* cabeca);
void imprimir_lista_esquerda(No* cabeca);
    if (nov
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->antes = NULL;
    novoNo->prox = NULL;
    return novoNo;
}

/* Função para inserir um nó no início da lista */
void adicionar_inicio(No** cabeca, int dado) {
    No* novoNo = criarNo(dado);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        novoNo->prox = *cabeca;
        (*cabeca)->antes = novoNo;
        *cabeca = novoNo;
    }
    printf("Elemento %d inserido no início da lista.\n", dado);
}

/* Função para inserir um nó no final da lista */
void adicionar_final(No** cabeca, int dado) {
    No* novoNo = criarNo(dado);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
        novoNo->antes = atual;
    }
    printf("Elemento %d inserido no final da lista.\n", dado);
}

/* Função para exibir a lista do início ao fim */
void imprimir_lista_direita(No* cabeca) {
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
    } else {
        printf("Lista (do início ao fim): ");
        while (cabeca != NULL) {
            printf("%d ", cabeca->dado);
            cabeca = cabeca->prox;
        }
        printf("\n");
    }
}

/* Função para exibir a lista do fim ao início */
void imprimir_lista_esquerda(No* cabeca) {
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
    } else {
        No* atual = cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        printf("Lista (do fim ao início): ");
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->antes;
        }
        printf("\n");
    }
}

/* Função principal */
int main(void) {
    No* cabeca = NULL;  /* Inicializa a lista vazia */
    int opcao, elemento;

    do {
        printf("\n-- MENU --\n");
        printf("1 - Inserir elemento no início\n");
        printf("2 - Inserir elemento no final\n");
        printf("3 - Exibir lista do início ao fim\n");
        printf("4 - Exibir lista do fim ao início\n");
        printf("0 - Sair\n    Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o elemento a ser inserido no início da lista: ");
                scanf("%d", &elemento);
                adicionar_inicio(&cabeca, elemento);
                break;
            case 2:
                printf("\nDigite o elemento a ser inserido no final da lista: ");
                scanf("%d", &elemento);
                adicionar_final(&cabeca, elemento);
                break;
            case 3:
                imprimir_lista_direita(cabeca);
                break;
            case 4:
                imprimir_lista_esquerda(cabeca);
                break;
            case 0:
                printf("\nEncerrando o programa..\n");
                break;
            default:
                printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
