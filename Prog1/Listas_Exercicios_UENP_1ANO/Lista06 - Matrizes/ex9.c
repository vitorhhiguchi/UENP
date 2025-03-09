/*9. Fa ̧ca um programa que receba as dimens ̃oes e os elementos de uma matriz, gere e exiba a
sua transposta.*/
#include <stdio.h>

int main() {
    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];
    int transposta[colunas][linhas];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
            transposta[j][i] = matriz[i][j]; 
        }
    }

    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}