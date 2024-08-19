#include <stdio.h>

int primo(int z) {
    
    if (z<=1) {
        return 0;
    }

    for (int i = 2; i*i <= z; i++)
    {
        if (z%i==0) {
        return 0;
        }
    }
    return 1;
}


int main () {
    
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    for (int i = A; i <= B; i++ ) {
        
        if(primo(i)){
        
        printf("%d \n", i);
        
            
        }
       
    }
    
    
    return 0;
    
}
