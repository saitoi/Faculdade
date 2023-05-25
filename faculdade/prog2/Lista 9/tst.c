#include <stdio.h>
#include <stdlib.h>

struct Contato {
    char nome[50];
    int telefone;
    char aniversario[10];
};

void inserir_contato(struct Contato *lista_contato, int *quant_contato) {
    ++(*quant_contato);
    printf("Insira os dados do contato %d:\n", *quant_contato);
    printf("Nome: ");
    fgets((lista_contato + *quant_contato)->nome, sizeof((lista_contato + *quant_contato)->nome), stdin);
    printf("Telefone: ");
    scanf("%d", &((lista_contato + *quant_contato)->telefone));
    printf("Aniversário (DD/MM): ");
    scanf("%s", (lista_contato + *quant_contato)->aniversario);
}

void imprimir_contato(struct Contato contato) {
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %d\n", contato.telefone);
    printf("Aniversário: %s\n", contato.aniversario);
}

int main(void) {
    struct Contato lista_contato[100];
    int quant_contato = -1;
    char resposta;
    FILE *arquivo = fopen("contato.txt", "a+");

    if (arquivo == NULL)
        printf("Erro ao abrir o arquivo.\n");

    menu();
    resposta = getchar();
    switch (resposta) {
        case '1':
            inserir_contato(lista_contato, &quant_contato);
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        default:
            break;
    }

    fclose(arquivo);

    return 0;
}

void clean_buf(char clear) {
    while ((clear = getchar()) != '\n' && clear != EOF);
}
