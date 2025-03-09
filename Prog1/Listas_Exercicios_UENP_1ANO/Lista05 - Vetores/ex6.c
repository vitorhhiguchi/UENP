/*6. Faça um programa que leia uma sequência de números inteiros e armazene em um vetor.
Em seguida, implemente uma função que determine e mostre os números do vetor que são
múltiplos de 7.*/
#include <stdio.h>
int main(){

    void multDeSete(int vet[], int quant);
    int quant, i;

    printf("Digite a quantidade de numeros que vai ser introduzido: ");
    scanf("%d", &quant);

    int vet[quant];

    for(i=0; i < quant; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &vet[i]);
    }

    multDeSete(vet, quant);

    return 0; 
}

void multDeSete(int vet[], int quant){
    int i;

    for(i=0; i < quant; i++){
        if(vet[i] % 7 == 0){
            printf("%d eh multiplo de 7!\n", vet[i]);
        }
    }

}