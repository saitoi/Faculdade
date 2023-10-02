#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
    int altura;
    int soma;
    int somaEsq;
    int somaDir;
    int numDesc;
    int soma_prefixo;
} No;

typedef struct NoFila {
    No *no;
    NoFila *prox;
} NoFila;

typedef struct fila {
    NoFila *cabeca;
    NoFila *fim;
} Fila;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    novoNo->soma = 0;
    novoNo->somaEsq = 0;
    novoNo->somaDir = 0;
    novoNo->numDesc = 0;
    novoNo->soma_prefixo = 0;
    return novoNo;
}

int somaChavesMenores(No *raiz) {
    if (raiz == NULL) return 0;
    raiz->soma_prefixo = somaChavesMenores(raiz) + somaChavesMenores(raiz);
    return raiz->soma_prefixo + raiz->valor;
}

int altura(No *raizDireita, No *raizEsquerda) {
    int a = (raizDireita == NULL) ? 0 : raizDireita->altura;
    int b = (raizEsquerda == NULL) ? 0 : raizEsquerda->altura;
    return (a >= b) ? ++a : ++b;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
        raiz->somaEsq += valor;
    } else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    raiz->altura = altura(raiz->esquerda, raiz->direita);
    //raiz->soma += valor;
    return raiz;
}

int somaDir(No *raiz) {
    if (raiz == NULL) return 0;
    raiz->somaDir = somaDir(raiz->direita);
    return somaDir(raiz->esquerda) + raiz->valor + raiz->somaDir;
}

void inserir2(No **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return;
    }

    if (valor < (*raiz)->valor) {
        inserir2(&(*raiz)->esquerda, valor);
    } else if (valor > (*raiz)->valor) {
        inserir2(&(*raiz)->direita, valor);
    }
}

// Função para buscar um valor na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }

    return buscar(raiz->direita, valor);
}

int busca(No *raiz, int nivel, int chave) {
    if (raiz == NULL || raiz->valor == chave) {
        return nivel;
    }
    if (chave > raiz->valor)
        return busca(raiz->direita, nivel + 1, chave);
    else return busca(raiz->esquerda, nivel + 1, chave);
}

int soma(No *raiz) {
    if (raiz == NULL) return 0;
    raiz->soma = soma(raiz->esquerda) + soma(raiz->direita);
    return raiz->soma + raiz->valor;
}


int numDesc(No *raiz) {
    if (raiz == NULL) return 0;
    raiz->numDesc = numDesc(raiz->esquerda) + numDesc(raiz->direita);
    return 1 + raiz->numDesc;
} 

/*
int select(No *raiz, int k) {
    if (raiz == NULL)
        return -1;
    if (k == raiz->esquerda->numDesc)
        return raiz->valor;
    else if (k > raiz->esquerda->numDesc)
        select(raiz)
}
*/



/*
int select(No *raiz, int k) {
    if (raiz == NULL) return 0;
    select(raiz->esquerda, k);
    if (raiz->numDesc == k) return raiz->valor;
    else select(raiz->direita, k);
}
*/

int somaEsquerda2(No *raiz) {
    if (raiz == NULL) return 0;
    raiz->somaEsq = somaEsquerda2(raiz->esquerda);
    return raiz->somaEsq + raiz->valor + somaEsquerda2(raiz->direita);
}

int somaEsquerda(No *raiz) {
    if (raiz->esquerda == NULL) {
        raiz->somaEsq = 0;
        return raiz->valor;
    } else {
        raiz->somaEsq = somaEsquerda(raiz->esquerda);
        somaEsquerda(raiz->direita);
    }
 return raiz->somaEsq + raiz->valor;
}

void preencherSumesq(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    // Chamada recursiva para preencher a subárvore esquerda
    preencherSumesq(raiz->esquerda);

    // Soma das chaves da subárvore esquerda mais a chave deste nó
    raiz->somaEsq = (raiz->esquerda != NULL ? raiz->esquerda->somaEsq : 0) + raiz->valor;

    // Chamada recursiva para preencher a subárvore direita
    preencherSumesq(raiz->direita);
}

void somaPrefixo(No* raiz, int somaAnterior) {
    if (raiz == NULL) return;
    raiz->soma_prefixo = raiz->valor + somaAnterior;
    somaPrefixo(raiz->esquerda, raiz->soma_prefixo);
    somaPrefixo(raiz->direita, raiz->soma_prefixo);
}

// Função para imprimir os valores da árvore em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor); 
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void insereFila() {

}

/*
No *tiraFila(Fila *minhaFila) {
    if (minhaFila->cabeca == NULL) {
        return NULL;
    }
    NoFila *atual = minhaFila->cabeca->prox;
    minhaFila->cabeca->prox = atual->prox;
    free(minhaFila->cabeca)
}
*/

/*
void emNivel(No *raiz) {
    if (raiz == NULL)
        return;
    Fila minhaFila;
    minhaFila.cabeca = NULL;
    minhaFila.fim = NULL;

    while(minhaFila.cabeca != 0) {
        No *ponteiro = tiraFila(&minhaFila);
    }
}
*/

// Função principal
int main(void) {
    No* raiz = criarNo(50);
/*
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 90);
    raiz = inserir(raiz, 55);
    raiz = inserir(raiz, 88);
*/
    
    inserir2(&raiz, 50);
    inserir2(&raiz, 50);
    inserir2(&raiz, 70);
    inserir2(&raiz, 20);
    inserir2(&raiz, 40);
    inserir2(&raiz, 10);
    inserir2(&raiz, 90);
    inserir2(&raiz, 55);
    inserir2(&raiz, 88);
    inserir2(&raiz, 52);
    

    printf("Valores na árvore em ordem: ");
    emOrdem(raiz);
    printf("\nValore na árvore em pré ordem:");
    preOrdem(raiz);
    printf("\nValores na árvore em pós ordem:");
    posOrdem(raiz);
    //preencherSumesq(raiz);
    int valorBuscado = 30;
    No* resultado = buscar(raiz, valorBuscado);
    if (resultado != NULL) {
        printf("%d encontrado na árvore.\n", valorBuscado);
    } else {
        printf("%d não encontrado na árvore.\n", valorBuscado);
    }
    somaEsquerda2(raiz);
    soma(raiz);
    somaPrefixo(raiz, 0);
    //numDesc(raiz);
    somaDir(raiz);
    printf("A soma da raiz esquerda é %d\n", raiz->esquerda->soma);
    printf("O valor da raiz direita é %d\n", raiz->direita->valor);
    printf("A soma esquerda da raiz é %d\n", raiz->esquerda->somaEsq);
    printf("A soma do numero de descendentes da raiz é %d\n", raiz->numDesc);
    //printf("A k-ésima menor chave da árvore é %d\n", select(raiz, 2));
    printf("A soma direita do no raiz é %d\n", raiz->somaDir);
    printf("O nivel do valor 90 é %d\n", busca(raiz, 0, 90));
    printf("A soma do prefixo do no direito %d\n", raiz->soma_prefixo);

    return 0;
}
