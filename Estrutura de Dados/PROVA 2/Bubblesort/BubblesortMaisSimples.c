/* Bubblesort
Perfonamnce:
Melhor caso: n(N)
Pior caso: o(n^2). Pois tem dois for
Não é bom para GRANDEs conjuntos de dados
*/
#include <stdio.h>

void bubbleSort(int *vet, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){

    //int vetor[10] = {10, 2, 3, 5, 6, 1, 4, 7, 9, 8};
    int vetor[10] = {9, 9, 2, 5, 6, 10, 7, 8, 4, 3};

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