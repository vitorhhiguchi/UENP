// 8. Faça uma função que receba um número inteiro qualquer, calcule e mostre todos os seus divisores, bem como a quantidade de divisores existentes.
#include <stdio.h>
int main(){

    int numero;
    void divisores(int num); // Declaração da função

    printf("Digite um numero inteiro: "); // Mostra a mensagem ao o usuário
    scanf("%d", &numero); // Armazena o valor informado

    divisores(numero); // Chamando a função

    return 0;
}

void divisores(int num){  // Função que mostra todos os divisores do número informado
    int i, contador = 0; 

    printf("Divisores do numero %d\n", num);
    for(i = 1; i <= num;i++){
        if (num % i == 0){
            printf("%d \n", i);
            contador++;
        }
    }

    printf("Quantidade de divisores de: %d\n", contador);
}