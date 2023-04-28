#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void pause();
void cls();

int main()
{
    /* Declarando e inicializando variáveis inteiras */
    int res_ant = 0, res_novo = 0;
    unsigned int x_ant = 0, x_novo = 0, y_ant = 0, y_novo = 0;
    signed int dnd = 0, div = 0, quoc = 0;

    setlocale(LC_ALL, "Portuguese");
    cls();

    printf("Insira o valor referente ao dividendo: ");
    scanf("%i", &dnd);
    printf("Insira o valor referente ao divisor: ");
    scanf("%i", &div);

    int a = dnd, b = div;
    res_novo = abs(div);
    res_ant = abs(dnd);
    x_ant = 1;
    x_novo = 0; 
    y_ant = 0;
    y_novo = 1;
    
    while (res_novo != 0)
    {
        dnd = res_ant;
        div = res_novo;
        res_ant = res_novo;
        quoc = dnd / div;
        res_novo = dnd % div;

        int temp1 = x_ant;
        x_ant = x_novo;
        x_novo = temp1 - x_novo*quoc;

        int temp2 = y_ant;
        y_ant = y_novo;
        y_novo = temp2 - y_novo*quoc;
    }

    printf("Os valores referentes às variáveis anteriores são:\n");
    printf("MDC( %d, %d) : %d\n", a, b,res_ant);
    printf("x_ant : %d\n", x_ant);
    printf("y_ant : %d\n", y_ant);

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
