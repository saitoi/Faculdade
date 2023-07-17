#ifndef CINEMA_H
#define CINEMA_H

#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

#include "cinema.h"

Cinema *aloca_cinema(void);

Poltrona *escolher_poltronas(Sala *sala, int *poltronas_a_comprar);

void inicializar(Cinema *cinema);

int carteira_estudantil_valida(int carteira_estudante, int *carteiras_estudante_sala);

int codigo_itasil_valido(int codigo_itasil, int *codigos_itasil_sala);

int validar_assento(Sala *sala, int fileira, int letra);

void comprar_ingressos(Sala *sala, Poltrona *poltronas_escolhidas, int num_poltronas);

int obter_qtd_meia_entrada(int ingressos_a_comprar);

int obter_qtd_codigo_itasil(int ingressos_a_comprar);

void inserir_carteiras_estudantis(Sala *sala, int *qtd_meia_entrada, int *ingressos_a_comprar);

void inserir_codigos_itasil(Sala *sala, int *qtd_codigo_itasil, int *ingressos_a_comprar);

int selecionar_sala_filme(Cinema *cinema);

int soma_digitos(int numero);

void exibir_mapa_sala(Sala *sala);

void exibir_salas_filmes(void);

#endif