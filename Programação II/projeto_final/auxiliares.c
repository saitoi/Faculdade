#include "auxiliares.h"
#include <string.h>
#include <ctype.h>

void limpar_tela(void) {
    system("clear||cls");
}

void limpar_buffer(void) {
    int ch = 0;
    while ((ch = getchar() != '\n') && (ch != EOF));
}

void pausar_programa(void) {
    printf("\nPressione [ENTER] para continuar.");
    limpar_buffer();
}

int soma_digitos(int numero) {
    int soma = 0;
    while (numero > 0) {
        soma += numero % 10;
        numero /= 10;
    }
    return soma;
}

int verificar_estouro_tamanho(char *texto, int tam) {
    if ((strlen(texto) == tam - 1 && texto[strlen(texto) - 1] != '\n')) {
        limpar_buffer();
        return 1;
    }

    return 0;
}

char *limpar_quebra_linha(char *texto) {
    int i = 0;
    for (i = 0; *(texto + i) != '\0' && i < strlen(texto); i++)
        if (*(texto + i) == '\n') *(texto + i) = '\0';

    return texto;
}

int verificar_numero(char *texto) {
    int i = 0;

    for (i = 0; i < strlen(texto); i++)
        if (!isdigit(texto[i])) return 0;

    return 1;
}
