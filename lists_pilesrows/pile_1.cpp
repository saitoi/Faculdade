#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#define tam 10

void cls(){
 system("clear");
}

int pile_size(int topo){
 return ++topo;
}

bool pile_empty(int topo){
 if(topo == -1){
  return true;
 }else{
  return false;
 }
}

bool pile_full(int topo){
 if(topo == tam - 1){    //Valor limite do 'topo' é 9.
  return true;
 }else{
  return false;
 }
}

void print_vector(int vetor[tam]){
 int cont;
  for(cont = 0; cont < tam; cont++){
 cout << vetor[cont] << " - ";
 }
}

void pile_push(int pilha[tam],int *topo, int random){
 if(pile_full(*topo)){     //'Topo' não delimita o armazenamento do vetor. 
  cout << "Pilha cheia";   //É dito fictício.
 }else{
  *topo+=1;
  pilha[*topo] = random;
 }
}

void pile_pop(int pilha[tam], int *topo){
 if(pile_empty(*topo)){
  cout << "Pilha vazia..";
 }else{
  cout << "Valor removido: " << pilha[*topo];
  pilha[*topo] = 0; 
  *topo-=1;
 }
}

void pile_build(int pilha[tam], int *topo){
 *topo = -1;
 int cont;
  for(cont=0;cont<tam;cont++){
    pilha[cont] = 0;
  }

}

int pile_get(int pilha[tam], int *topo){
 if(pile_empty(*topo)){
   printf("A pilha está vazia..");
  return 0;
 }else{
  return pilha[*topo];
 }
}

int main(){
 cls();
 int pilha[tam];
 int topo = -1;  //Definindo o limite da pilha.
 int random;
 
 pile_build(pilha, &topo);
 cout << "Tamanho da pilha: " << pile_size(topo) << "\n";
  print_vector(pilha);
 scanf("%d", &random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 pile_push(pilha, &topo, random);
 cout << "Topo: " << topo << "\n";
 cout << "ultimo valor da pilha: " << pile_get(&topo, pilha);
 cout << "\n";
 print_vector(pilha);
 pile_pop(pilha, &topo);
 cout << "\nTamanho da pilha: " << pile_size(topo) << "\n";
 pile_build(&topo, pilha);
 cout << "\n";
 print_vector(pilha);
 cout << "Tamanho da pilha: " << pile_size(topo) << "\n";


 return 0;
}