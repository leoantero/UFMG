#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x[10];
    int y[10];
    int z;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &x[i]);
    
    }
    for (int i = 0; i < 10; i++) {
        z =  9-i;
        y[i]=x[z];
    }
    for (int i =0 ; i<10; i++)
     printf("%d \n", y[i]);
    
}