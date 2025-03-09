/*1. Faça um programa que leia uma sequência de números qualquer e armazene em um vetor,
em seguida, implemente uma função que contabilize e retorne o total de ocorrências do
último número lido desta sequência.*/
#include <stdio.h>
int main(){

    float quantDeRepeticoesUltNum(int vet[], int tam); // Declrando a função
    int tam, i;
    float repeticoes;

    printf("Digite a quantidade de numero que vai ser digitado: \n");
    scanf("%d", &tam);

    float numerosDigitados[tam];

    for(i=0; i<tam; i++){
        printf("Digite um numero qualquer: \n");
        scanf("%f", &numerosDigitados[i]);
    }

    repeticoes = quantDeRepeticoesUltNum(numerosDigitados, tam);

    printf("A quantidade de numeros iguais o ultimo digitado %.2f eh de: %.2f", numerosDigitados[tam-1], repeticoes);

    return 0;
}

float quantDeRepeticoesUltNum(int vet[], int tam){
    int i, count = 0;

    for(i=0; i<tam-1; i++){
        if(vet[tam-1] == vet[i]){
            count ++; 
        }
    }

    return count;
}