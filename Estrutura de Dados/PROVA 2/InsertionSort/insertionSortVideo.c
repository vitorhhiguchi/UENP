/* InsertionSort
Perfomance:
-Melhor caso: O(n)
-Médio caso: O(n^2)
-Pior caso: O(n^2)
-Eficiente para conjuntos pequenos de dados
-Estável: não altera a ordem de dados iguais
-Capaz de ordenar dados a medida em que os recebe(tempo real)

O Auxiliary space é O(1)
*/

#include <stdio.h>

void insertionSort(int *vet[], int n){
    int i, j, aux;

    for(i=1; i<n; i++){
        aux = vet[i];
        for(j=i; (j>0) && (aux < vet[j-1]); j--)
            vet[j] = vet[j-1];
        vet[j] = aux;
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

    insertionSort(vetor, quant);

    printf("Imprimindo os valores do vetor apos ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;

}