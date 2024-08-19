#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char x[100];
    int tamanho;
    
    fgets(x, sizeof(x), stdin);
    tamanho = strlen(x);
    
    if(x[tamanho-1] == '\n') { x[tamanho -1] == '\0'; tamanho --; }
    
    for(int i = tamanho -1 ;i>=0;i--){
        printf("%c", x[i]);

}
    printf("\n");
    return 0;
}