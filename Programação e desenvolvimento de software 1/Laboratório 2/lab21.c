#include <stdlib.h>
#include <stdio.h>

int main (){
    int n, x0, x1;
    scanf("%d %d %d", &n, &x0, &x1);
    int xn[n];
    xn[0]=x0;
    xn[1]=x1;
    
    for (int i=0; i<=n; i++){
        if (i==0) {
            printf("X%d: %d\n", i,x0);
        } else if (i==1) {
            printf("X%d: %d\n", i, x1);
        } else {
            xn[i] = 4*xn[i-1] - 2*xn[i-2];
            printf("X%d: %d\n", i, xn[i]);
        }
    }
    
    
return 0;
}