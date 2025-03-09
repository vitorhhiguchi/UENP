#include <stdio.h>
#include <math.h>
int main(){

    float x, y, a, b, distancia;

    printf("Escreva as coordenadas de um ponto: ");
    scanf("%f", &x);
    scanf("%f", &y);

    printf("Escreva outras coordenadas de um ponto: ");
    scanf("%f", &a);
    scanf("%f", &b);

    distancia = sqrt( pow((x - a), 2) + pow((y - b), 2));     

    printf("A distancia entre esses dois pontos e de: %.2f", distancia);

    return 0;
}

/*O álgoritmo está lendo coordenadas de dois pontos, e depois ele calcula a distância entre eles.*/