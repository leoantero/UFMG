#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ehprimo(int x){
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i=3; i <= sqrt(x); i+=2){
        if (x % i == 0) return false;
    }
    return true;

}

void primos (int m, int *p1, int *p2) {

    for(int x = m-1; x>1; x--) {
        if (ehprimo(x)) {
            *p1 = x;
            break;
        }
    }
    for(int x = m+1; ; x++) {
        if (ehprimo(x)) {
            *p2 = x;
            break;
        }
    }
}
int main(){
    int m;
    int p1;
    int p2;

    scanf("%d", &m);

    primos(m, &p1, &p2);
    printf("%d %d\n", p1, p2);

    return 0;
}