#include <stdio.h>

#define MAX_CONTATO 1000

typedef struct Contato {
    char nome[50],
         telefone[15],
         aniversario[5];
} Contato;

void clean_buf(void) {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}

void menu();
void registra_contato(Contato lista_contato[MAX_CONTATO], int quant_contato);
void remover_contato(FILE *arquivo, Contato lista_contato[MAX_CONTATO], int quant_contato);

void menu(void) {
    puts("--- AGENDA DE CONTATOS ---\n");
    puts("Selecione uma dentre as possíveis ações, escolhendo o número: ");
    puts("1. Inserir contato novo.");
    puts("2. Remover contato.");
    puts("3. Pesquisar contato pelo nome.");
    puts("4. Listar todos os contatos.");
    puts("5. Listar contatos cujo nome inicia com uma dada letra.");
    puts("6. Imprimir os aniversariantes do mês.");
    printf("\nSeleção: ");
}

void inserir_contato(Contato *lista_contato, int *quant_contato) {
    (*quant_contato)++;
    printf("Insira os dados do contato %d:\n", *quant_contato);
    printf("Nome: ");
    //scanf("%s", lista_contato[*quant_contato].nome);
    fgets(lista_contato[*quant_contato].nome, sizeof(lista_contato[*quant_contato].nome), stdin);
    printf("Telefone: ");
    fgets(lista_contato[*quant_contato].telefone, sizeof(lista_contato[*quant_contato].telefone), stdin);
    clean_buf();
    printf("Aniversário (DD/MM): ");
    scanf("%s", lista_contato[*quant_contato].aniversario);
    clean_buf(); // Limpa o buffer de entrada após ler o inteiro

    registra_contato(lista_contato, *quant_contato);
}

void remover_contato(FILE *arquivo, Contato lista_contato[MAX_CONTATO], int quant_contato) {
    arquivo = fopen("contato.txt", "w+");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Insira o nome do contato que deseja remover: ");
    
}

void registra_contato(Contato lista_contato[MAX_CONTATO], int quant_contato) {
    FILE *arquivo;
    arquivo = fopen("contato.txt", "a+"); // Abrindo o arquivo 'contato.txt' para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 1; i <= quant_contato; ++i) {
        fprintf(arquivo, "CONTATO %d:\n", i);
        fprintf(arquivo, "Nome: %s", lista_contato[i].nome);
        fprintf(arquivo, "Telefone: %s\n", lista_contato[i].telefone);
        fprintf(arquivo, "Aniversário: %s\n", lista_contato[i].aniversario);
        fprintf(arquivo, "-------------------------------------\n\n");
    }

    fclose(arquivo);
}

int main(void) {
    Contato lista_contato[MAX_CONTATO];
    int quant_contato = 0;
    char resposta;
    FILE *arquivo = NULL;

    menu(); // Impressão do menu de seleção
    resposta = getchar();
    clean_buf(); // Limpa o buffer de entrada após ler a seleção

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

    return 0;
}
