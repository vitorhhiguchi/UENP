#include <stdio.h>
int main(){

    float base, altura, area;

    printf("Escreva o valor de uma base e altura: ");
    scanf("%f%f", &base, &altura);

    area = base * altura / 2;

    printf("A area de um triangulo esses valores e de: %.2f", area);

    return 0;
}

//O programa esta lendo a altura e a base de um triangulo e calcula a area.