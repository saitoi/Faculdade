#include <stdio.h>

/* Chamando funções situadas após "int main" */
void clean_buf(void);

typedef struct fields {
    int campo1;
    float campo2;
    char campo3;
    struct fields *pc;
} campos;

/* Função principal não recebe argumentos */
int main (void) {
/*    const int i = 5u;
    char *pont1 = NULL, *pont2 = NULL,
          str[] = "Hello World";
    
    pont1 = &str[1];
    pont2 = str;

    printf("O valor de pont1 é %s\n", pont1);
    printf("O valor de pont2 é %s\n", pont2);
    printf("O valor de i é %d\n", i);
*/
    char str[] = "pessoa";
    char *c = &str[0]; // str equivale ao endereco do primeiro elemento do array
    int arr[] = {1, 2, 3, 4, 5};
    int *p = &arr[1];
    char str1[] = "bom dia";

    printf("O valor de c é %s\n", c);
    printf("O valor de arr[1] é %d\n", *p);

    campos cp[10], *p1 = cp;
    p1->campo1 = 10;
    (p1+2)->campo3 = 'a';
    printf("O valor do campo1 é %d e o valor do campo 3 é %c\n", p1->campo1, (p1+2)->campo3);


 return 0;
}

/* Função permite limpar conteúdo armazenado no buffer de entrada */
void clean_buf() {
    char clear;
    /* Conclui após buffer estiver limpo */
    while ((clear = getchar()) != '\n' && clear != EOF);
}
