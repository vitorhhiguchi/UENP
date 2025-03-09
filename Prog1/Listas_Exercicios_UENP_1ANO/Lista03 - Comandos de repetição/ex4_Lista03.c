// 4. Faça um programa que calcule e exiba o valor de S, em que S  ́e dado por:
#include <stdio.h>
int main(){

    float S = 0;
    int i, numerador = 1;

    // Criando um looping para ser repetido 50 vezes
    for(i = 1; i <= 50; i++){
        // Fazendo a soma de frações determinada pelo exercício
        S += (float)numerador / (float)i;
        numerador += 2;
    }

    // Mostrando na tela o resultado
    printf("O valor de S eh: %.2f\n", S);

    return 0;
}