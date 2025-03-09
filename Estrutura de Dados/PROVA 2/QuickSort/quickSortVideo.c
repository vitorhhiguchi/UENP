/* QuickSort
Performance:
- Melhor caso: O(n log n)
- Medio caso: O(n log n)
- Pior caso(Muito raro de acontecer): O(N^2)
- Não é estavel, pois tem problema com valores iguais
- Vantagens:
- Desvantagem: Como escolher o pivô?
- Para evitar o pior caso, é comum usar a estratégia de escolher o pivo de forma aleatoria, ou uso da mediana de três(escolhendo
o pivo como a mediana de tres elementos da array).

-Auxiliary space: O(1) se não considerar a pilha recursiva.
*/

void quickSort(int *vet[], int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pivo-1);
        quickSort(vet, pivo+1, fim);
    }
}

int particiona(int *vet[], int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = vet[inicio];

    while(esq < dir){
        while(vet[esq] <= pivo)
            esq++;
        while(vet[dir] > pivo)
            dir--;
        if(esq < dir) {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }

    vet[inicio] = vet[dir];
    vet[dir] = pivo;

    return dir;
}

int main(){
    int quant = 7;
    //int vetor[10] = {10, 2, 3, 5, 6, 1, 4, 7, 9, 8};
    int vetor[7] = {5, 2, 8, 12, 4, 7, 9};

    printf("Imprimindo os valores do vetor antes de ser ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    quickSort(vetor, 0, quant-1);

    printf("Imprimindo os valores do vetor apos ordenado: \n");
    for(int i=0; i<quant; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}