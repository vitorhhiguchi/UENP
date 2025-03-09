//Faça um programa que leia um número e verifique se ele é primo ou não.
#include <stdio.h>
int main(){

    int num, i, ehPrimo = 1;

    // Armazenando um número
    printf("Digite um numero: ");
    scanf("%d", &num);
    // Comparando se o numero é menor que 1, pois se for, ele não é primo
    if (num < 1){
        ehPrimo = 0;
    }
    // Quando acontece a primeira condição de primo, cai nesse
    else{
        // Cria um loop para ver se o numero é divisel por outros números, se ele for a váriavel agora vale 0 ou false
        for(i = 2; i < num; i++){
            if(num % i == 0){
                ehPrimo = 0;
                break;
            }
        }
    }
    // Se o numero não for 0, então ele é primo, caso ele for ele é primo!
    if(ehPrimo){
        printf("%d eh um numero primo. \n", num);
    }
    else{
        printf("%d nao eh um numero primo. \n", num);
    }

    return 0;
}