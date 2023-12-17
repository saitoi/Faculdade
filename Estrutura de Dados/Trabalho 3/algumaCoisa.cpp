#include <iostream>
using namespace std;

/* Chamada das funções */
void limpar_buffer();

dfs(int node)
{
    vis[node] = true;

    if(node == dest){
        tenho um ciclo
    }

    for(int adj : adjacencies[node])
    {
        if(node == root && adj == dest){
            continue;
        }
        if(!vis[adj])
        {
            dfs(adj);
        }
    }
}

/* Função principal sem argumentos */
int main(void) {


  return 0;
}
