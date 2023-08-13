#include "cinema.h"
#include <string.h>
#include <ctype.h>

Cinema *alocar_cinema(void) {
    Cinema *cinema = (Cinema *) malloc(sizeof(Cinema));
    if (cinema == NULL) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    return cinema;
}

void inicializar_cinema(Cinema *cinema) {
    int sala = 0, fileira = 0, poltrona = 0, i = 0;

    for (sala = 0; sala < QUANTIDADE_SALAS; sala++)
        for (fileira = 0; fileira < QUANTIDADE_FILEIRAS; fileira++)
            for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++)
                cinema->salas[sala].assentos[fileira][poltrona] = 0;

    for (sala = 0; sala < QUANTIDADE_SALAS; sala++) {
        cinema->salas[sala].ingressos_disp_salas = MAX_INGRESSOS;

        for (i = 0; i < MAX_INGRESSOS; i++) {
            cinema->salas[sala].carteiras_estudantis[i] = -1;
            cinema->salas[sala].codigos_itasil[i] = -1;
        }
    }

    cinema->salas[0].num_sala = 1;
    strcpy(cinema->salas[0].nome_filme, "VELOZES E FURIOSOS 137");
    cinema->salas[1].num_sala = 2;
    strcpy(cinema->salas[1].nome_filme, "TRANSFORMERS");
    cinema->salas[2].num_sala = 3;
    strcpy(cinema->salas[2].nome_filme, "THE FLASH");
}

int carteira_estudantil_valida(int carteira_estudante, int *carteiras_estudante_sala) {
    int i = 0,
        soma = 0,
        tmp_carteira_estudante = carteira_estudante;

    if (tmp_carteira_estudante < 10000 || tmp_carteira_estudante > 99999)
        return 0;

    for (i = 0; i < MAX_INGRESSOS; i++)
        if (carteiras_estudante_sala[i] == carteira_estudante)
            return 0;

    soma = soma_digitos(carteira_estudante / 10);

    if (soma % 10 != carteira_estudante % 10)
        return 0;

    return 1;
}

int codigo_itasil_valido(int codigo_itasil, int *codigos_itasil_sala) {
    int i = 0;

    for (i = 0; i < MAX_INGRESSOS; i++)
        if (codigos_itasil_sala[i] == codigo_itasil)
            return 0;

    if ((codigo_itasil % 341) != 0)
        return 0;

    return 1;
}

int validar_assento(Sala *sala, int fileira, int espaco, int letra) {
    return 0 <= fileira && fileira < QUANTIDADE_FILEIRAS &&
        0 <= letra && letra < QUANTIDADE_POLTRONAS &&
        sala->assentos[fileira][letra] == 0 && espaco == ' ';
}

void comprar_ingressos(Sala *sala, Poltrona *poltronas_escolhidas, int num_poltronas) {
    int i = 0,
        ingressos_a_comprar = num_poltronas,
        qtd_meia_entrada = 0,
        qtd_codigo_itasil = 0,
        qtd_inteira = 0;
    float valor_total = 0.0;

    qtd_meia_entrada = obter_qtd_meia_entrada(ingressos_a_comprar);
    inserir_carteiras_estudantis(sala, &qtd_meia_entrada, &ingressos_a_comprar);

    if (ingressos_a_comprar > 0) {
        qtd_codigo_itasil = obter_qtd_codigo_itasil(ingressos_a_comprar);
        inserir_codigos_itasil(sala, &qtd_codigo_itasil, &ingressos_a_comprar);
    }
    qtd_inteira = ingressos_a_comprar;

    valor_total += qtd_meia_entrada * PRECO_MEIA;
    valor_total += qtd_codigo_itasil * PRECO_ITASIL;
    valor_total += qtd_inteira * PRECO_INTEIRA;

    imprimir_recibo(poltronas_escolhidas, num_poltronas, qtd_meia_entrada, qtd_codigo_itasil, qtd_inteira, valor_total);

    for (i = 0; i < num_poltronas; i++)
        sala->assentos[poltronas_escolhidas[i].fileira][poltronas_escolhidas[i].letra] = 1;
    sala->ingressos_disp_salas -= num_poltronas;
    pausar_programa();
}

void imprimir_tela_aplicacao_descontos(void) {
    puts("==========================================================");
    puts("                  APLICACAO DE DESCONTOS                  ");
    puts("==========================================================");
}

void imprimir_recibo(Poltrona *poltronas_escolhidas, int num_poltronas, int qtd_meia_entrada, int qtd_codigo_itasil, int qtd_inteira, float valor_total) {
    int i = 0;
    limpar_tela();
    puts("==========================================================");
    puts("                     RECIBO DE COMPRA                     ");
    puts("==========================================================");
    printf("Poltronas escolhidas: ");
    for (i = 0; i < num_poltronas; i++)
        printf("[%d %c] ", poltronas_escolhidas[i].fileira + 1, poltronas_escolhidas[i].letra + 'A');
    puts("");
    printf("Quantidade de ingressos sem desconto (inteiro): %d\n", qtd_inteira);
    printf("Subtotal: R$%.2f\n", qtd_inteira * PRECO_INTEIRA);
    printf("Quantidade de ingressos com desconto de meia-entrada: %d\n", qtd_meia_entrada);
    printf("Subtotal: R$%.2f\n", qtd_meia_entrada * PRECO_MEIA);
    printf("Quantidade de ingressos com desconto de cliente Itasil : %d\n", qtd_codigo_itasil);
    printf("Subtotal: R$ %.2f\n", qtd_codigo_itasil * PRECO_ITASIL);
    printf("Valor total da compra: R$ %.2f\n", valor_total);
    puts("==========================================================");
    puts("                AGRADECEMOS A PREFERENCIA                 ");
    puts("==========================================================");
}

int obter_qtd_meia_entrada(int ingressos_a_comprar) {
    int qtd_meia_entrada = 0, entrada_invalida = 1;
    char entrada[MAX_ENTRADA] = "";

    limpar_tela();
    imprimir_tela_aplicacao_descontos();
    do {
        printf("Insira quantos ingressos terao desconto de meia-entrada: ");
        if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
            verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
            printf("Quantidade invalida. Tente novamente...\n");
            pausar_programa();
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
            continue;
        }
        else {
            qtd_meia_entrada = atoi(entrada);
            if (qtd_meia_entrada >= 0 && qtd_meia_entrada <= ingressos_a_comprar)
                entrada_invalida = 0;

            else {
                printf("Quantidade invalida. Tente novamente...\n");
                pausar_programa();
                limpar_tela();
                imprimir_tela_aplicacao_descontos();
            }
        }
    } while (entrada_invalida);

    return qtd_meia_entrada;
}

void inserir_carteiras_estudantis(Sala *sala, int *qtd_meia_entrada, int *ingressos_a_comprar) {
    int carteira_estudante = 0, i = 0;
    char entrada[MAX_ENTRADA] = "";
    limpar_tela();
    imprimir_tela_aplicacao_descontos();

    for (i = 0; i < *qtd_meia_entrada; i++) {
        carteira_estudante = 0;
        strcpy(entrada, "");

        while (1) {
            printf("Insira a carteira de estudante para aplicar o desconto ou 0 para cancelar (%d/%d): ", i + 1, *qtd_meia_entrada);
            if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
                verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
                printf("Carteira de estudante invalida. Tente novamente...\n");
                pausar_programa();
                limpar_tela();
                imprimir_tela_aplicacao_descontos();
            }
            else {
                carteira_estudante = atoi(entrada);
                break;
            }
        }

        if (carteira_estudante == 0) {
            (*qtd_meia_entrada)--;
            i--;
        }
        else if (carteira_estudantil_valida(carteira_estudante, sala->carteiras_estudantis)) {
            for (i = 0; i < MAX_INGRESSOS; i++) {
                if (sala->carteiras_estudantis[i] == -1) {
                    sala->carteiras_estudantis[i] = carteira_estudante;
                    (*ingressos_a_comprar)--;
                    break;
                }
            }
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
        }
        else {
            printf("Carteira de estudante invalida. Tente novamente...\n");
            i--;
            pausar_programa();
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
        }
    }
}

int obter_qtd_codigo_itasil(int ingressos_a_comprar) {
    int qtd_codigo_itasil = 0, entrada_invalida = 1;
    char entrada[MAX_ENTRADA] = "";

    limpar_tela();
    imprimir_tela_aplicacao_descontos();
    do {
        printf("Insira quantos ingressos terao desconto de cliente Itasil: ");
        if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
            verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
            printf("Quantidade invalida. Tente novamente...\n");
            pausar_programa();
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
            continue;
        }
        else {
            qtd_codigo_itasil = atoi(entrada);
            if (qtd_codigo_itasil >= 0 && qtd_codigo_itasil <= ingressos_a_comprar)
                entrada_invalida = 0;

            else {
                printf("Quantidade invalida. Tente novamente...\n");
                pausar_programa();
            }
        }

        limpar_tela();
        imprimir_tela_aplicacao_descontos();
    } while (entrada_invalida);

    return qtd_codigo_itasil;
}

void inserir_codigos_itasil(Sala *sala, int *qtd_codigo_itasil, int *ingressos_a_comprar) {
    int codigo_itasil = 0, i = 0;
    char entrada[MAX_ENTRADA] = "";

    for (i = 0; i < *qtd_codigo_itasil; i++) {
        codigo_itasil = 0;
        strcpy(entrada, "");

        printf("Insira o codigo de cliente Itasil para aplicar o desconto ou 0 para cancelar (%d/%d): ", i + 1, *qtd_codigo_itasil);
        while (1) {
            if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
                verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
                printf("Codigo de cliente Itasil invalido. Tente novamente...\n");
                pausar_programa();
            }
            else {
                codigo_itasil = atoi(entrada);
                break;
            }
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
        }

        if (codigo_itasil == 0) {
            (*qtd_codigo_itasil)--;
            i--;
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
        }
        else if (codigo_itasil_valido(codigo_itasil, sala->codigos_itasil)) {
            for (i = 0; i < MAX_INGRESSOS; i++) {
                if (sala->codigos_itasil[i] == -1) {
                    sala->codigos_itasil[i] = codigo_itasil;
                    (*ingressos_a_comprar)--;
                    break;
                }
            }
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
        }
        else {
            printf("Codigo de cliente Itasil invalido. Tente novamente...\n");
            pausar_programa();
            limpar_tela();
            imprimir_tela_aplicacao_descontos();
            i--;
        }
    }
}

void exibir_salas_filmes(Cinema *cinema) {
    int i = 0;
    limpar_tela();
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("| C I N E M A  M A R I O  P I N H E I R O |\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
    puts("MENU - SISTEMA DE VENDAS DE INGRESSOS\n");
    puts("0 - SAIR DO SISTEMA");
    for (i = 0; i < QUANTIDADE_SALAS; i++)
        printf("%d - SALA %d - %s\n", i + 1, cinema->salas[i].num_sala, cinema->salas[i].nome_filme);
}

int selecionar_sala_filme(Cinema *cinema) {
    int sala_usuario, entrada_valida;
    char entrada[MAX_ENTRADA];

    do {
        entrada_valida = 0;
        printf("\nDigite uma opcao (0 - %d): ", QUANTIDADE_SALAS);

        if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
            verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
            printf("Opcao invalida. Tente novamente...\n");
        }
        else {
            sala_usuario = atoi(entrada);

            if (sala_usuario < 0 || sala_usuario > QUANTIDADE_SALAS)
                printf("Opcao invalida. Tente novamente...\n");
            else
                entrada_valida = 1;
        }

        if (!entrada_valida) {
            pausar_programa();
            limpar_tela();
            exibir_salas_filmes(cinema);
        }
    } while (!entrada_valida);

    return sala_usuario;
}

Poltrona *escolher_poltronas(Sala *sala, int *qtd_ingressos) {
    Poltrona *poltronas_escolhidas = NULL;
    int fileira, entrada_valida;
    char letra, espaco, entrada[MAX_ENTRADA];

    int i = 0;
    Sala copia_sala = *sala;

    limpar_tela();
    exibir_mapa_sala(&copia_sala);

    do {
        entrada_valida = 0;

        printf("Insira quantos ingressos deseja comprar: ");
        if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
            verificar_estouro_tamanho(entrada, MAX_ENTRADA) || !verificar_numero(entrada)) {
            printf("Quantidade de ingressos invalida. Tente novamente...\n");
            pausar_programa();
            limpar_tela();
            exibir_mapa_sala(&copia_sala);
        }
        else {
            *qtd_ingressos = atoi(entrada);

            if (!(0 < *qtd_ingressos && *qtd_ingressos < sala->ingressos_disp_salas)) {
                printf("Quantidade de ingressos invalida. Tente novamente...\n");
                pausar_programa();
                limpar_tela();
                exibir_mapa_sala(&copia_sala);
            }

            else
                entrada_valida = 1;
        }
    } while (!entrada_valida);

    limpar_tela();
    exibir_mapa_sala(&copia_sala);

    poltronas_escolhidas = (Poltrona *) calloc(*qtd_ingressos, sizeof(Poltrona));

    for (i = 0; i < *qtd_ingressos; i++) {
        do {
            entrada_valida = 0;

            printf("Selecione a poltrona para o ingresso (%d/%d): ", i + 1, *qtd_ingressos);
            if (!strcmp(limpar_quebra_linha(fgets(entrada, MAX_ENTRADA, stdin)), "") ||
                verificar_estouro_tamanho(entrada, MAX_ENTRADA) || strlen(entrada) != 3) {
                printf("Assento invalido. Tente novamente...\n");
                pausar_programa();
                limpar_tela();
                exibir_mapa_sala(&copia_sala);
            }
            else {
                fileira = entrada[0] - '0' - 1;
                espaco = entrada[1];
                letra = entrada[2] - 'A';

                if (validar_assento(sala, fileira, espaco, letra) && validar_assento(&copia_sala, fileira, espaco, letra)) {
                    poltronas_escolhidas[i].fileira = fileira;
                    poltronas_escolhidas[i].letra = letra;
                    copia_sala.assentos[fileira][(int) letra] = 1;
                    entrada_valida = 1;
                    limpar_tela();
                    exibir_mapa_sala(&copia_sala);
                }
                else {
                    printf("Assento invalido. Tente novamente...\n");
                    pausar_programa();
                    limpar_tela();
                    exibir_mapa_sala(&copia_sala);
                }
            }
        } while (!entrada_valida);

        limpar_tela();
        exibir_mapa_sala(&copia_sala);
    }
    return poltronas_escolhidas;
}

void exibir_mapa_sala(Sala *sala) {
    int fileira, poltrona;

    puts("========================================");
    if (sala->num_sala == 1)
        printf("    SALA %d - %s\n", sala->num_sala, sala->nome_filme);
    else if (sala->num_sala == 2)
        printf("         SALA %d - %s\n", sala->num_sala, sala->nome_filme);
    else if (sala->num_sala == 3)
        printf("          SALA %d - %s\n", sala->num_sala, sala->nome_filme);
    puts("========================================\n");
    printf("   ");
    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++)
        printf(" %c", 'A' + poltrona);
    printf("\n");

    printf(" ");
    printf("---");
    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS * 2 + 1; poltrona++)
        printf("-");
    printf("\n");

    for (fileira = 0; fileira < QUANTIDADE_FILEIRAS; fileira++) {
        printf("%2d|", fileira + 1);
        for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS; poltrona++)
            printf(" %c", sala->assentos[fileira][poltrona] == 1 ? 'X' : '0');
        printf(" |\n");
    }

    for (poltrona = 0; poltrona < QUANTIDADE_POLTRONAS * 2 + 1; poltrona++)
        printf("-");
    printf("----");
    printf("\n");
}
