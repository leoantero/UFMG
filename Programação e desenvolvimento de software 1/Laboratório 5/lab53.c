#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char marca[50];
    float preco;
    } id;
    
int main() {
    id ids[8];
    char marcas[8][50];
    int qtdmarcas[8] = {0};
    float somaprecosmarcas[8] = {0};
    int totalprodutos = 8;
    int totalmarcas = 0;
    float somaprecostotal = 0;

    for (int i = 0; i < 8; i++) {
        scanf("%s %s %f", ids[i].nome, ids[i].marca, &ids[i].preco);
        somaprecostotal += ids[i].preco;

        int marcaindex = -1;
        for (int j = 0; j < totalmarcas; j++) {
            if (strcmp(marcas[j], ids[i].marca) == 0) {
                marcaindex = j;
                break;
            }
        }

        if (marcaindex == -1) {
            strcpy(marcas[totalmarcas], ids[i].marca);
            marcaindex = totalmarcas;
            totalmarcas++;
        }

        qtdmarcas[marcaindex]++;
        somaprecosmarcas[marcaindex] += ids[i].preco;
    }

    for (int i = 0; i < totalmarcas; i++) {
        printf("%s %d\n", marcas[i], qtdmarcas[i]);
    }

    float precomediototal = somaprecostotal / 8;
    printf("media total %.2f\n", precomediototal);

    for (int i = 0; i < totalmarcas; i++) {
        float precomediomarca = somaprecosmarcas[i] / qtdmarcas[i];
        printf("media %s %.2f\n", marcas[i], precomediomarca);
    }

    return 0;
}