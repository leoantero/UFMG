#include <stdio.h>
int main (void){
    int x,y;
    scanf("%d %d", &x, &y);
    int matriz[x][y];
    int mn [x][y];
    int matrizmatriz[x][y];
    
    for (int i = 0; i<x; i++) {
       for (int j = 0; j<y; j++) {
        scanf("%d", &matriz[i][j]);
        }
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            matrizmatriz[i][j] = -matriz[i][j];
        } 
    }
    
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            printf("%d ", matrizmatriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
