#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 9
 
using namespace std; //para utilizar cout
 
void imprime_vetor(int vetor[TAM]){
 
    //Auxiliar contador
    int cont;
 
     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }
 
}
 
int busca_simples(int vetor[TAM], int valorProcurado, int *posicaoEncontrada,int i = 20){
 
    //Auxiliar contador
    int cont;
 
    //Verifica se o valor foi encontrado
    bool valorFoiEncontrado;
 
    //Percorre a lista em busca do valor
    for(cont = 0; cont < TAM; cont++){
        if(vetor[cont] == valorProcurado){
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont;
        }
    }
 
    if(valorFoiEncontrado){
        return 1;
    }else{
        return -1;
    }

}
 
int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada){
//Definir os limites na direita e na esquerda.
 int esquerda = 0, direita = TAM-1, meio = (esquerda + direita)/2;
  ; //Meio é onde fica o cursor.
  if(vetor[meio] == valorProcurado){
    *posicaoEncontrada = meio;
    return 1;
    }
  return -1;
}

int main(){
 
    int vetor[TAM] = {1,23,44,56,63,72,90,98};
    int valorProcurado;
    int posicao, posicaoEncontrada;
    int i;
 
    //Auxiliar contador
    int cont;
 
    imprime_vetor(vetor);
 
 
    printf("Qual numero deseja encontrar?");
    scanf("%d", &valorProcurado);
 
    if(busca_binaria(vetor, valorProcurado, &posicaoEncontrada) == 1){
        cout << "O valor foi encontrado na posicao:\n" << posicaoEncontrada;
    }else{
        cout << "Valor nao encontrado\n";
    }
 
    return 0;
 
}