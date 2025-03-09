/*9. Fa ̧ca um programa que receba do usu ́ario um vetor de “n” n ́umeros reais e ordene-os em
ordem crescente. Ao final, o programa deve mostrar o vetor ordenado.*/
#include <stdio.h>
int main(){

    void ordenar(float arr[], int n);
    int quant, i;

    printf("Digite a quantidade de numeros que serao inseridos: ");
    scanf("%d", &quant);

    int vet[quant];

    for(i=0; i < quant; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &vet[i]);
    }

    ordenar(vet, quant);

    printf("Vetor ordenado: ");
    for(i=0; i < quant; i++){
        printf("%d", vet[i]);
    }

    printf("\n");

    return 0;
}

void ordenar(float arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}