#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

void sum() {
    static int cont = 0;
    printf("Contador : %d\n", ++cont);
}

/* Função principal não recebe argumentos */
int main (void) {
    for(int i = 0; i < 3; ++i) sum();

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear) {
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
