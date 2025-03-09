//Faça um programa que determine e mostre os 50 primeiros números múltiplos de 3 considerando números maiores que 0.
#include <stdio.h>
int main(){

    int contador = 0, num = 1;
    // Está mostrando na tela essa frase abaixo
    printf("Os primeiros 50 numeros multiplos de 3 sao: \n");
    // O looping vai funcionar até quando a comparação for TRUE, depois ele acaba
    while (contador < 50){
        // A condição está printando todos os números que são múltiplos de 3, caso n entre na condição ela incrementa 1 na variável "num"
        if (num % 3 == 0){
            printf("%d ", num);
            contador++;
        }
        num++;
    }

    return 0;
}