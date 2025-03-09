#include <stdio.h>
#include <math.h>
int main(){

    float a, b, c, x1, x2, delta;

    printf("Digite os valores da equacao de segundo grau: ");
    scanf("%f%f%f", &a, &b, &c);

    delta = (pow(b,2) - (4 * a * c));

    if (a == 0){

        printf("Nao eh uma equacao de segundo grau");

    }
    
    else if (delta < 0){

        printf("A equacao nao possui raizes reais.");

    }

    else if (delta == 0){

        x1 = ( -b + sqrt(delta)) / (2 * a);
        x2 = ( -b - sqrt(delta)) / (2 * a);

        printf("A equacao possui apenas uma raiz real.\n");
        printf("A raiz da equacao eh %.2f\n", x1);

    }

    else{

        x1 = ( -b + sqrt(delta)) / (2 * a);
        x2 = ( -b - sqrt(delta)) / (2 * a);

        printf("A equacao possuvei duas raizes reais\n");
        printf("As raizes da equacao eh %.2f  e %.2f\n", x1, x2);

    }

    return 0;
}