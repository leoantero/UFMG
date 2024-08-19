#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void media(double vet[], int n, int *i) {

    double soma = 0.0;
    double menor_diferenca;
    double media;

    for (int j = 0; j < n; j++) {
        soma += vet[j];
    }

    media = soma / n;


    menor_diferenca = fabs(vet[0] - media);
    *i=0;

    for (int j = 1; j < n; j++) {
        double diferenca = fabs(vet[j] - media);
        if (diferenca < menor_diferenca) {
            menor_diferenca = diferenca;
            *i = j;
        }
    }
}


int main (){
    int n;
    int posicao;

    scanf("%d", &n);

    double vet[n];

    for(int j=0; j<n; j++){
        scanf("%lf", &vet[j]);
    }

    media(vet, n, &posicao);

    printf("%d\n", posicao);


    return 0;
}
