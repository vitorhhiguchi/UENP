//Faca um programa que receba dois números inteiros representando o intervalo (inicio) e (fim) de uma sequência, e depois imprima todos os numeros ımpares dentro deste intervalo.
#include <stdio.h>
int main(){

    int x, y;

    // Pede para o usuário digitar 2 numeros e está armazenando eles.
    printf("Escreva dois numeros inteiros: ");
    scanf("%d%d", &x, &y);

    // Aqui é um looping que está comparando se x é menor que y, e então o looping vai acontecer até que x seja maior ou igual a y.
    // Enquanto o looping roda, ele vai printar os números ímpares.
    while(x < y){
        if(x % 2 == 1){
            printf("%d\n", x);
        }
        x++;
    }

    return 0;
}