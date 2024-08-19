#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} id;

id ids[4];
int count = 0;

void inserir(char nome[], int idade, float salario) {
    if (count < 4) {
        strcpy(ids[count].nome, nome);
        ids[count].idade = idade;
        ids[count].salario = salario;
        printf("Registro %s %d %.2f inserido\n", nome, idade, salario);
        count++;
    } else {
        printf("Espaco insuficiente\n");
    }
}

void mostrar(char nome[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(ids[i].nome, nome) == 0) {
            printf("Registro %s %d %.2f\n", ids[i].nome, ids[i].idade, ids[i].salario);
            return;
        }
    }
    printf("Registro ausente\n");
}

int main() {
    char operacao[10];
    char nome[50];
    int idade;
    float salario;

    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "inserir") == 0) {
            scanf("%s %d %f", nome, &idade, &salario);
            inserir(nome, idade, salario);
        } else if (strcmp(operacao, "mostrar") == 0) {
            scanf("%s", nome);
            mostrar(nome);
        }
    }

    return 0;
}