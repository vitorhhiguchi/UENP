/*Faca um programa que receba 2 números inteiros quaisquer representados por x e y e 
mostre, em ordem crescente, todos os números entre x e y cujo resto da divisão deles por 5 for igual a 2 ou igual a 3. */
#include <stdio.h>
int main(){

    int x, y;

    // Recebendo de entrada dois números
    printf("Digite dois numeros inteiros: ");
    scanf("%d%d", &x, &y);

    // Condição para entrar no looping, para sempre os prints serem em ORDEM CRESCENTE entre x e y.
    if(x < y){
        while(x < y){
            if(x % 5 == 2 || x % 5 == 3){
                printf("%d\n", x);
            }
            x++;
        }
    }
    else{
        while(y < x){
            if(y % 5 == 2 || y % 5 == 3){
                printf("%d\n", y);
            }
            y++;
        }
    }

    return 0;
}