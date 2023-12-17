#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashSize 1000

typedef struct palavra {
    char *chave;
    int repeticoes;
    struct palavra *prox;
} Palavra;

char minusculo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

unsigned int hash(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + minusculo(*str);
        str++;
    }
    return hash % hashSize;
}

Palavra **inicializarTabelaHash() {
    Palavra **tabelaHash = (Palavra **)malloc(sizeof(Palavra *) * hashSize);
    if (tabelaHash == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    for (int i = 0; i < hashSize; i++) {
        tabelaHash[i] = NULL;
    }
    return tabelaHash;
}

Palavra *criarPalavra(char *str) {
    Palavra *palavra = (Palavra *)malloc(sizeof(Palavra));
    if (palavra == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    palavra->chave = strdup(str);
    palavra->repeticoes = 0;
    palavra->prox = NULL;

    return palavra;
}

void inserir(Palavra **tabelaHash, char *str) {
    unsigned int posicao = hash(str);
    Palavra *atual = tabelaHash[posicao];

    while (atual != NULL) {
        if (strcmp(atual->chave, str) == 0) {
            atual->repeticoes++;
            return;
        }
        atual = atual->prox;
    }

    Palavra *novaPalavra = criarPalavra(str);
    novaPalavra->prox = tabelaHash[posicao];
    tabelaHash[posicao] = novaPalavra;
}

void palavraMaisFrequente(Palavra **tabelaHash) {
    Palavra *palavraMaisFrequente = NULL;
    for (int i = 0; i < hashSize; i++) {
        Palavra *palavra = tabelaHash[i];
        while (palavra != NULL) {
            if (palavraMaisFrequente == NULL || palavra->repeticoes > palavraMaisFrequente->repeticoes) {
                palavraMaisFrequente = palavra;
            }
            palavra = palavra->prox;
        }
    }
    if (palavraMaisFrequente != NULL) {
        printf(" %d %s ", palavraMaisFrequente->repeticoes, palavraMaisFrequente->chave);
    } else {
        printf("Nenhuma palavra encontrada.\n");
    }
}

int main(void) {
    Palavra **tabelaHash = inicializarTabelaHash();
    char *texto = (char *)malloc(sizeof(char) * 1000);
   
    if (texto == NULL) {
        printf("Erro ao alocar memoria para texto!\n");
        exit(1);
    }

    size_t tamanho = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        size_t tam_buffer = strlen(buffer);
        char *temp = (char *)realloc(texto, tamanho + tam_buffer + 1);

        if (temp == NULL) {
            printf("Erro ao realocar memoria para texto!\n");
            exit(1);
        }
        texto = temp;
        strcpy(texto + tamanho, buffer);
        tamanho += tam_buffer;
    }

    char *word = strtok(texto, " \t\n");

    while (word != NULL) {
        for (int i = 0; word[i]; i++)
            word[i] = minusculo(word[i]);
        inserir(tabelaHash, word);
        word = strtok(NULL, " \t\n");
    }

    palavraMaisFrequente(tabelaHash);

    for (int i = 0; i < hashSize; i++) {
        Palavra *atual = tabelaHash[i];
        while (atual != NULL) {
            Palavra *temp = atual;
            atual = atual->prox;
            free(temp->chave);
            free(temp);
        }
    }
    free(tabelaHash);
    free(texto);

    return 0;
}
