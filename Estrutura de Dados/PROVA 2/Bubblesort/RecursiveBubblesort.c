/* O Bubblesort recursivo ele é tempo de complexidade O(n^2)
O tempo auxiliar passa a ser O(n)     
*/

#include <stdio.h>

void swap(int *xp, int *xy){
    int aux = *xp;
    *xp = *xy;
    *xy = aux;
}

void bubbleSort(int vet[], int n){
    // Aqui ele confere primeiramente se há apenas um elemento na array.
    // Também é a condição de parada da borbulha(do sorting).
    if(n==1){  
        return;
    }
    int count = 0;

    // Passagem do BubbleSort: borbulha o maior elemento até o final.
    for(int i=0; i<n-1; i++){
        if(vet[i] > vet[i+1]){
            swap(&vet[i], &vet[i+1]);
            count++;
        }
    }

    //Se não houve troca na passagem, o array está ordenado, retorna
    if(count==0)
        return;
    
    // Chamada recursiva para o array de tamanho n-1
    bubbleSort(vet, n-1);
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