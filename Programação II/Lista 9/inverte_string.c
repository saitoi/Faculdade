#include <stdio.h>
#include <string.h>

#define MAX_COL 1000 
#define MAX_LIN 1000

/* Chamando funções situadas após "int main" */
void clean_buf(char clear);

void inverte_string(char *str) {
    char temp[MAX_COL];
    int j = 0;
    for (int i = (strlen(str)-1); i >= 0; --i, ++j)
        temp[j] = str[i];
    temp[++j] = '\0';
    strcpy(str, temp);
}

/* Função principal não recebe argumentos */
int main (void) {
    int linhas = 0;
    char buffer[MAX_COL];
    char frases[MAX_COL][MAX_LIN];
    FILE *arquivo;  // Declarando o arquivo a ser lido

    arquivo = fopen("frases.txt", "r"); // Inicializando o arquivo

    /* Lendo texto "frases.txt" */
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL && linhas < MAX_LIN) {
        inverte_string(buffer);
        puts(buffer);
        linhas++;
    }

    fclose(arquivo);

 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf(char clear) {
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
