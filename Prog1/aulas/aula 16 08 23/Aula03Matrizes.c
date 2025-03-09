#include <stdio.h>
#define LIN 4
#define COL 4

int main(){

    int i, j;
    float notas[LIN][COL], media;

    // Leitura aqui
    // imprime linha por linha
    for(i=0; i < LIN; ++i){
        for(j=0; i < COL; ++j){
            printf("%.1f", notas[i][j]);
        }
        printf("\n");
    }    

    return 0;
}