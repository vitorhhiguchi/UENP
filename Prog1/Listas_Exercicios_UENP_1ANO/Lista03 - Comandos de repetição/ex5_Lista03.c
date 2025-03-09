// 5. Faça um programa que receba uma quantidade de números inteiros, em seguida calcule e mostre a sua média. A quantidade de números deve ser fornecida pelo usuário.
#include <stdio.h>
int main(){

    int quant, num, i, soma = 0;
    float media;

    // Está mostrando na tela a mensagem abaixo, e armazenando o número fornecido.
    printf("Digite a quantidade de numeros que o usuario vai fornecer: \n");
    scanf("%d", &quant);

    // Está criando um looping até o "i" atingir o numero digitado no último scanf
    for(i = 1; i <= quant; i++){
        // Armazenando os numeros que irá ser calculado a media
        printf("Digite o numero %d: \n", i);
        scanf("%d", &num);
        // Somando os numeros digitados com eles mesmos
        soma += num;
    }
    // Calculando a média dos numeros dados
    media = soma / quant;
    
    // Mostrando para o usuário a média calculada
    printf("A media com a quantidade %d de numeros inteiros eh de: %.2f\n", quant, media); 

    return 0;
}