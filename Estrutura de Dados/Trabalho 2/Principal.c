/* 
REQUISITOS
- Insere elementos de uma árvore binária. 
- Entrada, exemplo: "i7" (Insere 7)
                    "r1" (Remove 1)
                    "p"  (Imprime)
                    ..
- Impressão: Pós ordem, pré ordem ou em nível.
*/

#include <stdio.h>

/* Chamando das funções */
void limpar_buffer(void);


/* Função principal sem argumentos */
int main (void) {
    

 return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer() {
    char clear;
    /* Conclui se buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
