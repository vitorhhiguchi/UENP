/* Bubblesort
Perfonamnce:
Melhor caso: n(N)
Pior caso: o(n^2). Pois tem dois for
Não é bom para GRANDEs conjuntos de dados

O espaço auxiliar na memoria é O(1)
*/
#include <stdio.h>

void bubbleSort(int *vet, int N){
    int i, continuar, aux, fim = N;

    do{
        continuar = 0;
        for(i=0; i<fim-1; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                continuar = i;
            }
        }
        fim--;
    }while(continuar != 0);
}

int main(){

    int vetor[10] = {10, 2, 3, 5, 6, 1, 4, 7, 9, 8};

    printf("Imprimindo os valores do vetor antes de ser ordenado: \n");
    for(int i=0; i<10; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    bubbleSort(vetor, 10);

    printf("Imprimindo os valores do vetor apos ordenado: \n");
    for(int i=0; i<10; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}