#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);



int main (void) {


    return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
