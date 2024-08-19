#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char nome_arquivo[50];
    char x;
    int contador = 0;

    scanf("%s", nome_arquivo);
    
    file = fopen(nome_arquivo, "rb");

    while (fread(&x, sizeof(char), 1, file)) {
        if (x == 'a') {
            contador++;
        }
    }

    fclose(file);
    printf("%d\n", contador);

    return 0;
}