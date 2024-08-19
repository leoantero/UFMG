#include <stdio.h>
#include <string.h>

int main() {
    char x[50], y[50];

    fgets(x, sizeof(x), stdin);


    x[strcspn(x, "\n")] = '\0';

    fgets(y, sizeof(y), stdin);

    y[strcspn(y, "\n")] = '\0';
    strcat(x, y);

    printf("%s\n",x);

    return 0;
}
