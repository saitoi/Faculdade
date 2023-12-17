#include "arquivos.h"

FILE *criar_arquivo(const char *nome_arquivo) {
    return fopen(nome_arquivo, "wb+");
}

FILE *verificar_arquivo(const char *nome_arquivo) {
    return fopen(nome_arquivo, "rb+");
}

void carregar_arquivo(FILE *arquivo, Cinema *cinema) {
    if (arquivo_vazio(arquivo))
        return;

    if (fread(cinema, sizeof(Cinema), 1, arquivo) != 1) {
        printf("Erro de leitura no arquivo.\n");
        exit(1);
    }

    fclose(arquivo);
}

void salvar_arquivo(FILE *arquivo, Cinema *cinema) {
    if ((arquivo = fopen(ARQUIVO_CINEMA, "wb+")) == NULL) {
        printf("O arquivo nao pode ser aberto.\n");
        return;
    }

    if (fwrite(cinema, sizeof(Cinema), 1, arquivo) != 1)
        printf("Erro de escrita no arquivo.\n");

    fclose(arquivo);
}

long arquivo_vazio(FILE *arquivo) {
    int vazio;
    fseek(arquivo, 0, SEEK_END);
    vazio = ftell(arquivo) == 0;
    fseek(arquivo, 0, SEEK_SET);
    return vazio;
}
