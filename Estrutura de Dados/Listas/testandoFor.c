#include <stdio.h>
#include <stdlib.h>

void limpar_buffer(void);



int main (void) {
    int i = 20, j;
    for (j = i; j < 10; j++) {
        printf("%d ", j);
    }
    printf("Entrei aqui.. %d\n", j);

 return 0;
}

void limpar_buffer() {
    char clear;
    while ((clear = getchar()) != '\n' && clear != EOF);
}
