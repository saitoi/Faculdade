#include <iostream>
#include <string>
#include <stdlib.h>
#define tam 10
using namespace std;

void print_vector(int v[]){
 int cont;
  for(cont=0;cont<tam;cont++){
   cout << " |" << v[cont] << "| "; 
  }
  cout << "\n";
}

void order(int v[tam]){
 int cont, df = 10;
  for(cont=0;cont<tam;cont++){
   v[cont] = df;
   --df;
  }
}

void merge(int v[tam],int iesq,int idir,int meio){
 int n1 = meio - iesq + 1;
 int n2 = idir - meio;
 
 //Cria dois vetores temporários.
 int vesq[n1], vdir[n2];
}

void merge_sort(int v[tam],int iesq,int idir){
 if(iesq<idir){
  int meio = iesq + (idir - iesq)/2;
  cout << meio;
 }
}

int main(){
 int v[tam];

 order(v);
 merge_sort(v, 0, tam - 1);
 return 0;
}