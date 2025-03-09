//2. Faça uma função que receba como parâmetro um número inteiro e verifique se este é primo ou não.
#include <stdio.h>

int main(){
    int numero;
    void ehPrimo(int num); // Declaração de função 

    printf("Digite um numero inteiro: "); // Mostra a mensagem na tela
    scanf("%d", &numero); // Armazenando o dado na variavel

    ehPrimo(numero); // chamando a função

    return 0;
}

void ehPrimo(int num){  // função para comparar se o numero é primo ou não
    int i, primo = 1;
    if(num < 1){  // Condições para ver se o numero é primo
        primo = 0;
    }
    else{
        for(i = 2; i < num; i++){  // Vendo se o numero é primo
            if(num % i == 0){
                primo = 0;
                break;
            }
        }
    }
    // terminando de comparar, para mostrar na tela se o número digitado era primo ou não   
    if (primo){
        printf("O numero %d eh primo!", num);
    }
    else{
        printf("O numero %d nao eh primo!", num);
    }
}