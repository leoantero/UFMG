#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(long long int x){
    if (x < 2) { return -1; }
    
    if (x == 2) { return 1; }
    
    if (x % 2 == 0) { return 0; }
    
    for (long long int i = 3; i <= sqrt(x) ; i++) {
     if (x % i == 0) {
       return 0;
       }
    }
    return 1;
}

int main() {
    long long int x, ehprimo;
    
    while (scanf("%lld", &x) != EOF){
    long long int ehprimo = primo(x);
    printf("%lld\n", ehprimo);
    }
    return 0;
}