/* SelectionSort
Performance:
- Melhor caso: O(n^2)
- Caso méedio: O(n^2)
- Pior caso: O(n^2)
- Ineficiente para grandes conjuntos de dados
- Estável: não altera a ordem de dados iguais

Auxiliary space: O(1)
*/

#include <stdio.h>

void selectionSort(int *vet[], int n){
    int i, j, menor, troca;

    for(i=0; i<n-1; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(vet[j] < vet[menor])
                menor = j;
        }
        if(i != menor){
            troca = vet[i];
            vet[i] = vet[menor];
            vet[menor] = troca;
        }
    }

}

int main(){
    int quant = 7;
    //int vetor[10] = {10, 2, 3, 5, 6, 1, 4, 7, 9, 8};
    int vetor[7] = {5, 2, 8, 12, 4, 7, 9};

    printf("Imprimindo os valores do vetor antes de ser ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    selectionSort(vetor, quant);

    printf("Imprimindo os valores do vetor apos ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}