//Faça um programa que receba como entrada um número inteiro n e exiba o resultado da seguinte soma:
#include <stdio.h>
int main(){

    int i, num;
    float soma, somaTotal = 0;
    // Está recebendo um numero inteiro e armazenando
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    // Está criando um looping para fazer algumas somas com frações
    for(i = 1; i <= num; i++){
        soma += 1 /(float)i;    // poderia ser escrito como "soma = soma + 1/(float)i"
        printf("A soma com o numero %d eh: %.2f\n", i, soma);
        somaTotal = somaTotal + soma; 
    }
    // Está mostrando a soma total dos números fracionários
    printf("A soma total eh de: %.2f\n", somaTotal);

    return 0;
}