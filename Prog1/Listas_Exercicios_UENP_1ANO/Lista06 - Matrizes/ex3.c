/*3. Fa ̧ca um programa que receba uma matriz de inteiros de ordem 5 x 3 e verifique quais os
elementos da matriz s ̃ao m ́ultiplos de 3, armazenando esses elementos em um vetor. Depois,
o programa deve exibir o vetor resultante.*/
#include <stdio.h>
#define LIN 5
#define COL 3
int main(){

    int mat[LIN][COL], vet[15], i, j, contador=0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite um numero inteiro: ");
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if(mat[i][j] % 3 ==0){
                vet[contador] = mat[i][j];
                contador++;
            }
        }
    }

    printf("Os numeros multiplos de 3 sao: ");
    for(i=0; i < 15; i++){
        printf("%d\n", vet[i]);
    }

    return 0;
}