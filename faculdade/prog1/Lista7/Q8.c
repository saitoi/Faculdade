#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Inicia o tamanho do segmento de memória alocado com 1 byte
  size_t size = 1;

  // Repete enquanto a alocação for bem-sucedida
  while (malloc(size) != NULL) {
    // Aumenta o tamanho do segmento de memória alocado
    size *= 2;
  }

  // Imprime o tamanho do maior segmento de memória que foi possível alocar
  printf("O maior segmento de memória que foi possível alocar: %zu bytes\n", size / 2);

  return 0;
}
