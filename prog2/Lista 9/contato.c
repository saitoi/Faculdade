#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATO 1000

typedef struct Contato {
    char nome[50],
         telefone[15],
         aniversario[5];
} Contato;

void clean_buf(void) {
    int clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}

void menu(void);
void imprimir_contato_l(Contato lista_contato[MAX_CONTATO], int quant_contato);
void inserir_contato(Contato *lista_contato, int *quant_contato);
void remover_contato(Contato *lista_contato, int *quant_contato);
void imprimir_contato(Contato lista_contato[MAX_CONTATO]);
void pesquisa_contato(Contato lista_contato[MAX_CONTATO], int quant_contato);
void registra_contato(Contato lista_contato[MAX_CONTATO], int quant_contato);
void aniversariantes_do_mes(Contato lista_contato[MAX_CONTATO], int quant_contato);

/* --- MENU --- */

void menu(void) {
    puts("--- AGENDA DE CONTATOS ---\n");
    puts("Selecione uma das possíveis ações, escolhendo o número: ");
    puts("1. Inserir contato novo.");
    puts("2. Remover contato.");
    puts("3. Pesquisar contato pelo nome.");
    puts("4. Listar todos os contatos.");
    puts("5. Listar contatos cujo nome inicia com uma dada letra.");
    puts("6. Imprimir os aniversariantes do mês.");
    printf("\nSeleção: ");
}

/* --- ADICIONAR CONTATO --- */

void inserir_contato(Contato *lista_contato, int *quant_contato) {
    (*quant_contato)++;
    printf("Insira os dados do contato %d:\n", *quant_contato);
    printf("Nome: ");
    fgets(lista_contato[*quant_contato].nome, sizeof(lista_contato[*quant_contato].nome), stdin);
    printf("Telefone: ");
    fgets(lista_contato[*quant_contato].telefone, sizeof(lista_contato[*quant_contato].telefone), stdin);
    printf("Aniversário (DD/MM): ");
    scanf("%s", lista_contato[*quant_contato].aniversario);
    clean_buf(); // Limpa o buffer de entrada após ler a string

    registra_contato(lista_contato, *quant_contato);
}

/* --- REMOVER CONTATO --- */

void remover_contato(Contato *lista_contato, int *quant_contato) {
    int alert = -1;
    char nome[50];
    printf("Insira o nome do contato que deseja remover: ");
    fgets(nome, sizeof(nome), stdin);

    for (int i = 1; i <= *quant_contato; ++i) {
        if (strcmp(nome, lista_contato[i].nome) == 0) {
            alert = i;
            break;
        }
    }

    if (alert == -1) {
        printf("Contato não encontrado.\n");
        return;
    }

    for (int i = alert; i < *quant_contato; ++i) {
        strcpy(lista_contato[i].nome, lista_contato[i + 1].nome);
        strcpy(lista_contato[i].telefone, lista_contato[i + 1].telefone);
        strcpy(lista_contato[i].aniversario, lista_contato[i + 1].aniversario);
    }

    (*quant_contato)--;
    printf("Contato removido com sucesso.\n");
}

/* --- REGISTRA CONTATO --- */

void registra_contato(Contato lista_contato[MAX_CONTATO], int quant_contato) {
    FILE *arquivo;
    arquivo = fopen("contato.txt", "a+"); // Abrindo o arquivo 'contato.txt' para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "CONTATO %d:\n", quant_contato);
    fprintf(arquivo, "Nome: %s", lista_contato[quant_contato].nome);
    fprintf(arquivo, "Telefone: %s", lista_contato[quant_contato].telefone);
    fprintf(arquivo, "Aniversário: %s", lista_contato[quant_contato].aniversario);
    fprintf(arquivo, "-------------------------------------\n");

    fclose(arquivo);
}

/* --- IMPRIMIR CONTATO COM LETRA --- */

void imprimir_contato_l(Contato lista_contato[MAX_CONTATO], int quant_contato) {
    int i = 0;
    char caractere;

    puts("Escolha um caractere que inicie o nome dos contatos:");
    caractere = getchar();
    clean_buf(); // Limpa o buffer de entrada após ler o caractere
    
    /* Percorrendo lista até identificar caractere */
    while (i <= quant_contato) {
        if (lista_contato[i].nome[0] == caractere || lista_contato[i].nome[0] == (caractere + 32))
            printf("Nome: %s", lista_contato[i].nome);
        ++i;
    }
}

/* --- IMPRIMIR LISTA --- */

void imprimir_contato(Contato lista_contato[MAX_CONTATO]) {
    char caractere;
    FILE *arquivo = fopen("contato.txt", "r");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo.");
        return;
    }
    
    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere);
    }

    fclose(arquivo);
}

/* --- PESQUISA CONTATO --- */

void pesquisa_contato(Contato lista_contato[MAX_CONTATO], int quant_contato) {
    int cont;
    char contato_nome[50];

    printf("Qual contato deseja procurar: ");
    fgets(contato_nome, sizeof(contato_nome), stdin);
    for (cont = 0; cont <= quant_contato && strcmp(contato_nome, lista_contato[cont].nome) != 0; ++cont);
    if (cont > quant_contato) {
        puts("Contato não foi identificado.");
        return;
    } else {
        puts("Os dados do contato estão listados abaixo.");
        printf("Nome: %s", lista_contato[cont].nome);
        printf("Telefone: %s", lista_contato[cont].telefone);
        printf("Aniversario: %s\n", lista_contato[cont].aniversario);
    }

}

/* --- ANIVERSARIANTE DO MES --- */

void aniversariantes_do_mes(Contato lista_contato[MAX_CONTATO], int quant_contato) {
    int mes_atual;
    printf("Digite o número do mês atual: ");
    scanf("%d", &mes_atual);
    clean_buf(); // Limpa o buffer de entrada

    printf("Aniversariantes do mês %d:\n", mes_atual);

    int i, aniversariantes = 0;
    for (i = 1; i <= quant_contato; i++) {
        int mes_aniversario;
        sscanf(lista_contato[i].aniversario, "%*d/%d", &mes_aniversario);
        if (mes_aniversario == mes_atual) {
            printf("Nome: %s", lista_contato[i].nome);
            printf("Telefone: %s", lista_contato[i].telefone);
            printf("Aniversario: %s\n", lista_contato[i].aniversario);
            aniversariantes++;
        }
    }

    if (aniversariantes == 0) {
        printf("Não há aniversariantes este mês.\n");
    }
}


/* --- FUNÇÃO PRINCIPAL --- */

int main(void) {
    FILE *arquivo;
    Contato lista_contato[MAX_CONTATO];
    int quant_contato = 0;
    char resposta;

    arquivo = fopen("contato.txt", "r");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo.");
        return 1;
    }

    // Lê as linhas do arquivo e extrai as informações dos contatos
    while (fgets(lista_contato[quant_contato].nome, sizeof(lista_contato[quant_contato].nome), arquivo) != NULL) {
        fgets(lista_contato[quant_contato].telefone, sizeof(lista_contato[quant_contato].telefone), arquivo);
        fgets(lista_contato[quant_contato].aniversario, sizeof(lista_contato[quant_contato].aniversario), arquivo);
        quant_contato++;
    }

    fclose(arquivo);

    while (1) {
        menu(); // Impressão do menu de seleção
        resposta = getchar();
        clean_buf(); // Limpa o buffer de entrada após ler a seleção

        switch (resposta) {
            case '1':
                inserir_contato(lista_contato, &quant_contato);
                break;
            case '2':
                remover_contato(lista_contato, &quant_contato);
                break;
            case '3':
                pesquisa_contato(lista_contato, quant_contato);
                break;
            case '4':
                imprimir_contato(lista_contato);
                break;
            case '5':
                imprimir_contato_l(lista_contato, quant_contato);
                break;
            case '6':
                aniversariantes_do_mes(lista_contato, quant_contato);
                break;
            default:
                exit(0);
                break;
        }
    }

    return 0;
}
