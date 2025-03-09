#include <stdio.h>
int main(){

    float a, b, c;

    printf("Digite 3 numeros maiores que zero: ");
    scanf("%f%f%f", &a, &b, &c);

    if (a == b && a == c ){

        printf("O triangulo eh equilatero"); 

    }

    else if (a == b && a != c || a == c && a != b || b == c && b != a){
        printf("O triangulo eh isosceles");
    }

    else{

        printf("O triangulo eh escaleno");

    }

    return 0;
}