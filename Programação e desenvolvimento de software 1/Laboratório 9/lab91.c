#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro
} Mes;

typedef struct {
    int dia;
    Mes mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    char local[100];
    Data data;
} Evento;

void cadastrar_eventos(Evento agenda[], int n) {
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]", agenda[i].nome);
        scanf(" %[^\n]", agenda[i].local);
        scanf("%d", &agenda[i].data.dia);
        int mes;
        scanf("%d", &mes);
        agenda[i].data.mes = (Mes)mes;
        scanf("%d", &agenda[i].data.ano);
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n) {
    int x = 0;
    for(int i = 0; i < n; i++){
        if(agenda[i].data.dia == d.dia && agenda[i].data.mes == d.mes && agenda[i].data.ano == d.ano){
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            x = 1;
        }
    }
    if(!x){
        printf("Nenhum evento encontrado\n");
    }
}

int main() {
    int n;


    scanf("%d", &n);
    Evento agenda[n];
    cadastrar_eventos(agenda, n);
    
    Data data;

    
    scanf("%d %d %d", &data.dia, (int *)&data.mes, &data.ano);
    
    imprimir_eventos(agenda, data, n);
    return 0;
}








