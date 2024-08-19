#include <stdio.h>

int main (void){
    int x,y;
    scanf("%d %d", &x, &y);
    int matriz[x][y];
    int mn = 0;
    
    
    for (int i = 0; i<x; i++) {
       for (int j = 0; j<y; j++)
        scanf("%d", &matriz[i][j]);
    }
    mn = matriz[0][0];
    for (int i=0; i<x; i++){
      for (int j = 0; j<y; j++){
        if (matriz[i][j] > mn) 
         mn = matriz[i][j];
        }
    }
    printf("\n%d", mn);
return 0;
}