/*Impremente um programa que armazene dados inteiros em uma matriz de ordem 4 e imprima: Todos os elementos que se encontram
em posições cuja linha mais coluna forma um número par*/
#include <stdio.h>
#define LIN 4
#define COL 4
int main(){

    int i, j;
    int matriz[LIN][COL];

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            printf("Digite um numero inteiro: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            if((i + j) % 2 == 0){
                printf("matriz[%d][%d] = %d", i, j, matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}