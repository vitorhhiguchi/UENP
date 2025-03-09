/*7. Fa ̧ca um programa que receba do usu ́ario um vetor de “n” n ́umeros inteiros, em seguida,
implemente uma fun ̧c ̃ao que determine e retorne o maior valor do vetor lido.*/
#include <stdio.h>
int main(){

    int maiorValorLido(int vetor[], int quantidade, int maiorN);
    int quant, i, maior=0;

    printf("Digite a quantidade de numeros que sera introduzido no vetor: ");
    scanf("%d", &quant);

    int vet[quant];

    for(i=0; i < quant; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &vet[i]);
    }

    maior = maiorValorLido(vet, quant, maior);

    printf("O maior numero lido foi: %d", maior);

    return 0;
}

int maiorValorLido(int vetor[], int quantidade, int maiorN){
    int i;

    for(i=0; i < quantidade; i++){
        if(vetor[i] > maiorN){
            maiorN = vetor[i];
        }
    }

    return maiorN;

}