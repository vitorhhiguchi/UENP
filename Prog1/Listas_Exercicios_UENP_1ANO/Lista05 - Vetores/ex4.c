/*4. Faça um programa que leia uma sequência de 21 números inteiros e armazene em um vetor.
Depois, determine se o último número lido está presente nos 20 primeiros e mostre as
posições do vetor em que ele se encontra. */
#include <stdio.h>
#define TAM 21
int main(){

    int i, numeros[TAM];

    for(i=0; i < TAM; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &numeros[i]);
    }

    for(i=0; i < TAM-1; i++){
        if(numeros[TAM-1] == numeros[i]){
            printf("O numero na posicao[%d] eh igual ao ultimo digitado!\n", i);
        }
    }

    return 0;
}