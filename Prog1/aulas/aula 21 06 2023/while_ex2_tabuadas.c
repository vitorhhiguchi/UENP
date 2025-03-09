//Usando o comando while, faça um programa que gere a tabuada de um número "n" fornecido pelo usuário
#include <stdio.h>
int main(){

    int numero;
    int tabuada = 0;

    printf("Escreva um numero inteiro para criar a tabuada dela: ");
    scanf("%d", &numero);
    
    while (tabuada < 11){
        printf("%d x %d = %d \n", numero, tabuada, (numero * tabuada));
        tabuada++;
    }

    return 0;
}