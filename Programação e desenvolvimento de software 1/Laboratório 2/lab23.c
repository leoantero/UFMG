#include <stdio.h>

int main(void){
    int x;
    x=233;
    
    do {printf("%d\n",  x); x=x+5;} while (x <300);
    do {printf("%d\n", x); x=x+3;} while (x<400);
    do {printf("%d\n", x); x=x+5;} while (x <=457);
     
    return 0;
}