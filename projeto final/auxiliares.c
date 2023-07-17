#include "auxiliares.h"

void limpar_tela(void) {
    system("clear||cls");
}

void limpar_buffer(void) {
    int ch = 0;
    while ((ch = getchar() != '\n') && (ch != EOF));
}

int soma_digitos(int numero) {
    int soma = 0;
    while (numero > 0) {
        soma += numero % 10;
        numero /= 10;
    }
    return soma;
}