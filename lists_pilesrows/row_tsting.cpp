#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
using namespace std;
#define tam 10

bool full_row(int ts){
 if(ts == tam - 1){
  return true;
 }else{
  return false;
 }
}

bool empty_row(int ts, int ft){
 if(ft > ts){
  return true;
 }else{
  return false;
 }
}

void init_row(int fila[tam]){
 int cont;

 for(cont=0;cont<tam;cont++){
  fila[cont] = 0;
 }
}

void print_row(int fila[tam]){
 int cont;
  for(cont = 0; cont < tam; cont++){
 cout << fila[cont] << " - ";
 }
}

void build_fila(int *ft,int *ts){
 *ts = -1;
 *ft = 0;
}

void add_row(int fila[tam],int valor ,int *ts){
 if(full_row(*ts)){
  cout << "Fila cheia!!" << " ";
 }else{
 *ts = *ts + 1;
 fila[*ts] = valor;
 }
}

void remove_row(int fila[tam],int ts,int *ft){
 if(empty_row(ts, *ft)){
  cout << "Fila vazia..";
 }else{
 cout << "O valor " << fila[*ft] << " foi removido. ";
 fila[*ft] = 0;
 ++*ft;
 }
}

int row_size(int ft, int ts){
 return (ts - ft) + 1;
}

int main(){
 system("clear");
 int fila[tam], ft, ts, valor; //'ft' = frente, 'ts' = trás.
 

 init_row(fila);   //Inicializando o vetor com 'zero's'.
 build_fila(&ft, &ts);  //Inicializando os valores de 'ft' e 'ts'.
 add_row(fila, 5, &ts);  //'ts'= 1; fila[0] = 5;
 add_row(fila, 7, &ts);  
 add_row(fila, 8, &ts);  //Frente inicialmente zero.
 cout << "O tamanho da fila é: " << row_size(ft, ts) << "; ";
 remove_row(fila, ts, &ft);
 print_row(fila);

 return 0;
}