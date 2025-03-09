/*3. Faça um programa que leia 50 números inteiros e armazene em um vetor. Em seguida,
armazene os números pares no vetor chamado par e os números ímpares no vetor ímpar.
Imprima os dois vetores resultante.*/
#include <stdio.h>
#define TAM 50
int main(){
    
    int i, numeros[TAM], ehPar = 0, ehImpar = 0;

    for(i=0; i < TAM; i++){
        printf("Digite um numero inteiro:\n");
        scanf("%d", &numeros[i]);
        
        if(numeros[i] % 2 == 0){
            ehPar++;
        }
        else{
            ehImpar++;
        }
    }


    int pares[ehPar];
    int impares[ehImpar];
    int indicePar = 0, indiceImpar = 0;
    
    for(i=0; i < TAM; i++){
        if(numeros[i] % 2 == 0){
            pares[indicePar] = numeros[i];
            indicePar++;
        }
        else{
            impares[indiceImpar] = numeros[i];
            indiceImpar++;
        }
    } 

    for(i=0; i < ehPar; i++){
        printf("Os numeros pares sao: %d\n", pares[i]);
    }
    for(i=0; i < ehImpar; i++){
        printf("Os numeros impares sao: %d\n", impares[i]);
    }

    return 0;
}