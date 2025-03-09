/*2. Fa ̧ca um programa que leia uma matriz de ordem 3 x 5 e calcule a soma dos elementos de
cada coluna da matriz, armazenando os resultados em um vetor. Depois, o programa deve
exibir o vetor resultante.*/
#include <stdio.h>
#define LIN 3
#define COL 5
int main(){

    int i, j, mat[LIN][COL], somaDasColunas[5] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Digite o numero: ");
            scanf("%d", &mat[i][j]);
            somaDasColunas[j] += mat[i][j]; 
        }
    }

    printf("\nSomas das colunas:\n");
    for (int j = 0; j < 5; j++) {
        printf("Soma da coluna %d: %d\n", j + 1, somaDasColunas[j]);
    }

    return 0;
}