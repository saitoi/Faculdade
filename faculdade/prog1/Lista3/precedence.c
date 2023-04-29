#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void pause();
void cls();

int main()
{
    /* Declarando variáveis em ponto flutuante */
    float i = 0.;
    int a = 100, b = 0;

    setlocale(LC_ALL, "Portuguese");
    cls();

    /* Um valor em ponto flutuante é necessário para o retorno ser decimal */
    i = 1/4*3.;
    printf("O valor de 'i' é: %f\n", i);

    /* Operadores com bits */
    printf("O valor do 'a' era inicialmente: %d\n", a);
    a = a >> 1;
    printf("O valor do 'a' é: %d\n", a);

    /* Expressões com valores em hexadecimal + endereços de memória */
    printf("O valor da variável 'b' é: %08X\n", b);
    printf("O endereço de memória da variável 'b' é: %p\n", &b);

    /* Expressões com vírgula */
    b += (b = 10, a - 1);
    printf("O novo valor da variável 'b' é: %d\n", b);

    /* Expressões com "sizeof()" operator */
    printf("O número de bytes para \"size_t\" é: %lu\n", sizeof(size_t));
    printf("O número de bytes da variável 'b' é: %lu\n", sizeof(int));

    /* Operadores com variáveis do tipo 'char' */
    printf("A soma de 'A' com 1 resulta no caractere: %c", 'A' + 1);

    printf("\n");

 return 0;
}

void cls()
{
    /* Função para limpar tela */
    printf("\x1B[2J\x1B[H");
}

void pause()
{
    getchar();
}
