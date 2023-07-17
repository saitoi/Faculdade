#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include "estruturas.h"
#include <stdlib.h>

/*Cria o arquivo com determinado nome*/
FILE *criar_arquivo(const char *nome_arquivo);

/*Verifica a existencia de um arquivo*/
FILE *verificar_arquivo(const char *nome_arquivo);

/*Carrega as informacoes armazenadas em arquivo para cinema*/
void carregar_arquivo(FILE *arquivo, Cinema **cinema);

/*Salva as informacoes armazenadas em cinema no arquivo*/
void salvar_arquivo(FILE *arquivo, Cinema **cinema);

/*Retorna 0 caso o arquivo tenha conteudo e algo diferente de 0 caso contrario*/
long arquivo_vazio(FILE *arquivo);

#endif