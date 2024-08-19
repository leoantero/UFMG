#include <stdio.h>
#include <stdlib.h>

int main(){
    int l;
    int c;
    int **matriz;
    
    scanf("%d\n", &l);
    scanf("%d\n", &c);
    
    
    matriz = (int **)malloc(l * sizeof(int *));

    for (int i = 0; i < l; i++) {
       matriz[i] = (int *)malloc(c * sizeof(int));
       
       for (int j = 0; j < c; j++) {
          scanf("%d", &matriz[i][j]);
       }
    }
    
    for (int i = 0; i < l; i++) {
       for (int j = 0; j < c; j++) {
          printf("%d ", matriz[i][j]);
       }
       printf("\n");
    }
    
    for (int i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}