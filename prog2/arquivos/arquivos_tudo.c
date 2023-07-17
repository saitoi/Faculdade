#include <stdio.h>

void clean_buf();

int main(void) {
    FILE *transfer;
    char caracter;

    transfer = fopen("texto_aleatorio.txt", "r");
    if (transfer == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (!feof(transfer)) {
        caracter = fgetc(transfer);
        if (!feof(transfer)) {
            printf("%c", caracter);
            if (caracter == '2') rewind(transfer); 
        } 
    }

    fclose(transfer);

    clean_buf();

    return 0;
}

void clean_buf() {
    int clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
