#include <stdio.h>
int main(){

    float x, y;

    printf("Digite as coordenadas de um ponto em um plano cartesiano ");
    scanf("%f%f", &x, &y);

    if (x > 0 && y > 0){
        printf("O ponto (%.2f, %.2f) esta no PRIMEIRO quadrante.\n", x, y);
    }
    
    else if (x < 0 && y > 0){
        printf("O ponto (%.2f, %.2f) esta no SEGUNDO quadrante.\n", x, y);
    }

    else if (x < 0 && y < 0){
        printf("O ponto (%.2f, %.2f) esta no TERCEIRO quadrante.\n", x, y);
    }
    
    else if (x > 0 && y < 0){
        printf("O ponto (%.2f, %.2f) esta no QUARTO quadrante.\n", x, y);
    }

    else if (x > 0 && y == 0 || x < 0 && y == 0){
        printf("O ponto (%.2f, %.2f) esta no eixo X.\n", x, y);
    }

    else if (x == 0 && y > 0 || x == 0 && y < 0){
        printf("O ponto (%.2f, %.2f) esta no eixo Y.\n", x, y);
    }

    else if (x == 0 && y == 0){
        printf("O ponto (%.2f, %.2f) esta na ORIGEM.\n", x, y);
    }

    return 0;
}