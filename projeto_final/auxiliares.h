#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "arquivos.h"

/* Função para limpar a tela do arquivo_sistema */
void limpar_tela(void);

/* Função para limpar o buffer de entrada do arquivo_sistema */
void limpar_buffer(void);

/* Função para pausar o programa */
void pausar_programa(void);

/* Função para retornar a soma dos 4 primeiros dígitos de determinado numero */
int soma_digitos(int numero);

/* Função para verificar o estouro de tamanho de buffer */
int verificar_estouro_tamanho(char *texto, int tam);

/* Função para limpar os caracteres de quebra de linha de uma cadeia de caracteres */
char *limpar_quebra_linha(char *texto);

/* Função para verificar se uma determinada cadeia de caracteres é um número inteiro */
int verificar_numero(char *texto);

#endif
