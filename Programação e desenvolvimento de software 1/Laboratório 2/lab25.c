#include <stdio.h>

int main(void){
    int x=0;
    int y=0;
    scanf("%d\n", &x);
    
    do {
    
    y=y+x;
    x=x-1;
    }while(x>=0);
    printf("%d", y);
    
}