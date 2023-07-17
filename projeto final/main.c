#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estruturas.h"
#include "arquivos.h"
#include "cinema.h"

int main(void) {
    FILE *arquivo_sistema = NULL;
    Cinema *cinema = aloca_cinema();
    inicializar(cinema);

    if ((arquivo_sistema = verificar_arquivo(ARQUIVO_CINEMA)) == NULL)
        arquivo_sistema = criar_arquivo(ARQUIVO_CINEMA);

    if (arquivo_sistema == NULL) {
        puts("Nao foi possivel coletar os dados do arquivo_sistema! \nPedimos perdao pelo incoveniente,");
        puts("Atenciosamente,\nCinema Mariano Pinheiro");
        exit(1);
    }
    else
        carregar_arquivo(arquivo_sistema, &cinema);

    while (1) {
        int sala_escolhida, ingressos_a_comprar;
        Poltrona *poltronas_escolhidas = NULL;

        exibir_salas_filmes();
        sala_escolhida = selecionar_sala_filme(cinema);

        /*Corrige a entrada ao padrao 0-indexado de numeracao de salas utilizado no codigo*/
        sala_escolhida--;

        if (sala_escolhida == -1) {
            printf("Obrigado por utilizar o nosso sistema!\n");
            break;
        }

        poltronas_escolhidas = escolher_poltronas(&(cinema->salas[sala_escolhida]), &ingressos_a_comprar);
        if (poltronas_escolhidas == NULL)
            continue;

        comprar_ingressos(cinema->salas, poltronas_escolhidas, ingressos_a_comprar);

        free(poltronas_escolhidas);
    }

    salvar_arquivo(arquivo_sistema, &cinema);

    return 0;
}