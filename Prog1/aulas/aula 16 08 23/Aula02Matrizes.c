// Ex1. Preenchendo a matriz a partir da entrada padrão
#include <stdio.h>
#define LIN 4
#define COL 4
int main(){

    int i, j;
    float notas[LIN][COL];

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            printf("Entre com a nota [%d %d]: ", i, j);
            scanf("%f", &notas[i][j]);
        }
    }

    // Leitura aqui
    // imprime linha por linha
    for(i=0; i < LIN; ++i){
        for(j=0; i < COL; ++j)
            printf("%.1f", notas[i][j]);
        printf("\n");
    }    


    return 0;
}