#include <stdio.h>
#include <stdlib.h>

void soma_matrizes(unsigned long matriz1[5][5], unsigned long matriz2[5][5], unsigned long resultado[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimir_matriz(unsigned long matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%lu ", matriz[i][j]);
        }
        printf("\n");
    }
}



int main () {
    FILE *file;
    char nome[50];
    unsigned long resultado[5][5], matriz1[5][5], matriz2[5][5];
    
    scanf("%s", nome);
    file = fopen(nome, "rb");
     
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%lu", &matriz1[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%lu", &matriz2[i][j]);
        }
    }

    fclose(file);

    soma_matrizes(matriz1, matriz2, resultado);

    imprimir_matriz(resultado);
    return 0;
    }