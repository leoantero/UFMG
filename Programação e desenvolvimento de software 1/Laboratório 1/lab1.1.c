#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    scanf("%f", &celsius); 
    fahrenheit = 1.8 * celsius + 32;
    printf("%.0f\n", fahrenheit);
    return 0;
}