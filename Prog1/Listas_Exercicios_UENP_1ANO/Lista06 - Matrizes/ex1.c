/*1. Fa ̧ca um programa que leia uma matriz de ordem 5 x 3, calcule e mostre a soma de cada
linha da matriz.*/
#include <stdio.h>
#define LIN 5
#define COL 3
int main(){

    int mat[LIN][COL], i, j, soma[5] = {0};

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            printf("Digite um numero inteiro: ");
            scanf("%d", &mat[i][j]);
            soma[i] += mat[i][j];
        }
    }

    printf("\nMatriz lida:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
    }

    printf("\nSomas das linhas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Soma da linha %d: %d\n", i + 1, soma[i]);
    }

    return 0;
}