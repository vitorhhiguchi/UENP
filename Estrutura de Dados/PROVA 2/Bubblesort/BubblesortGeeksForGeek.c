/* Bubblesort
Perfonamnce:
Melhor caso: n(N)
Pior caso: o(n^2). Pois tem dois for
Não é bom para GRANDEs conjuntos de dados
*/

//Modelo do site que usei para estudar: https://www.geeksforgeeks.org/bubble-sort-algorithm/

#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp){
    int aux = *xp;
    *xp = *yp;
    *yp = aux;
}

void bubbleSort(int *vet, int n){
    int i, j;
    bool swapped;

    for(i=0; i<n-1; i++){
        swapped = false;
        for(j=0; j< n-1; j++){
            if(vet[j] > vet[j+1]){
                swap(&vet[j], &vet[j+1]);
                swapped = true;
            }  
        }
        if(!swapped){
            break;
        } 
    }
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