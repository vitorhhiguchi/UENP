/*Faça uma função que receba o raio de um círculo e retorne a sua área. A área do círculo é dada por PI ∗ r^2.
Dica: use a biblioteca math.h, com a função pow(). */
#include <stdio.h>
#include <math.h>
#define pi 3.14

float areaDoCirculo (float r){
    float area = pi * pow(r,2);
    
    return area;
}

int main(){

    float area, raio;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    area = areaDoCirculo(raio);

    printf("A area do circulo eh de: %.2f", area);

    return 0;
}