#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIN 3
#define COL 3

void printMatriz(int matriz[LIN][COL]){
    for(int i = 0; i<LIN; i++){
        for(int j=0; j<COL; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int matriz[LIN][COL];

    srand(time(NULL));

    for(int i = 0; i<LIN; i++){
        for(int j=0; j<COL; j++){
            matriz[i][j] = rand() % 9;
        }
    }

    printMatriz(matriz);

    


    return 0;
}