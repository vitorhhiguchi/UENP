#include <stdio.h>
#include <math.h>
int main(){

    float a, b, c, formA, formB, formC, formD;

    printf("Escreva 3 valores para serem calculados: ");
    scanf("%f%f%f", &a, &b, &c);
    
    formA = (a * b) / c;
    formB = pow(a,2) + b + 5*c;
    formC = (a * b * c) + b + (c/3) * 5 -1;
    formD = pow(a * b * c, 3) / 2;

    printf("O valor conseguido com a formula A foi de: %.2f \n", formA);
    printf("O valor conseguido com a formula B foi de: %.2f \n", formB);
    printf("O valor conseguido com a formula C foi de: %.2f \n", formC);
    printf("O valor conseguido com a formula D foi de: %.2f \n", formD);

    return 0;
}
//Basicamente o algoritmo esta lendo 4 numeros e dps aplicando em 4 formulas diferentes e mostram o resultado.