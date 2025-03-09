#include <stdio.h>

void insertionSort(int *vet[], int n){
    int i, j, aux;
    
    for(i=1; i<n; i++){
        aux = vet[i];
        for(j=i; (j > 0) && vet[j] > vet[j - 1]; j--)
            vet[j] = j[j-1];
        vet[j-1] = aux;
        
    }
}