/*5. Fa ̧ca um programa que leia uma matriz de ordem 5 x 5, calcule e mostre a m ́edia dos
elementos da diagonal principal.*/
#include <stdio.h>
int main(){

    int i, j, mat[5][5], elementosDiagonal = 0;
    float somaDiagonal = 0.0, mediaDiagonal;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Digite um numero inteiro: ");
            scanf("%d", &mat[i][j]);
            if (i == j) {
                somaDiagonal += mat[i][j]; 
                elementosDiagonal++;
            }
        }
    }

    if (elementosDiagonal > 0) {
        mediaDiagonal = somaDiagonal / elementosDiagonal;

        // Mostra a média dos elementos da diagonal principal
        printf("\nMedia dos elementos da diagonal principal: %.2f\n", mediaDiagonal);
    } else {
        printf("\nNao ha elementos na diagonal principal.\n");
    }

    return 0;



}