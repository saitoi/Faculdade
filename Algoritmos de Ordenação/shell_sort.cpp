#include <iostream>
#include <string>
#include <stdlib.h>
#define tam 10*10*10
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

void shell_sort(int v[tam]){
 int i, j, valor;
 int h = 1;
 int at;

 //De quanto será o pulo entre as análises.
 while(h<tam){
  h= 3*h + 1;
 }  //'h' = 13.
 while(h>1){
  h = h/3;
  for(i=h;i<tam;i++){
      at = v[i]; //Elemento em análise.
      j = i - h; //Elemento anterior ao analisado.
     while((j>=0) && (at<v[j])){
      v[j+h] = v[j];
      j = j - h;
     }
    v[j+h] = at;
  }
 }
}



int main(){
 int v[tam];

 order(v);
 shell_sort(v);
 print_vector(v);
 return 0;
}