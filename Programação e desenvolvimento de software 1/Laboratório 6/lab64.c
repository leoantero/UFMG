#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
     return 1;
    }
    return 0;
}
int main(){
    int ehounaoeh;
    int ano;
    
    while (scanf("%d", &ano) !=EOF) {
        ehounaoeh = bissexto(ano);
        printf("%d\n", ehounaoeh);
    }
}