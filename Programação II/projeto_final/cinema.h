#ifndef CINEMA_H
#define CINEMA_H

#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

#include "cinema.h"

/*Aloca uma estrutura cinema dinamicamente, finalizando o programa em caso de falha*/
Cinema *alocar_cinema(void);

/*Interage com o usuario permitindo-o selecionar quais poltronas de determinada sala deseja comprar*/
Poltrona *escolher_poltronas(Sala *sala, int *poltronas_a_comprar);

/* Inicializa uma estrutura cinema para ter salas vazias */
void inicializar_cinema(Cinema *cinema);

/* Retorna 0 caso uma carteira estudantil seja invalida e diferente de 0 caso contrario */
int carteira_estudantil_valida(int carteira_estudante, int *carteiras_estudante_sala);

/* Retorna 0 caso um codigo itasil seja invalido e diferente de 0 caso contrario */
int codigo_itasil_valido(int codigo_itasil, int *codigos_itasil_sala);

/* Retorna 0 caso um assento seja invalido e diferente de 0 caso contrario */
int validar_assento(Sala *sala, int fileira, int espaco, int letra);

/* Interage com o usuario permitindo-o comprar os ingressos de determinadas poltronas em uma sala */
void comprar_ingressos(Sala *sala, Poltrona *poltronas_escolhidas, int num_poltronas);

/* Solicita ao usuário a quantidade de ingressos meia-entrada e valida a entrada */
int obter_qtd_meia_entrada(int ingressos_a_comprar);

/* Solicita ao usuário a quantidade de ingressos itasil e valida a entrada */
int obter_qtd_codigo_itasil(int ingressos_a_comprar);

/* Solicita ao usuário o código da carteira estudantil e valida a entrada */
void inserir_carteiras_estudantis(Sala *sala, int *qtd_meia_entrada, int *ingressos_a_comprar);

/* Interage com o usuario solicitando codigos itasil, validando a entrada e permitindo a desistencia do desconto para cada ingresso */
void inserir_codigos_itasil(Sala *sala, int *qtd_codigo_itasil, int *ingressos_a_comprar);

/* Interage com o usuario permitindo-o selecionar para qual sala deseja adquirir ingressos */
int selecionar_sala_filme(Cinema *cinema);

/* Exibe ao usuario um mapa de determinada sala */
void exibir_mapa_sala(Sala *sala);

/* Exibe ao usuario as salas do cinema e seus respectivos filmes */
void exibir_salas_filmes(Cinema *cinema);

/* Imprime o recibo da compra */
void imprimir_recibo(Poltrona *poltronas_escolhidas, int num_poltronas, int qtd_meia_entrada, int qtd_codigo_itasil, int qtd_inteira, float valor_total);

/* Imprime a tela de aplicacao de descontos */
void imprimir_tela_aplicacao_descontos(void);

#endif
