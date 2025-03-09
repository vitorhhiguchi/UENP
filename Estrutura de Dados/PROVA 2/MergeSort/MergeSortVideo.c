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
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(vet, inicio, meio);  // Dividir a primeira mertade
        mergeSort(vet, meio+1, fim); // Dividir a segunda metade
        merge(vet, inicio, meio, fim); // Juntar tudo para voltar ordenado
    }

}

void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int*) malloc(tamanho*sizeof(int));

    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1){
                    temp[i] = v[p1++];
                }else{
                    temp[i] = v[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            v[k]=temp[j];
    }
    free(temp);
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