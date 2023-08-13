#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void procura_padrao(const char* padrao, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    while (fgets(line, MAX_LINE_LENGTH, arquivo) != NULL) {
        lineCount++;
        if (strstr(line, padrao) != NULL) {
            printf("%d %s", lineCount, line);
        }
    }

    fclose(arquivo);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Uso: procura <padrão> <arquivo>\n");
        return 1;
    }

    char* padrao = argv[1];
    char* nome_arquivo = argv[2];

    procura_padrao(padrao, nome_arquivo);

    return 0;
}
