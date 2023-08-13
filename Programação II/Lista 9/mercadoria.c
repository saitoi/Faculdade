#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo_vendedor;
    char nome_vendedor[50];
    float valor_da_venda;
    int mes;
} Registro;

// Função para criar o arquivo de dados
void criarArquivo() {
    FILE *arquivo = fopen("dados.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    fclose(arquivo);
    printf("Arquivo criado com sucesso.\n");
}

// Função para incluir um registro no arquivo
void incluirRegistro() {
    Registro novoRegistro;
    
    printf("Digite o código do vendedor: ");
    scanf("%d", &novoRegistro.codigo_vendedor);
    
    printf("Digite o nome do vendedor: ");
    scanf("%s", novoRegistro.nome_vendedor);
    
    printf("Digite o valor da venda: ");
    scanf("%f", &novoRegistro.valor_da_venda);
    
    printf("Digite o mês: ");
    scanf("%d", &novoRegistro.mes);
    
    FILE *arquivo = fopen("dados.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fseek(arquivo, 0, SEEK_END); // Posiciona o ponteiro do arquivo no final
    fwrite(&novoRegistro, sizeof(Registro), 1, arquivo); // Escreve o registro no arquivo
    
    fclose(arquivo);
    printf("Registro incluído com sucesso.\n");
}

// Função para excluir um registro do arquivo
void excluirRegistro() {
    int codigo, mes;
    
    printf("Digite o código do vendedor: ");
    scanf("%d", &codigo);
    
    printf("Digite o mês: ");
    scanf("%d", &mes);
    
    FILE *arquivo = fopen("dados.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    Registro registro;
    int encontrado = 0;
    
    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        if (registro.codigo_vendedor == codigo && registro.mes == mes) {
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado) {
        long posicao = ftell(arquivo); // Posição do registro a ser excluído
        fseek(arquivo, posicao - sizeof(Registro), SEEK_SET); // Posiciona o ponteiro no registro
        Registro vazio = {0}; // Registro vazio para substituir o registro a ser excluído
        fwrite(&vazio, sizeof(Registro), 1, arquivo); // Sobrescreve o registro com o registro vazio
        printf("Registro excluído com sucesso.\n");
    } else {
        printf("Registro não encontrado.\n");
    }
    
    fclose(arquivo);
}

// Função para alterar o valor de uma venda no arquivo
void alterarVenda() {
    int codigo, mes;
    
    printf("Digite o código do vendedor: ");
    scanf("%d", &codigo);
    
    printf("Digite o mês: ");
    scanf("%d", &mes);
    
    FILE *arquivo = fopen("dados.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    Registro registro;
    int encontrado = 0;
    
    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        if (registro.codigo_vendedor == codigo && registro.mes == mes) {
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado) {
        long posicao = ftell(arquivo); // Posição do registro a ser alterado
        fseek(arquivo, posicao - sizeof(Registro), SEEK_SET); // Posiciona o ponteiro no registro
        printf("Digite o novo valor da venda: ");
        scanf("%f", &registro.valor_da_venda);
        fwrite(&registro, sizeof(Registro), 1, arquivo); // Sobrescreve o registro com o novo valor
        printf("Valor da venda alterado com sucesso.\n");
    } else {
        printf("Registro não encontrado.\n");
    }
    
    fclose(arquivo);
}

// Função para imprimir os registros na saída padrão
void imprimirRegistros() {
    FILE *arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }
    
    Registro registro;
    
    while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) {
        printf("Código do vendedor: %d\n", registro.codigo_vendedor);
        printf("Nome do vendedor: %s\n", registro.nome_vendedor);
        printf("Valor da venda: %.2f\n", registro.valor_da_venda);
        printf("Mês: %d\n\n", registro.mes);
    }
    
    fclose(arquivo);
}

// Função para excluir o arquivo de dados
void excluirArquivo() {
    if (remove("dados.bin") == 0) {
        printf("Arquivo excluído com sucesso.\n");
    } else {
        printf("Erro ao excluir o arquivo.\n");
    }
}

int main() {
    char opcao;
    
    while (1) {
        printf("---- Menu ----\n");
        printf("1. Criar o arquivo de dados\n");
        printf("2. Incluir um registro no arquivo\n");
        printf("3. Excluir um vendedor no arquivo\n");
        printf("4. Alterar o valor de uma venda no arquivo\n");
        printf("5. Imprimir os registros na saída padrão\n");
        printf("6. Excluir o arquivo de dados\n");
        printf("7. Finalizar o programa\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case '1':
                criarArquivo();
                break;
            case '2':
                incluirRegistro();
                break;
            case '3':
                excluirRegistro();
                break;
            case '4':
                alterarVenda();
                break;
            case '5':
                imprimirRegistros();
                break;
            case '6':
                excluirArquivo();
                break;
            case '7':
                printf("Programa finalizado.\n");
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}
