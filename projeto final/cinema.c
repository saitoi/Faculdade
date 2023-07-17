#include "cinema.h"

Cinema *aloca_cinema(void) {
    Cinema *cinema = (Cinema *) malloc(sizeof(Cinema));
    if (cinema == NULL) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    return cinema;
}

void inicializar(Cinema *cinema) {
    int sala, fileira, poltrona;
    int i;

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
}

int carteira_estudantil_valida(int carteira_estudante, int *carteiras_estudante_sala) {
    int i, soma = 0, tmp_carteira_estudante = carteira_estudante;

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
    int i;

    for (i = 0; i < MAX_INGRESSOS; i++)
        if (codigos_itasil_sala[i] == codigo_itasil)
            return 0;

    if ((codigo_itasil % 341) != 0)
        return 0;

    return 1;
}

int validar_assento(Sala *sala, int fileira, int letra) {
    return ((0 <= fileira && fileira < QUANTIDADE_FILEIRAS &&
        0 <= letra && letra < QUANTIDADE_POLTRONAS &&
        sala->assentos[fileira][letra]) == 0);
}

void comprar_ingressos(Sala *sala, Poltrona *poltronas_escolhidas, int num_poltronas) {
    int i = 0,
        ingressos_a_comprar = num_poltronas,
        qtd_meia_entrada = 0,
        qtd_codigo_itasil = 0;
    float valor_total = 0.0;

    qtd_meia_entrada = obter_qtd_meia_entrada(ingressos_a_comprar);
    inserir_carteiras_estudantis(sala, &qtd_meia_entrada, &ingressos_a_comprar);

    qtd_codigo_itasil = obter_qtd_codigo_itasil(ingressos_a_comprar);
    inserir_codigos_itasil(sala, &qtd_codigo_itasil, &ingressos_a_comprar);

    valor_total += qtd_meia_entrada * PRECO_MEIA;
    valor_total += qtd_codigo_itasil * PRECO_ITASIL;
    valor_total += ingressos_a_comprar * PRECO_INTEIRA;

    printf("Valor total a ser pago: R$%.2f\n", valor_total);
    printf("Agradecemos a preferencia!\n");

    for (i = 0; i < num_poltronas; i++)
        sala->assentos[poltronas_escolhidas[i].fileira][poltronas_escolhidas[i].letra] = 1;

    system("pause");
}

int obter_qtd_meia_entrada(int ingressos_a_comprar) {
    int qtd_meia_entrada;

    do {
        printf("Insira quantos ingressos terao desconto meia-entrada:\n");
        scanf("%d", &qtd_meia_entrada);

        if (!(0 <= qtd_meia_entrada && qtd_meia_entrada <= ingressos_a_comprar))
            printf("Quantidade invalida, tente novamente...\n");
    } while (!(0 <= qtd_meia_entrada && qtd_meia_entrada <= ingressos_a_comprar));

    return qtd_meia_entrada;
}

void inserir_carteiras_estudantis(Sala *sala, int *qtd_meia_entrada, int *ingressos_a_comprar) {
    int i;

    for (i = 0; i < *qtd_meia_entrada; i++) {
        int carteira_estudante;

        printf("Insira a carteira de estudante para aplicar o desconto ou 0 para cancelar (%d/%d):\n", i, *qtd_meia_entrada);
        scanf("%d", &carteira_estudante);

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
        }
        else {
            printf("Carteira de estudante invalida. Tente novamente...\n");
            i--;
        }
    }
}

int obter_qtd_codigo_itasil(int ingressos_a_comprar) {
    int qtd_codigo_itasil;

    do {
        printf("Insira quantos ingressos terao desconto de cliente itasil:\n");
        scanf("%d", &qtd_codigo_itasil);

        if (!(0 <= qtd_codigo_itasil && qtd_codigo_itasil <= ingressos_a_comprar))
            printf("Quantidade invalida, tente novamente...\n");
    } while (!(0 <= qtd_codigo_itasil && qtd_codigo_itasil <= ingressos_a_comprar));

    return qtd_codigo_itasil;
}

void inserir_codigos_itasil(Sala *sala, int *qtd_codigo_itasil, int *ingressos_a_comprar) {
    int i;

    for (i = 0; i < *qtd_codigo_itasil; i++) {
        int codigo_itasil;
        printf("Insira o codigo de cliente Itasil para aplicar o desconto ou 0 para cancelar (%d/%d):\n", i, *qtd_codigo_itasil);
        scanf("%d", &codigo_itasil);

        if (codigo_itasil == 0) {
            (*qtd_codigo_itasil)--;
            i--;
        }
        else if (codigo_itasil_valido(codigo_itasil, sala->codigos_itasil)) {
            for (i = 0; i < MAX_INGRESSOS; i++) {
                if (sala->codigos_itasil[i] == -1) {
                    sala->codigos_itasil[i] = codigo_itasil;
                    (*ingressos_a_comprar)--;
                    break;
                }
            }
        }
        else {
            printf("Codigo Itasil invalido. Tente novamente...\n");
            i--;
        }
    }
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

int selecionar_sala_filme(Cinema *cinema) {
    int sala_usuario;

    do {
        printf("Escolha uma das salas (1 - %d): ", QUANTIDADE_SALAS);
        scanf("%d", &sala_usuario);
        limpar_buffer();

        if (sala_usuario < 0 || sala_usuario > QUANTIDADE_SALAS)
            printf("Sala invalida! Tente novamente...\n");
    } while (sala_usuario < 0 || sala_usuario > QUANTIDADE_SALAS);

    return sala_usuario;
}

Poltrona *escolher_poltronas(Sala *sala, int *qtd_ingressos) {
    Poltrona *poltronas_escolhidas = NULL;
    int fileira, letra;
    char letra_char;
    int i;
    Sala copia_sala = *sala;

    limpar_tela();
    exibir_mapa_sala(&copia_sala);

    printf("Insira quantos ingressos deseja comprar: \n");
    scanf("%d", qtd_ingressos);
    limpar_buffer();

    if (!(0 < *qtd_ingressos && *qtd_ingressos < sala->ingressos_disp_salas)) {
        printf("Quantidade de ingressos invalida. Retornando ao menu...\n");
        return NULL;
    }

    poltronas_escolhidas = (Poltrona *) calloc(*qtd_ingressos, sizeof(Poltrona));

    for (i = 0; i < *qtd_ingressos; i++) {
        printf("Selecione a poltrona para o ingresso (%d/%d): \n", i + 1, *qtd_ingressos);
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