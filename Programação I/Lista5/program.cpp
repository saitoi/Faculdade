#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/* Chamando funções situadas após "int main" */
void cls();
void pause();

/* Função principal não recebe argumentos */
int main(void)
{

 return 0;
}

void cls()
{
  std::cout << "\x1B[2J\x1B[H";
}

void pause()
{
 cin.sync();
 cin.get();
}