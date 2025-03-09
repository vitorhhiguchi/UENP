/*5. Faça um programa em leia uma sequência de números e armazene em um vetor. Em
seguida, determine e mostre quantos números lidos estão dentro do intervalo entre 10 e 50.
O programa deve ser encerrado quando for lido o número -1. */
#include <stdio.h>
#define TAM 100000
int main(){

    int numeros[TAM], i=0, dentroIntervalo=0, continuar = 1;
    
    //Nesse loop, o while só acaba, caso, exceder o tamanho do vetor e caso for digitado -1, e a variável "continuar"
    // virar False.
    while (continuar && i < TAM){
        // Pede para o usuário digitar um numero e armazena ele
        printf("Digite um numero inteiro: \n");
        scanf("%d", &numeros[i]);
    
        // Faz uma condição, para saber se o número digitado está entre o intervalo entre 10 e 50
        if(numeros[i] > 10 && numeros[i] < 50){
            dentroIntervalo++; // Caso esteja, contamos 1 para o contador
        }
        // Condição para saber se o usuário digitou -1.
        if(numeros[i] == -1){
            // Definindo o valor da variável "continuar" como False
            continuar = 0;
        }
        // Incremento da variável contador
        i++;

    }
    // Mostrando para o usuário a quantidade de números digitados que estão dentro do intervalo
    printf("A quantidade de numeros entre 10 e 50 eh de: %d", dentroIntervalo);

    return 0;
}