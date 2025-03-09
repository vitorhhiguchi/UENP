/*6. Fa ̧ca um programa que leia uma matriz quadrada com dimens ̃ao definida pelo usu ́ario. Em
seguida, implemente uma fun ̧c ̃ao que calcule e mostre a soma dos elementos que est ̃ao acima
da diagonal principal.*/
#include <stdio.h>

int somaAcimaDiagonal(int matriz[][100], int dimensao) {
    int soma = 0;

    for (int i = 0; i < dimensao; i++) {
        for (int j = i + 1; j < dimensao; j++) {
            soma += matriz[i][j];
        }
    }

    return soma;
}

int main() {
    int dimensao;

    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &dimensao);

    if (dimensao <= 0 || dimensao > 100) {
        printf("Dimensao invalida.\n");
        return 1; 
    }

    int matriz[100][100];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = somaAcimaDiagonal(matriz, dimensao);

    printf("\nSoma dos elementos acima da diagonal principal: %d\n", soma);

    return 0;
}