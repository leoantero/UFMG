#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d\n", &n);
    
    int *arr = (int *)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    
    return 0;
}