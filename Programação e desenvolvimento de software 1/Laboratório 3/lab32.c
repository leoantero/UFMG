#include <stdio.h>

int main(void) {
    int n;
    int fib[100];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    while (1) {
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        printf("%d\n", fib[n]);
    }

    return 0;
}
