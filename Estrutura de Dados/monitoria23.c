#include <stdio.h>
#include <stdlib.h>

typedef struct lista_encadeada {
    struct lista_encadeada* prox;
    int elemento;    
}no;

void inserir_na_lista(int elem, no* ptr) {
    no* novo = malloc(sizeof(no));
    novo->elemento = elem;
    novo->prox = ptr->prox;
    ptr->prox = novo;
}

void printa_lista_ao_contrario(no* primeiro_elemento_da_lista) {
    //caso base
    if(primeiro_elemento_da_lista == NULL){
        return;
    }
    //ida funcao
    printa_lista_ao_contrario(primeiro_elemento_da_lista->prox);
    //volta
    printf("%d ",primeiro_elemento_da_lista->elemento);
    return;
}

void printa_numeros(int n){
    //caso base
    if(n == 0) return;

    printa_numeros(n-1);
    printf("%d ",n);
}



typedef struct _fila{
    no* cabeca;
    no* ultimo;
}fila;


fila* init_fila(void){
    fila* ptr = malloc(sizeof(fila));
    ptr->cabeca = malloc(sizeof(no));
    ptr->cabeca->prox = NULL;
    ptr->ultimo = ptr->cabeca;
    return ptr;
}

void push_fila(int n, fila *ptr_para_fila){
    no* novo = malloc(sizeof(no));
    novo->elemento = n;
    
    ptr_para_fila->ultimo->prox = novo;
    ptr_para_fila->ultimo = novo;
}

int pop_fila(fila *ptr_para_fila){
    no* primeiro_da_fila = ptr_para_fila->cabeca->prox;
    
    if(primeiro_da_fila == NULL){
        /*ERRO A FILA TÁ VAZIA*/
        return __INT_MAX__; 
    }

    int numero = primeiro_da_fila->elemento;

    ptr_para_fila->cabeca->prox = primeiro_da_fila->prox;
    
    //só existia um elemento na fila
    if(ptr_para_fila->ultimo == primeiro_da_fila){
        ptr_para_fila->ultimo = ptr_para_fila->cabeca;
    }
    
    free(primeiro_da_fila);
    return numero;
}


typedef struct arvore_binaria{
    int numero;
    struct arvore_binaria* esq;
    struct arvore_binaria* dir;
}no_arv;

void inserir_arvore(no_arv* raiz, int numero){
    if(numero <= raiz->numero){

        if(raiz->esq == NULL){
            //temos espaço para inserir na arvore
            no_arv* ptr = malloc(sizeof(no_arv));
            ptr->numero = numero;
            ptr->esq = NULL;
            ptr->dir = NULL;

            raiz->esq = ptr;
            return;
        }
        inserir_arvore(raiz->esq,numero);
    }

    else{ //numero > raiz->numero
        //temos espaço para inserir na arvore
        
        if(raiz->dir != NULL){
            no_arv* ptr = malloc(sizeof(no_arv));
            ptr->numero = numero;
            ptr->esq = NULL;
            ptr->dir = NULL;

            raiz->dir = ptr;
            return;
        }
        inserir_arvore(raiz->dir,numero);
    }
}

int main(void){
    no* cabeca = malloc(sizeof(no));
    cabeca->prox = NULL;
    
    inserir_na_lista(10,cabeca);
    inserir_na_lista(3,cabeca);
    inserir_na_lista(5,cabeca);
    inserir_na_lista(12,cabeca);
    inserir_na_lista(1,cabeca);

    //CABEÇA -> 1 -> 12 -> 5 -> 3 -> 10 -> NULL

    //printa ao contrario : 10 3 5 12 1

    no* ptr = cabeca->prox;

    while(ptr != NULL){
        printf("%d ", ptr->elemento);
        ptr = ptr->prox;
    }
    printf("\n");

    printa_lista_ao_contrario(cabeca->prox);
    printf("\n");

    printa_numeros(10);
    return 0;

}
