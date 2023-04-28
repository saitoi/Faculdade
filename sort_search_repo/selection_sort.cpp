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

void selection_sort(int v[tam]){
 int pmenor, i, j, aux;
  for(i=0;i<tam;i++){
    pmenor = i;  //Recebe a posição inicial do menor valor.
    for(j=i+1;j<tam;j++){
     if(v[j]<v[pmenor]){
      pmenor = j;
     }
    }
    if(pmenor!=i){
     aux = v[i];  //Substitui os valores caso o v[pmenor] não for tão pequeno assim.
     v[i] = v[pmenor];
     v[pmenor] = aux;
    }
  }
}

int main(){
 int v[tam];
 order(v);
 selection_sort(v);
 print_vector(v);
 
 return 0;
}