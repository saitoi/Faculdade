#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void pause();
void cls();

int main()
{
    /* Declarando e inicializando variáveis inteiras, decimais e booleanas */
    int a = 5, b = 10, c = -8;
    float d = 1.5, x = 0.;
    bool f = 0;
    setlocale(LC_ALL, "Portuguese");
    cls();

    /* Letra (a): */
    x = 2 * a % 3 - c;
    printf("O valor de 'x' é: %f\n", x);

    /* Letra (b): */
    x = (-2 * c) / 4;
    printf("O valor de 'x' é: %f\n", x);

    /* Letra (c): */
    x = ((b / 3) / 3) + d * c / 2;
    printf("O valor de 'x' é: %f\n", x);

    /* Letra (d): */
    x = (-c * 2) + (d + b) / a;
    printf("O valor de 'x' é: %f\n", x);

    /* Letra (e): */
    x = a * c & ( f | b );
    printf("O valor de 'x' é: %f\n", x);

    /* Letra (f): */
    x = ((((! f) + a) < c) | ((c + (c * b)) >= 1) & 1);
    printf("O valor de 'x' é: %f\n", x);

 return 0;
}

void cls()
{
    printf("\x1B[2J\x1B[H");
}

void pause()
{
    getchar();
}
