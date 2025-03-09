/* 10. Faça um programa leia uma sequência de números inteiros e mostre quantos números 
múltiplos de 7 foram digitados no intervalo entre 10 e 50, bem como a média desses números. O programa deve ser encerrado quando for digitado o valor 0. */
#include <stdio.h>
int main(){

    int num, contador = 0, soma = 0;
    float media;
    // Exibindo na tela a mensagem
    printf("Digite uma sequencia de numeros inteiros(digite 0 para encerrar): \n");
    // Executando o bloco de comandos abaixo sem ter nenhuma condição
    do {
        // Armazenando o número digitado
        scanf("%d", &num);
        // Condições para que seja contado +1 no contador
        if (num >= 10 && num <= 50 && num % 7 == 0) {
            contador++;
            soma += num;
        }
    }while(num);
    // Condição para mostrar se há ou não números multiplos de 7
    if(contador > 0){
        media = (float)soma / contador;
        printf("Quantidade de numeros multiplos de 7 eh de: %d\n", contador);
        printf("Media dos numeros multiplos de 7 eh de: %.2f\n", media);
    }
    else{
        printf("Nenhum numero multiplo de 7 foi digitado!\n");
    }

    return 0;
}