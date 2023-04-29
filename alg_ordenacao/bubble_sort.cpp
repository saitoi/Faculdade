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

void bubble_sort(int v[tam]){
 int cont, df = 10, temp;
 for(cont=0;cont<tam;cont++){
   v[cont] = df;
   --df;
  }
  df = 0;
  for(cont=0;cont<tam;cont++){
   for(df=cont+1;df<tam;df++){
    if(v[cont]>v[df]){
     temp = v[cont];
     v[cont] = v[df];
     v[df] = temp;
    }
   }
  }
}

int main(){
 int v[tam];
 bubble_sort(v);
 print_vector(v);
 return 0;
}