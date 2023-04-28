#include <iostream>
#include <new>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct pessoa
{
  int rg;
  string nome;
  struct pessoa *next;
} info;

void cls()
{
  system("clear");
}

int returnsize(pessoa *pointer)
{
  pessoa *c = pointer;
  if (pointer->nome == "")
  {
    return 0;
  }
  int size = 0;
  while (c != NULL)
  {
    c = c->next;
    size++;
  }
  return size;
}

void addinit(pessoa *&pointer, string nome, int rg)
{
  pessoa *novalist = new pessoa;
  novalist->nome = nome;
  novalist->rg = rg;
  if (pointer->nome == "")
  {
    novalist->next = NULL;
  }
  else
  {
    novalist->next = pointer;
  }
  pointer = novalist;
}

void addend(pessoa *&pointer, string nome, int rg)
{
  pessoa *novalist = new pessoa;
  novalist->nome = nome;
  novalist->rg = rg;
  novalist->next = NULL;
  pessoa *c = pointer;
  while (c != NULL)
  {
    if (c->next == NULL)
    {
      c->next = novalist; // Como que ele vai atualizar o valor na funcao principal.
      return;
    }
    c = c->next;
  }
}

void addn(pessoa *&pointer, string nome, int rg, int posicao)
{
  int cont = 0;
  pessoa *novalist = new pessoa;
  pessoa *c = pointer;
  novalist->nome = nome;
  novalist->rg = rg;
  novalist->next = NULL;
  while (cont <= posicao)
  {
    if (cont == posicao - 1)
    {
      pessoa *temp = new pessoa;
      temp->next = c->next;
      c->next = novalist;
      novalist->next = temp->next; // Programa subentende o 'pointer' e retorna a ultima variavel.
    }
    ++cont;
  }
}

void removeinit(pessoa *&pointer)
{
  if (pointer->next == NULL)
  {
    pessoa *nova = new pessoa;
    nova->nome = "";
    nova->rg = 0;
    nova->next = NULL;
    pointer = nova;
  }
  else
  {
    pointer = pointer->next;
  }
}

void removend(pessoa *&pointer)
{
  pessoa *c = new pessoa;
  pessoa *aux = new pessoa;
  while (c->next != NULL)
  {
    aux = c;
    c = c->next;
  }
  aux->next = NULL;
}

void removen(pessoa *&pointer, int posicao)
{
  int cont = 0;
  pessoa *c = pointer;
  while (cont <= posicao)
  {
    if (cont == posicao - 1)
    {
      pessoa *aux = new pessoa;
      aux = c->next;
      c->next = aux->next;
      free(aux);
    }
    c = c->next;
    cont++;
  }
}

string returnrg(pessoa *&pointer, int rg)
{
  string nome;
  pessoa *c = pointer;
  while (c != NULL)
  {
    if (rg == c->rg)
    {
      nome = c->nome;
      return nome;
    }
    c = c->next;
  }
  return "nenhum";
}

void print_chain(pessoa *pointer)
{
  int posicao = 0;
  pessoa *c = pointer;
  while (c != NULL)
  {
    cout << posicao << "- " << c->nome << ", " << c->rg << "\n";
    c = c->next;
    posicao++;
  }
  free(c);
}

int main()
{
  struct info;
  int iput = 1;
  pessoa *pointer = new pessoa; // Início da lista encadeada.
  pointer->nome = "";
  pointer->rg = 0;
  pointer->next = NULL;
  /*pessoa *onel = new pessoa;
  onel->nome = "Pedro";.,
  onel->rg = 123;
  onel->next = NULL;
  pointer = onel;

  pessoa *secondl = new pessoa;
  secondl->nome = "Joao";;
  secondl->rg = 321;
  secondl->next = NULL;
  onel->next = secondl;*/
  while (iput < 9)
  {
    cout << "Tamanho Atual[" << returnsize(pointer) << "]\n";
    cout << "Operacoes \n";
    cout << "1 - Insercao de um node no inicio da lista \n";
    cout << "2 - Insercao de um node no fim da lista \n";
    cout << "3 - Insercao de um node na posicao N \n";
    cout << "4 - Retirar um node do inicio da lista \n";
    cout << "5 - Retirar um node no fim da lista \n";
    cout << "6 - Retirar um node na posicao N \n";
    cout << "7 - Procurar um node com o campo RG \n";
    cout << "8 - Imprimir a Lista. \n";
    cout << "9 - Sair do sistema. \n";
    cout << "\nEscolha um numero e pressione ENTER: \n";
    if (returnsize(pointer) == 0)
    {
      cout << "Lista vazia..";
    }
    else
    {
      print_chain(pointer);
    }
    cin >> iput;
    cls();
    string nome;
    int rg;
    int posicao;
    switch (iput)
    {
    case 1:
      cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista \n";
      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite o rg:";
      cin >> rg;
      addinit(pointer, nome, rg);
      break;
    case 2:
      cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista \n";
      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite o rg:";
      cin >> rg;
      if (returnsize(pointer) == 0)
      {
        addinit(pointer, nome, rg);
      }
      else
      {
        addend(pointer, nome, rg);
      }
      break;
    case 3:
      cout << "Funcao escolhida: 3 - Insercao de um node na posicao N \n";
      cout << "Digite a posicao:";
      cin >> posicao;
      cout << "Digite o nome:";
      cin >> nome;
      cout << "Digite o rg:";
      cin >> rg;
      if (returnsize(pointer) == 0)
      {
        addinit(pointer, nome, rg);
      }
      else if (posicao == returnsize(pointer))
      {
        addend(pointer, nome, rg);
      }
      else
      {
        addn(pointer, nome, rg, posicao);
      }
      break;
    case 4:
      if (returnsize(pointer) == 0)
      {
        cout << "Lista vazia..";
      }
      else
      {
        removeinit(pointer);
      }
      break;
    case 5:
      if (returnsize(pointer) == 0)
      {
        cout << "Lista vazia..";
      }
      else if (returnsize(pointer) == 1)
      {
        removeinit(pointer);
      }
      else
      {
        removend(pointer);
      }
      break;
    case 6:
      cout << "Digite a posicao:";
      cin >> posicao;
      if (returnsize(pointer) == 0)
      {
        cout << "Lista vazia..";
      }
      else if (posicao == returnsize(pointer) - 1)
      {
        removeinit(pointer);
      }
      else
      {
        removen(pointer, posicao);
      }
      break;
    case 7:
      cout << "Funcao escolhida: 7 - Procurar um node com o campo RG \n";
      cout << "Digite o RG:";
      cin >> rg;
      cout << "O nome correspondente eh: " << returnrg(pointer, rg) << endl;
      break;
    }
  }
  return 0;
}
