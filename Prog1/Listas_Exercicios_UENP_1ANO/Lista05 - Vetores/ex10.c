/*10. Fa ̧ca um programa que receba um vetor de 20 elementos e, em seguida, efetue a troca dos
10 primeiros elementos pelos 10  ́ultimos, exibindo ao final o vetor resultante.*/
#include <stdio.h>
#define TAM 20
int main(){

    int temp, i, vet[20];

    for(i=0; i < TAM; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    for(i=0; i < TAM/2; i++){
        temp = vet[i];
        vet[i] = vet[TAM - i - 1];
        vet[TAM - i - 1] = temp;
    }

    printf("Vetor resultante após a troca:\n");
    for(i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}