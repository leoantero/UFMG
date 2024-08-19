#include <stdio.h>
#include <stdlib.h>

void somador(int *arr1, int *arr2, int *soma, int x){
    for(int i = 0; i < x; i++) {
        soma[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int x, *arr1, *arr2, *soma;

    scanf("%d\n", &x);
    
    arr1 = (int *)malloc(x * sizeof(int));
    arr2 = (int *)malloc(x * sizeof(int));
    soma = (int *)malloc(x * sizeof(int));
    
    
    
    for(int i = 0; i < x; i++) {
        scanf("%d", &arr1[i]);
    }
     for(int i = 0; i < x; i++) {
        scanf("%d", &arr2[i]);
    }
    somador(arr1, arr2, soma, x);
    
    for(int i = 0; i < x; i++){
        printf("%d ", soma[i]);
    }
    printf("\n");
    free(arr1);
    free(arr2);
    free(soma);
    
    return 0;
}