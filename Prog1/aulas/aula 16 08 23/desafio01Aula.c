#include <stdio.h>
int main(){

    int i, j, LIN, COL;

    printf("Insira o tamanho da Matriz, Digite: ");
    scanf("%d%d", &LIN, &COL);
    int notas[LIN][COL];

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            printf("Entre com a nota [%d %d]: ", i, j);
            scanf("%d", &notas[i][j]);
        }
    }

    for(i=0; i < LIN; i++){
        for(j=0; j < COL; j++){
            notas[i][j] *= 5; 
            printf("%d ", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}