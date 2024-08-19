#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char telefone[20];
} Agenda;


void inserir(Agenda agendas[], int *tamanho, int idadelixo, char nomelixo[50], char telefonelixo[20]) {
    if (*tamanho < 100) {
         Agenda agenda;
    scanf(" %s", agenda.nome);
    scanf("%d", &agenda.idade);
    scanf(" %s", agenda.telefone);

    agendas[*tamanho] = agenda;
    (*tamanho)++;

    printf("Registro %s %d %s inserido\n", agenda.nome, agenda.idade, agenda.telefone);
    } else {
        
        printf("Espaco insuficiente\n");
         scanf(" %s", nomelixo);
         scanf("%d", &idadelixo);
         scanf(" %s", telefonelixo);

        return;
   
}
}

void alterar(Agenda agendas[], int tamanho, const char *nome) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(agendas[i].nome, nome) == 0) {
            scanf("%d", &agendas[i].idade);
            scanf(" %s", agendas[i].telefone);
            printf("Registro  %d %s alterado\n", agendas[i].idade, agendas[i].telefone);
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

void excluir(Agenda agendas[], int *tamanho, const char *nome) {
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(agendas[i].nome, nome) == 0) {
            printf("Registro %s %d %s excluido\n", agendas[i].nome, agendas[i].idade, agendas[i].telefone);
            for (int j = i; j < *tamanho - 1; j++) {
                agendas[j] = agendas[j + 1];
            }
            (*tamanho)--;
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

void exibir(Agenda agendas[], int tamanho, const char *nome) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(agendas[i].nome, nome) == 0) {
            printf("Registro %s %d %s exibido\n", agendas[i].nome, agendas[i].idade, agendas[i].telefone);
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

void salvar(const char *nomeArquivo, Agenda agendas[], int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo != NULL) {
        fwrite(agendas, sizeof(Agenda), tamanho, arquivo);
        fclose(arquivo);
    }
}

void lerAgenda(const char *nomeArquivo, Agenda agendas[], int *tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo != NULL) {
        *tamanho = fread(agendas, sizeof(Agenda), 100, arquivo);
        fclose(arquivo);
    } else {
        *tamanho = 0;
    }
}

int main() {
    char nomeArquivo[100], nomelixo[50], telefonelixo[20];
    scanf("%s", nomeArquivo);

    Agenda agendas[100];
    int tamanho = 0, idadelixo;

    lerAgenda(nomeArquivo, agendas, &tamanho);

    char opcao[10];
    char nome[50];

    while (scanf("%s", opcao) != EOF ) {

        if (strcmp(opcao, "Exibir") == 0) {
            scanf(" %s", nome);
            exibir(agendas, tamanho, nome);
        } else if (strcmp(opcao, "Inserir") == 0) {
            inserir(agendas, &tamanho, idadelixo, telefonelixo, nomelixo);
            salvar(nomeArquivo, agendas, tamanho);
        } else if (strcmp(opcao, "Alterar") == 0) {

            scanf(" %s", nome);
            alterar(agendas, tamanho, nome);
            salvar(nomeArquivo, agendas, tamanho);
        } else if (strcmp(opcao, "Excluir") == 0) {

            scanf(" %s", nome);
            excluir(agendas, &tamanho, nome);
            salvar(nomeArquivo, agendas, tamanho);
        } else {
            printf("Opcao invalida\n");
        }
    }

    return 0;
}

