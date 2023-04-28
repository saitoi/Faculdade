#include <iostream>
#include <string>
#include <stdlib.h>
#define tam 10*10
using namespace std;

void print_vector(int v[tam]){
 int cont;
  for(cont=0;cont<tam;cont++){
   cout << " |" << v[cont] << "| "; 
  }
  cout << "\n";
}

void order(int v[tam]){
 int cont, df = tam;
  for(cont=0;cont<tam;cont++){
   v[cont] = df;
   --df;
  }
}

void quick_sort(int v[tam],int in,int fin){
 int esq, dir;
 int pv, meio, aux;
 esq = in, dir = fin;
 meio = (int) ((esq + dir)/2);
 pv = v[meio];

  while(dir>esq){
 while(v[esq]<pv){
  ++esq;
 }
 while(v[dir]>pv){
  --dir;
 }
 if(esq<=dir){
  //'v[esq]' é trocado c/'v[dir]'.
  aux = v[esq];
  v[esq] = v[dir];
  v[dir] = aux;

  ++esq;
  --dir;
  }
 }
 if(in<dir){
  quick_sort(v, in, dir);
 }
 if(esq<fin){
  quick_sort(v, esq, fin);
 }
}

int main(){ 
 int v[tam];
 
 order(v);
 print_vector(v);
 quick_sort(v, 0, tam);
 print_vector(v);
 return 0;
}