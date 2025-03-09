/*4. Fa ̧ca um programa que leia uma matriz 4 x 5, determine e mostre atrav ́es de uma fun ̧c ̃ao
o menor elemento dessa matriz.*/
#include <stdio.h>
int main(){

    int mat[4][5], i, j, menor = 100000000;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Digite um numero inteiro: ");
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if(mat[i][j] < menor)
                menor = mat[i][j];
        }
    }

    printf("O menor valor da matriz eh: %d", menor);

    return 0;
}