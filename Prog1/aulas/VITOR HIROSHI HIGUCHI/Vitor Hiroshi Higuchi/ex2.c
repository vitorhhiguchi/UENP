#include <stdio.h>
#include <stdlib.h>
#define LIN 5
#define COL 5

int main(){

    void somaDasColunas(float mat[][], int linha, int coluna);
    void verificadorDeElemento(float mat[][], int linha, int coluna);
    void calculoMediaAreaCinza(float mat[][], int linha, int coluna);

    int i, j;
    float matriz[LIN][COL];
    int linha = LIN, colun = COL;

    printf("Digite os valores da matriz: \n");
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Digite o valor da matriz[%d][%d]: \n", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    somaDasColunas(matriz, linha, colun);
    verificadorDeElemento(matriz, linha, colun);
    calculoMediaAreaCinza(matriz, linha, colun);

    return 0;
}

void somaDasColunas(float mat[][], int linha, int coluna){
    int i, j;
    float soma[linha] = {0, 0, 0, 0, 0};

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            soma[i] += mat[i][j];
        }
    }

    for(i=0; i<linha; i++){
        printf("A soma da linha[%d]: %.2f", i, soma[i]);
    }
}

void verificadorDeElemento(float mat[][], int linha, int coluna){
    if(mat[linha][coluna]){
        printf("matriz[%d][%d]"); 
    }

}

void calculoMediaAreaCinza(float mat[][], int linha, int coluna){
    float media = 0;
    
    media = mat[0][2] + mat[0][4] + mat[1][0] + mat[1][1] + mat[1][2] + mat[1][3] + mat[1][4] + mat[2][2] + mat[2][4] + mat[3][0] + mat[3][1] + mat[3][2] + mat[3][3] + mat[3][4] + mat[4][2] + mat[4][4];
    media = media / 2;

    printf("A media da area em cinza da matriz eh de: %.2f", media);
}