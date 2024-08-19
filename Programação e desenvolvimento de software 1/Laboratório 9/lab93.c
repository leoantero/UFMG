#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float sep_comp;
    float sep_larg;
    float pet_comp;
    float pet_larg;
    char tipo[50];
} Iris;

float calcular_distancia(Iris a, Iris b){
    return sqrt(pow(a.sep_comp - b.sep_comp, 2) +
                pow(a.sep_larg - b.sep_larg, 2) +
                pow(a.pet_comp - b.pet_comp, 2) +
                pow(a.pet_larg - b.pet_larg, 2));
}

void classificar(Iris nao_identificada, Iris registros_identificados[], int n){
    int min_dist = 0;
    float menor_distancia = calcular_distancia(nao_identificada, registros_identificados[0]);
    
    for(int i=1; i<n; i++){
        float distancia = calcular_distancia(nao_identificada, registros_identificados[i]);
        if (distancia < menor_distancia) {
            menor_distancia =  distancia;
            min_dist = i;
        }   
        
    }
    
    printf("%s\n", registros_identificados[min_dist].tipo);
}

int main(){
    
    int n;
    scanf("%d\n", &n);
    
    Iris *iris = (Iris *)malloc(n*sizeof(Iris));
    
    for(int i = 0; i < n; i++){
        scanf("%f %f %f %f", &iris[i].sep_comp, &iris[i].sep_larg, &iris[i].pet_comp, &iris[i].pet_larg);
        scanf("%49[^\n]", iris[i].tipo);
    }
    
    Iris procurar;
    
    scanf("%f %f %f %f", &procurar.sep_comp, &procurar.sep_larg, &procurar.pet_comp, &procurar.pet_larg);
    classificar(procurar, iris, n);
    
    free(iris);
    
    return 0;
}