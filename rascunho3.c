#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Definição da quantidade de assentos */
#define QUANTIDADE_SALAS 3
#define QUANTIDADE_FILEIRAS 40
#define QUANTIDADE_POLTRONAS 10
#define MAX_DESCONTOS 400

/* Definição dos preços e descontos */
#define PRECO_INTEIRA 20.00
#define PRECO_MEIA 10.00
#define PRECO_ITASIL 14.00

/* Estrutura para definição das salas */
typedef struct sala {
    int assentos[QUANTIDADE_FILEIRAS][QUANTIDADE_POLTRONAS],
        carteira_estudantil[MAX_DESCONTOS],
        codigo_itasil[MAX_DESCONTOS],
        ingressos_disp_salas;
} Sala;

/* Estrutura para definição das salas do cinema */
typedef struct cinema {
    Sala salas[QUANTIDADE_SALAS];
} Cinema;

/* Estrutura para categorização das poltronas */
typedef struct poltrona {
    int fileira,
        letra;
} Poltrona;

int validar_assento(Sala *sala, int fileira, int letra);
void limpar_tela(void);
void limpar_buffer(void);
/* Protótipos das funções */
/*

void limpa_tela(void);
void carregar_arquivo(FILE *arquivo, Cinema **cinema);
void exibir_salas_filmes(void);
int selecionar_sala_filme(Cinema *cinema);
int verificar_estouro_tamanho(char *texto, int tam);
int verificar_numero(char *texto);
FILE *cria_arquivo(void);
FILE *verificar_arquivo(void);
Cinema *aloca_cinema(void);
Poltrona *escolher_poltronas(Sala *sala);
void comprar_ingressos(Sala *sala, int sala_escolhida);
*/

/* X -------- Funções Adicionais -------- X */

/* Função para inicializar */
void inicializar(Cinema *cinema) {
    int sala, fileira, poltrona;
    int i;

    /* Inicializar salas */
    for (sala = 0; sala < QUANTIDADE_SALAS; sala++)
        for (fileira = 0; fileira < QUANTIDADE_FILEIRAS; fileira++)
            for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++)
                cinema->salas[sala].assentos[fileira][poltrona] = 0;

    for (sala = 0; sala < QUANTIDADE_SALAS; sala++) {
        cinema->salas[sala].ingressos_disp_salas = 400;

        for (i = 0; i < MAX_DESCONTOS; i++) {
            cinema->salas[sala].carteira_estudantil[i] = -1;
            cinema->salas[sala].codigo_itasil[i] = -1;
        }
    }
}

int validar_carteira_estudante(int carteira_estudante, int *carteiras_estudante_sala) {
    int i, soma = 0, tmp_carteira_estudante = carteira_estudante;

    /* Verifica se o código tem 5 dígitos */
    if (tmp_carteira_estudante < 10000 || tmp_carteira_estudante > 99999)
        return 0;

    /* Verificando se o código já foi usado */
    for (i = 0; i < MAX_DESCONTOS && *(carteiras_estudante_sala + i) != -1; i++)
        if (*(carteiras_estudante_sala + i) == carteira_estudante)
            return 0;

    /* Realizando a divisão sucessiva para verificar a soma dos dígitos */
    tmp_carteira_estudante = carteira_estudante / 10;
    while (tmp_carteira_estudante > 0) {
        soma += tmp_carteira_estudante % 10;
        tmp_carteira_estudante /= 10;
    }

    if (soma % 10 != carteira_estudante % 10)
        return 0;

    return 1;
}

int validar_codigo_itasil(int codigo_itasil, int *codigos_itasil_sala) {
    int i;

    /* Verificando se o código já foi usado */
    for (i = 0; i < MAX_DESCONTOS && *(codigos_itasil_sala + i) != -1; i++)
        if (*(codigos_itasil_sala + i) == codigo_itasil)
            return 0;

    /* Verificando se o código é múltiplo de 341 */
    if ((codigo_itasil % 341) == 0) {
        codigos_itasil_sala[i] = codigo_itasil;
        return 1;
    }
    else
        return 0;
}

/* Função NOVA para comprar ingressos */
void comprar_ingressos(Sala *sala, Poltrona *poltronas_escolhidas, int num_poltronas) {
    int i = 0,
        ingressos_a_comprar = num_poltronas,
        meia_entrada = 0,
        itasil = 0;

    do {
        printf("Insira quantos ingressos terao desconto meia-entrada:\n");
        scanf("%d", &meia_entrada);

        if (!(0 <= meia_entrada && meia_entrada <= ingressos_a_comprar)) {
            printf("Quantidade invalida, tente novamente...\n");
        }
    } while (!(0 <= meia_entrada && meia_entrada <= ingressos_a_comprar));

    for (i = 0; i < meia_entrada; i++) {
        int carteira_estudante;
        printf("Insira a carteira de estudante para aplicar o desconto ou 0 para cancelar (%d/%d):\n", i, meia_entrada);
        scanf("%d", &carteira_estudante);

        if (carteira_estudante == 0) {
            meia_entrada--;
            i--;
        }
        else if (validar_carteira_estudante(carteira_estudante, sala->carteira_estudantil)) {
            for (i = 0; i < MAX_DESCONTOS; i++) {
                if (sala->carteira_estudantil[i] == -1) {
                    sala->carteira_estudantil[i] = carteira_estudante;
                    ingressos_a_comprar--;
                    break;
                }
            }
        }
        else {
            printf("Carteira de estudante invalida. Tente novamente...\n");
            i--;
        }
    }

    do {
        printf("Insira quantos ingressos terao desconto de cliente itasil:\n");
        scanf("%d", &itasil);

        if (!(0 <= itasil && itasil <= ingressos_a_comprar)) {
            printf("Quantidade invalida, tente novamente...\n");
        }
    } while (!(0 <= itasil && itasil <= ingressos_a_comprar));

    for (i = 0; i < itasil; i++) {
        int codigo_itasil;
        printf("Insira o codigo itasil para aplicar o desconto ou 0 para cancelar (%d/%d):\n", i, itasil);
        scanf("%d", &codigo_itasil);

        if (codigo_itasil == 0) {
            itasil--;
            i--;
        }
        else if (validar_codigo_itasil(codigo_itasil, sala->codigo_itasil)) {
            for (i = 0; i < MAX_DESCONTOS; i++) {
                if (sala->codigo_itasil[i] == -1) {
                    sala->codigo_itasil[i] = codigo_itasil;
                    ingressos_a_comprar--;
                    break;
                }
            }
        }
        else {
            printf("Codigo Itasil invalido. Tente novamente...\n");
            i--;
        }
    }

    printf("Valor total a ser pago: R$%.2f\n", meia_entrada * PRECO_MEIA + itasil * PRECO_ITASIL + ingressos_a_comprar * PRECO_INTEIRA);
    printf("Agradecemos a preferencia!\n");
}

int validar_assento(Sala *sala, int fileira, int letra) {
    return ((0 <= fileira && fileira < QUANTIDADE_FILEIRAS &&
        0 <= letra && letra < QUANTIDADE_POLTRONAS &&
        sala->assentos[fileira][letra]) == 0);
}

Cinema *aloca_cinema(void) {
    Cinema *cinema = (Cinema *) malloc(sizeof(Cinema));
    return cinema;
}

/* Função para carregar o arquivo_sistema a partir de um arquivo binario */
void carregar_arquivo(FILE *arquivo, Cinema **cinema) {
    if (!(*cinema = aloca_cinema())) {
        printf("Erro de alocacao.\n");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_END);
    if (ftell(arquivo) == 0) {
        return;
    }
    fseek(arquivo, 0, SEEK_SET);

    if (!(fread(cinema, sizeof(Cinema), 1, arquivo))) {
        printf("Erro de leitura no arquivo.\n");
        exit(1);
    }
    fclose(arquivo);
}

/* Função NOVA para efetuar pedido */
int selecionar_sala_filme(Cinema *cinema) {
    int sala_usuario;

    do {
        printf("Escolha uma das salas (1 - %d): ", QUANTIDADE_SALAS);
        scanf("%d", &sala_usuario);
        limpar_buffer();
    } while (sala_usuario < 0 || sala_usuario > QUANTIDADE_SALAS);

    return sala_usuario;
}

/* Exibir sala antes de comprar ingressos */
void exibir_salas_filmes(void) {
    limpar_tela();
    puts("-- MENU --");
    puts("0 - Sair");
    puts("1 - Sala 1 (Velozes e Furiosos)");
    puts("2 - Sala 2 (Transformers)");
    puts("3 - Sala 3 (The Flash)");
}

/* Função para verificar se houve estouro no tamanho da entrada */
int verificar_estouro_tamanho(char *texto, int tam) {
    if ((strlen(texto) == tam - 1 && texto[strlen(texto) - 1] != '\n')) {
        limpar_buffer();
        return 1;
    }

    return 0;
}

/* Função para verificar se um texto digitado é um número ou não */
int verificar_numero(char *texto) {
    int i = 0;

    for (i = 0; i < strlen(texto); i++)
        if (!isdigit(texto[i])) return 0;

    return 1;
}

/* Função para criar o arquivo binário que contém os dados do arquivo_sistema */
FILE *cria_arquivo(void) {
    FILE *arq = NULL;
    return arq = fopen("cinema.bin", "wb+");
}

/* Função para verificar se o arquivo binário que contém os dados do arquivo_sistema já existe ou não */
FILE *verificar_arquivo(void) {
    FILE *arq = NULL;
    return arq = fopen("cinema.bin", "rb+");
}

/* Exibir mapa da sala vindo do arquivo */
void exibir_mapa_sala(Sala *sala) {
    int fileira, poltrona;

    printf("----- MAPA DA SALA-----\n\n");

    /* Imprimir números das poltronas */
    printf("   ");
    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++) {
        printf(" %c", 'A' + poltrona);
    }
    printf("\n");

    /* Imprimir linha separadora */
    printf(" ");
    printf("---");
    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS * 2 + 1; poltrona++) {
        printf("-");
    }
    printf("\n");

    /* Imprimir mapa da sala */
    for (fileira = 0; fileira < QUANTIDADE_FILEIRAS; fileira++) {
        printf("%2d|", fileira + 1);
        for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++) {
            printf(" %c", sala->assentos[fileira][poltrona] == 1 ? 'X' : '0');
        }
        printf(" |\n");
    }

    /* Imprimir linha separadora */
    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS * 2 + 1; poltrona++) {
        printf("-");
    }
    printf("----");
    printf("\n");
}

Poltrona *escolher_poltronas(Sala *sala, int *poltronas_a_comprar) {
    Poltrona *poltronas_escolhidas = NULL;
    int num_poltronas, fileira, letra;
    char letra_char;
    int i;
    Sala copia_sala = *sala;

    limpar_tela();
    exibir_mapa_sala(&copia_sala);

    printf("Insira quantas poltronas deseja comprar: \n");
    scanf("%d", &num_poltronas);
    limpar_buffer();
    if (!(0 < num_poltronas && num_poltronas < sala->ingressos_disp_salas)) {
        printf("Quantidade de ingressos invalida. Retornando ao menu...\n");
        return NULL;
    }
    *poltronas_a_comprar = num_poltronas;

    poltronas_escolhidas = (Poltrona *) calloc(num_poltronas, sizeof(Poltrona));

    for (i = 0; i < num_poltronas; i++) {
        printf("Selecione a poltrona para o ingresso (%d/%d): \n", i + 1, num_poltronas);
        scanf("%d %c", &fileira, &letra_char);
        fileira--;
        letra = letra_char - 'A';

        if (validar_assento(sala, fileira, letra)) {
            poltronas_escolhidas[i].fileira = fileira;
            poltronas_escolhidas[i].letra = letra;

            copia_sala.assentos[fileira][letra] = 1;
        }
        else {
            printf("Assento invalido, tente novamente...\n");
            i--;
        }
        limpar_tela();
        exibir_mapa_sala(&copia_sala);
    }
    return poltronas_escolhidas;
}

/* Função principal do programa */
int main(void) {
    FILE *arquivo_sistema = NULL;
    Cinema *cinema = aloca_cinema();

    if (!(arquivo_sistema = verificar_arquivo())) arquivo_sistema = cria_arquivo();
    if (!arquivo_sistema) {
        puts("Nao foi possivel coletar os dados do arquivo_sistema! \nPedimos perdao pelo incoveniente,");
        puts("Atenciosamente,\nCinema Mariano Pinheiro");
        exit(1);
    }
    else carregar_arquivo(arquivo_sistema, &cinema);
    inicializar(cinema);
    /*
    if (!(arquivo_sistema = verificar_arquivo()))
        arquivo_sistema = cria_arquivo();

    if (!arquivo_sistema) {
        puts("Nao foi possivel coletar os dados do arquivo_sistema!\nPedimos perdao pelo incoveniente,");
        puts("Atenciosamente,\nCinema Mariano Pinheiro");
        exit(1);
    } else {
        carregar_arquivo(arquivo_sistema, &cinema);
        inicializar(cinema);
    }
    */

    do {
        int sala_escolhida, poltronas_a_comprar;
        Poltrona *poltronas_escolhidas = NULL;

        exibir_salas_filmes();
        sala_escolhida = selecionar_sala_filme(cinema);
        sala_escolhida--; /* Como os vetores das salas sao 0 - indexados */

        if (sala_escolhida == -1) {
            printf("Obrigado por utilizar o nosso sistema!\n");
            break;
        }

        poltronas_escolhidas = escolher_poltronas(&(cinema->salas[sala_escolhida]), &poltronas_a_comprar);
        if (poltronas_escolhidas == NULL) continue;
        comprar_ingressos(cinema->salas, poltronas_escolhidas, poltronas_a_comprar);

        free(poltronas_escolhidas);
    } while (1);

    /* Salvar cinema no arquivo binario */

    return 0;
}

/* X -------- Funções Adicionais -------- X */

/* Função para limpar a tela do arquivo_sistema */
void limpar_tela(void) {
    system("clear||cls");
}

/* Função para limpar o buffer de entrada do arquivo_sistema */
void limpar_buffer(void) {
    int ch = 0;
    while ((ch = getchar() != '\n') && (ch != EOF));
}