#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Funcao para misturar o vetor
void mistureVetor(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((rand() / (double)RAND_MAX) < 0.5)
        {
            int j = (int)((n - 1) * (rand() / (double)RAND_MAX));
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

// I mpl em en ta ca o do Bubble Sort
void bubbleSort(int *vet, int tam, int *iteracoes){
    int trocado;
    *iteracoes = 0;
    for(int i=0; i<tam-i-1; i++){
        trocado = 0;
        for(int j=0; j<tam-1; j++){
            (*iteracoes)++;
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                trocado = 1;
            }
        }
        if(!trocado){
            break;
        }
    }
}

int main(){
    int tamanhos[] = {5000, 10000, 15000, 20000, 25000, 30000,
                      35000, 40000, 45000, 50000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    // Abrir arquivo para armazenar os resultados
    FILE * fp_selection = fopen("BubbleSortIteracoesCasoMedio.txt" ,"w");
    srand ( time (0) ) ; // Iniciar os numeros aleatorios
    // Loop pelos tamanhos de vetor
    for ( int i = 0; i < num_tamanhos ; i ++) {
            int tam = tamanhos[i];
            int *arr = (int *)malloc(tam * sizeof(int));
            // Preencher o array com valores crescentes
            for (int j = 0; j < tam; j++)
            {
                arr[j] = j;
            }
            // Executar 30 repeticoes para obter o caso medio
            for (int j = 0; j < 30; j++)
            {
                mistureVetor(arr, tam);
                int iteracoes;
                // Selection Sort
                bubbleSort(arr, tam, &iteracoes);
                fprintf(fp_selection, "%d ", iteracoes);
            }
            fprintf(fp_selection, "\n");
            free(arr); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose ( fp_selection );
    return 0;
}