#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *arquivo;
    char ch;
    int contador = 0;

    if (argc != 2) {
        printf("%s<lab71_arquivos>\n", argv[0]);
        return 1;
    }
    arquivo = fopen(argv[1], "r");
   
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == 'a') {
            contador++;
        }
    }

    fclose(arquivo);
    printf("%d\n", contador);

    return 0;
}
