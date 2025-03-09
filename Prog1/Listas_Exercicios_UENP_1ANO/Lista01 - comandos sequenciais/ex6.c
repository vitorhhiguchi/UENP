#include <stdio.h>
int main(){

    float x, y, temporario;

    printf("Escreva um valor qualquer para x: ");
    scanf("%f", &x);

    printf("Escreva outro valor para y: ");
    scanf("%f", &y);

    temporario = x;
    x = y;
    y = temporario;

    printf("O valor de x e de: %.f \n", x);
    printf("O valor de y e de: %.f \n", y);

    return 0;
}


/*Nesse algoritmo eu tive que criar 3 variáveis, pois quando eu colocar tanto o valor de x ou de y neles, os dois ficariam com o mesmo valor.
Por isso que eu criei a variavel temporaria, para ela armazenar os dados de x ou y. Para conseguir ter o valor real dado a cada um, antes de armazenar o valor entre eles.*/