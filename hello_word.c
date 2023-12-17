#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);



int main (void) {
    printf("Hello World!\n");

    return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
