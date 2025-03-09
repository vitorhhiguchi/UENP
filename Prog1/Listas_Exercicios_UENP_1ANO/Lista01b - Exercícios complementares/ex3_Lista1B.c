#include <stdio.h>
#include <math.h>
int main(){

    float massa, altura, IMC; 

    printf("Escreva sua altura e peso: ");
    scanf("%f%f", &altura, &massa);

    IMC = massa / (pow(altura, 2));

    printf("O IMC da pessoa com as informacoes dada e de: %.2f", IMC);

    return 0;
}

//basicamente o codigo esta lendo sua altura e peso, e então calcula o IMC.