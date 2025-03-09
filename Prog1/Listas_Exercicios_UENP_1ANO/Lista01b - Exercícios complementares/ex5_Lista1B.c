#include <stdio.h>
int main(){

    int a, b, c, d, conta;

    printf("Escreva 4 valores de numeros inteiros: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    conta = (a * b) - (c * d);

    printf("A diferença do produto de A e B pelo produto de C e D eh de: %.2d \n", conta);

    return 0;
}

// o codigo esta lendo 4 numeros inteiros e calculando o produto com a diferença de outro produto