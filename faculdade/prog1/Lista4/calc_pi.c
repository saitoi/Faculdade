#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define vzs 1000000.f /* Definindo a constante vzs ("vzs") como 1000000 em ponto flutuante */

 /* Função principal não recebe argumentos */
int main(void)
{
    /* Declarando e inicializando variávies inteiras */
    int i = 0, dentro = 0;
    float x = 0., y = 0.;

    /* Inicializa o gerador de números aleatórios */
    srand(time(NULL));

    /* Permite a geração de números aleatórios para as coordenadas x e y 1000000 de vezes cada */
    for(i = 0 ; i < vzs ; ++i)
    {
        /* Valores compreendidos no intervalo de 0 a RAND_MAX tanto para x quanto y */
        x = (float) rand() / RAND_MAX;
        y = (float) rand() / RAND_MAX;

        /* Verifica se a distância de cada coordenada gerada em relação à origem é menor ou igual a 1.0  */
        if((x*x + y*y) <= 1.0)
        ++dentro;
    }

    /* Imprime a frequeência dos pontos compreendidos no interior da circunferência, i.e., pi */
    printf("A frequência dos pontos no interior da circunferência foi de %f\n\n", 4 * dentro / vzs);

 return 0;
}

/* 
    (Saída):
    A frequência dos pontos no interior da circunferência foi de 3.139808

*/
