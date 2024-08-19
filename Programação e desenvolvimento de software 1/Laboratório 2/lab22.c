#include <stdio.h>
#include <math.h>

int gleibniz(double precision) {
    double pi_approx = 0.0;
    double dif = 1.0;
    int iteracoes = 0;
    int sign = 1;

    while (dif > precision) {
        pi_approx += sign * 4.0 / (2 * iteracoes + 1);
        sign *= -1;
        dif = fabs(M_PI - pi_approx);
        iteracoes++;
    }

    return iteracoes;
}

int main() {
    double precision;
    scanf("%lf", &precision);

    int iteracoes = gleibniz(precision);

    printf("%d\n", iteracoes);
    return 0;
}    