//Faça um programa para calcular e gerar a tabuada dos números 1 ao 10.
#include <stdio.h>
int main(){

    int i, j;
    // Looping vai repetir até a variável i ser <= 10
    for (i = 1; i <= 10; i++){
        printf("Tabuada do %d:\n", i);
        // esse outro looping cria a tabuada
        for(j = 1; j<= 10; j++){
            printf("%d x %d = %d\n", i, j, i * j);
        }
        // aqui só ta dando um espaço entre as tabuadas
        printf("\n");  
    }

    return 0;
}