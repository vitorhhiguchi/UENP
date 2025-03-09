//Faça uma função que receba três números inteiros e retorna o maior deles. Reutilize a função abaixo que retorna o maior entre dois números.
#include <stdio.h>

// Função está comparando o maior número entre os 3 digitados.
float maior3(int a, int b, int c){
    // Comparando se o primeiro numero é o maior
    if(a > b && a > c){
        return a;
    }
    // Comparando se o segundo é o maior
    else if (b > a && b > c){
        return b;
    }
    // Retornando o valor do que sobrou
    else{
        return c;
    }
}

int main(){
    
    int num1, num2, num3, comparar;
    // Mostrando na tela a mensagem e armazenando 3 numeros
    printf("Digite 3 numeros inteiros: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    // Chamando a função e armazenando
    comparar = maior3(num1, num2, num3);
    // Mostrando na tela o resultado da função
    printf("O maior numero entre os 3 digitados eh o: %d", comparar);

    return 0;
}