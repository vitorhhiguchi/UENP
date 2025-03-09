/*Exemplo 2: Somar duas matrizes
Porgrama que lê duas matriz de inteiros e preenche uma terceira com a soma das duas
As matrizes têm dimnesões MxN fornecidos pelo usuário, sendo 1 <= M, N <= 100 */
#include <stdio.h>
#define LIN 2
#define COL 2

int main(){

    int i, j;
    int matrizUm[LIN][COL], matrizDois[LIN][COL], soma[LIN][COL];

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Digite um numero inteiro: \n");
            scanf("%d", &matrizUm[i][j]);
            printf("\n");
        }
    }

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Digite outro numero inteiro: \n");
            scanf("%d", &matrizDois[i][j]);
            printf("\n");
        }
    }

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            soma[i][j] = matrizUm[i][j] + matrizDois[i][j];
            printf("MatrizUm[%d][%d] + MatrizDois[%d][%d] = %d\n", i, j, i, j, soma[i][j]);
            printf("%d + %d = %d\n", matrizUm[i][j], matrizDois[i][j], soma[i][j]); 
        }
    }

    return 0;
}