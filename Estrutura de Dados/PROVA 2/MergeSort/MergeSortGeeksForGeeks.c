/* MergeSort
Perfomance:
- Melhor caso: O(n log n)
- Medio caso: O(n log n)
- Pior caso: O(n log n)
- Estável: Não altera a ordem de dados iguais
- Desvantagens: recursividade e usa um vetor auxiliar durante a ordenação

- Space Complexity: O(n), espaço necessário quando é criado uma array temporaria durante o merge
*/

#include <stdio.h>

void mergeSort(int *vet[], int inicio, int fim){
    if(inicio<fim){
        int meio =  inicio + (fim-1) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio+1, fim);

        merge(vet, inicio, meio, fim);
    }

}

void merge(int *vet[], int inicio, int meio, int fim){
    int i, j, k;
    // tamanhos das duas metades
    int parte1 = meio - inicio + 1;
    int parte2 = fim - meio;

    //Arrays temporarias
    int esquerda[parte1], direita[parte2];

    for(i=0; i < parte1; i++)
        esquerda[i] = vet[inicio + i];
    for(j=0; j < parte2; j++)
        direita[j] = vet[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    // Esse while é para juntar as duas maiores partes ordenando-as
    while(i < parte1 && j < parte2){
        if(esquerda[i] <= direita[j]){
            vet[k] = esquerda[i];
            i++;
        }
        else {
            vet[k] = direita[j];
            j++;
        }
        k++;
    }

    while(i < parte1){
        vet[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < parte2){
        vet[k] = direita[j];
        j++;
        k++;
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

    mergeSort(vetor, 0, quant-1);

    printf("Imprimindo os valores do vetor apos ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}