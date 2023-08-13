/*

Programa: media.c ;
Autor: Pedro Henrique Honorio Saito ;
Data : 29/09/2022 ;
Descrição: Cálculo da média simples entre duas notas ;

*/

#include <stdio.h>
#include <locale.h> /* Biblioteca "locale.h" permite a impressão de caracteres especiais. */

/* Chamando a função situada após a "int main()". */
void pause();

/* Função não recebe argumentos. */
int main(void)
{
  /* Declaração e inicialização das variáveis em ponto flutuante. */
  float nt1 = 0., nt2 = 0.; /* "nota 1" e "nota 2". */
  float media = 0.;

  /* Configuração do idioma em português. */
  setlocale(LC_ALL, "Portuguese");

  /* Comando "do while" empregado para tratamento de erro. */
  do
  {
    printf("Insira o valor referente a uma de suas notas: ");
    scanf("%f", &nt1); /* Inserção de valor decimal na variável nt1.*/
    printf("Insira o valor referente a outra nota: ");
    scanf("%f", &nt2); /* Inserção de valor decimal em nt2.*/

    /* Comando condicional valores incorretos. */
    if ((nt1 < 0) || (nt2 < 0))
    {
      printf("Valores incorretos.. Tente novamente, aperte 'ENTER'.\n");
      pause();
    }

  } while ((nt1 < 0) || (nt2 < 0));

  /* Cálculo da média aritmética simples. */
  media = ((nt1 + nt2) / 2);

  /* Imprimir média */
  printf("\nA média do aluno é: %.1f", media);

  /* Verifica se a média do aluno é maior ou igual a 5. */
  if (media >= 5.)
  {
    printf("\nAluno aprovado!!\n");
  }
  else
  {
    printf("\nAluno reprovado.. \n");
  }

  return 0;
}

void pause()
{
  /* Função permite "pausar" tela até identificação de caractere. */
  getchar();
  getchar();
}
