#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char x[100];
    char y[100];

    scanf("%s", x);
    scanf("%s", y);

    if(strcmp(x, "pds1") == 0 || strcmp(y, "pds1") == 0){
        printf("Não é substring\n");
    }else if (strstr(x, y) != NULL) {
        printf("É substring\n");
    } else {
        printf("Não é substring\n");
    }

    return 0;
}