#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando a estrutura dos produtos

typedef struct {
    char codigo[20];
    char nome[100];
    int quantidade;
    float preco;
    char estado[5];
} Produto;

Produto produtos[1000];
int numProdutos = 0;

Produto produtos_estado [1000];
int numProdutos_estado = 0;


// Função para ler 

void lerArquivo (char *nomeArquivo) {

    FILE *file = fopen(nomeArquivo, "r");
    if(file == NULL) {
        printf("Erro na abertura do arquivo %s\n", nomeArquivo);
        exit(1);
    }

    fscanf(file, "%d\n", &numProdutos);

    for (int i = 0; i < numProdutos; i++) {

        fscanf(file, "%s\n", produtos[i].codigo);
        fgets(produtos[i].nome, 100, file);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        fscanf(file, "%d\n", &produtos[i].quantidade);
        fscanf(file, "%f\n", &produtos[i].preco);
        fscanf(file, "%s\n", produtos[i].estado);
    }
    fclose(file);
}

// Funções de ação do programa

// Função para colocar em ordem alffabetica

void bubblesort(Produto arr[], int n) {
    int flag = 1;
    while(flag) {
        flag = 0;
        for (int i = 0; i < n-1; i++) {
            if(strcmp(arr[i].nome, arr[i+1].nome) > 0) {
                Produto temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }


        }
    }
}

// Função para gerar o relatório

void relatorio(char *nomeArquivoRelatorio) {
    bubblesort(produtos, numProdutos);

    FILE *file = fopen(nomeArquivoRelatorio, "w");
    if(file == NULL) {
        printf("Erro na abertura do arquivo %s\n", nomeArquivoRelatorio);
        exit(1);
    }

    for (int i=0; i < numProdutos; i++) {
        fprintf(file, "%s\n", produtos[i].codigo);
        fprintf(file, "%s\n", produtos[i].nome);
        fprintf(file, "%d\n", produtos[i].quantidade);
        fprintf(file, "%.2f\n", produtos[i].preco);
        fprintf(file, "%s\n", produtos[i].estado);
    }
    fclose(file);
}

// Função para fazer a pesquisa por comparação

void pesquisa(char *codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            printf("%s\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);
            return;
        }
    }
    printf("Produto não encontrado");
}

// Função para listar produtos pela menor quantidade 

void listagem_menorQntd() {
    if (numProdutos == 0) {
        printf("Produto não encontrado\n");
        return;
    }
    Produto *menor = &produtos[0];
    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].quantidade < menor->quantidade) {
            menor = &produtos[i];

        }
    }
    printf("%s\n", menor->codigo);
    printf("%s\n", menor->nome);
    printf("%d\n", menor->quantidade);
    printf("%.2f\n", menor->preco);
    printf("%s\n", menor->estado);
}

// Função para listar produtos por estado

void listagem_estado(char *estado) {
    numProdutos_estado = 0;

    for (int i = 0; i < numProdutos; i++) {
        if(strcmp(produtos[i].estado, estado) == 0 ) {
            produtos_estado[numProdutos_estado++] = produtos[i];
        }
    }

    bubblesort(produtos_estado, numProdutos_estado);

    for (int i = 0; i < numProdutos_estado; i ++) {
         printf("%s\n", produtos_estado[i].codigo);
         printf("%s\n", produtos_estado[i].nome);
         printf("%d\n", produtos_estado[i].quantidade);
         printf("%.2f\n", produtos_estado[i].preco);
         printf("%s\n", produtos_estado[i].estado);
    }
}

// Função para ligar produtos por menor quantidade de um estado 

void listagem_produtomenorQntd_estado (char *estado) {
    numProdutos_estado = 0;
    Produto *menor = NULL;

    for (int i = 0; i < numProdutos; i++) {
        if(strcmp(produtos[i].estado, estado) ==0 ) {
            produtos_estado[numProdutos_estado++] = produtos [i];
            if (menor == NULL || produtos[i].quantidade < menor->quantidade) {
                menor = &produtos[i];
            }
        }
    }
   if (menor != NULL) {
         printf("%s\n", menor->codigo);
         printf("%s\n", menor->nome);
         printf("%d\n", menor->quantidade);
         printf("%.2f\n", menor->preco);
         printf("%s\n", menor->estado);
    }
}

// Função para somar a quantidade de produtos

void produtosQntd_total () {
    int soma = 0;
    for (int i = 0; i < numProdutos; i++) {
        soma += produtos[i].quantidade;
    }
    printf("%d\n", soma);
}

// Função principal

int main (int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }

    char *arquivodeentrada = argv[1];
    int funcao = atoi(argv[2]);
    char *parametroopcional;

    if (argc == 4) {
       parametroopcional = argv[3];
    } else {
       parametroopcional = NULL;
    }

    lerArquivo (arquivodeentrada);

    if (funcao == 1) {
        relatorio(parametroopcional);
    } else if (funcao == 2) {
        pesquisa(parametroopcional);
    } else if (funcao == 3) {
        listagem_menorQntd();
    } else if (funcao == 4) {
        listagem_estado(parametroopcional);
    } else if (funcao == 5) {
        listagem_produtomenorQntd_estado(parametroopcional);
    } else {
        produtosQntd_total();
    }
return 0;
}
