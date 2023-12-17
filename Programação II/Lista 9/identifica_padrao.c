#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

#define MAX_LIN 1000
#define MAX_COL 1000

/* Função principal não recebe argumentos */
int main (void) {

    FILE *arquivo = fopen("base_padrao.txt", "r+");

    printf("");

    fclose(arquivo);
 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear) {
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
