//2. Faça um programa que receba do usuário um vetor de “n” números inteiros e, em seguida, imprima o vetor na ordem inversa.
#include <stdio.h>
int main(){

    int quantDeNumeros, i;

    printf("Digite a quantidade de numeros que voce quer digitar: \n");
    scanf("%d", &quantDeNumeros);

    int lerNumeros[quantDeNumeros];

    for(i=0; i < quantDeNumeros; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &lerNumeros[i]);
    }

    for(i=quantDeNumeros-1; i >= 0; i--){
        printf("Vetor[%d] = %d\n", i, lerNumeros[i]);
    }

    return 0;
}