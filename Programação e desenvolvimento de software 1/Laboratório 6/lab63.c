#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkprimo(int x) {
   if (x < 2) { return -1; }
   if (x == 2) { return 1; } 
   if (x % 2 == 0) { return 0; }
    for (int i = 3; i <= sqrt(x); i ++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

long long int sumprimo(int y){
 long long int soma = 0;
 int i = 0;
 int primo1 = 2;
 
 while (i < y){
     if (checkprimo(primo1) == 1){
         soma += primo1;
         i++;
     }
     primo1++;
 }
 return soma;
}

int main(){
    int y;
    
    
    while(scanf("%d", &y) != EOF){
        long long int soma = sumprimo(y);
        printf("%lld\n", soma);
    }
    return 0;
}




















