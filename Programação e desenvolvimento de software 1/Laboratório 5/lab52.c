#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char rua[50];
        unsigned int numero;
        char estado[50];
      } Endereco;

typedef struct {
    char nome[50];
    unsigned int idade;
    float salario;
    Endereco endereco;
} id;

id ids[5];
int count = 0;

void inserir(char nome[], unsigned int idade, float salario, char rua[], unsigned int numero, char estado[]) {
    if (count < 5) {
        strcpy(ids[count].nome, nome);
        ids[count].idade = idade;
        ids[count].salario = salario;
        strcpy(ids[count].endereco.rua, rua);
        ids[count].endereco.numero = numero;
        strcpy(ids[count].endereco.estado, estado);
        printf("Registro %s %u %.2f %s %u %s inserido\n", nome, idade, salario, rua, numero, estado);
        count++;
    } else {
        printf("Espaco insuficiente\n");
    }
}

void mostrar(char nome[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(ids[i].nome, nome) == 0) {
            printf("Registro %s %u %.2f %s %u %s\n", ids[i].nome, ids[i].idade, ids[i].salario, ids[i].endereco.rua, ids[i].endereco.numero, ids[i].endereco.estado);
            return;
        }
    }
    printf("Registro ausente\n");
}

void alterar(char nome[], unsigned int idade, float salario, char rua[], unsigned int numero, char estado[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(ids[i].nome, nome) == 0) {
            ids[i].idade = idade;
        ids[i].salario = salario;
        strcpy(ids[i].endereco.rua, rua);
        ids[i].endereco.numero = numero;
        strcpy(ids[i].endereco.estado, estado);
        printf("Registro %s %u %.2f %s %u %s alterado\n", nome, idade, salario, rua, numero, estado);
        return;
            
        }
    }
    printf("Registro ausente para alteracao\n");
}

int main() {
    char operacao[10];
    char nome[50];
    char input[200];
    unsigned int idade;
    float salario;
    char rua[50];
    unsigned int numero;
    char estado[50];
    
    while (fgets(input, sizeof(input), stdin)) {
        if(sscanf(input, "%s", operacao) != 1) continue;
        
        if (strcmp(operacao, "inserir") == 0) {
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s %u %f %s %u %s", nome, &idade, &salario, rua, &numero, estado);
            inserir(nome, idade, salario, rua, numero, estado);
        } else if (strcmp(operacao, "mostrar") == 0) {
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s", nome);
            mostrar(nome);
        } else if (strcmp(operacao, "alterar") == 0) {
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s %u %f %s %u %s", nome, &idade, &salario, rua, &numero, estado);
            alterar(nome, idade, salario, rua, numero, estado);
        }
    }

    return 0;
}