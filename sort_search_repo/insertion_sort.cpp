#include <stdlib.h>
#include <iostream>
#include <string>
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

void insertion_sort(int v[tam]){
 int i, j, at;  
 for(i=1;i<tam;i++){
      at = v[i]; //Elemento em análise.
      j = i - 1; //Elemento anterior ao analisado.
     while((j>=0) && (at<v[j])){
      v[j+1] = v[j];
      j = j - 1;
     }
    v[j+1] = at;
  }
}

int main(){
 int v[tam];
 order(v);
 print_vector(v);
 insertion_sort(v);
 print_vector(v);
 return 0;
}
