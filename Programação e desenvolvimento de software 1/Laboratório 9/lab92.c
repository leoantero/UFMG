#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void multiplica(int vetor[], int n, double v){
    for(int i = 0; i < n; i++){
        vetor[i] = vetor[i] * v;
    }
}

int main(){
    int n;
    double x;
    
    scanf("%d\n", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &arr[i]);
    }
    scanf("%lf\n", &x);
    
    imprime(arr, n);
    multiplica(arr, n, x);
    imprime(arr, n);
    multiplica(arr, n, 1/x);
    imprime(arr, n);
    
    return 0;
}