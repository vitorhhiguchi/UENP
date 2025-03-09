/*10. Fa ̧ca um programa que leia uma matriz 3 X 7 com valores inteiros, calcule e mostre quantos
elementos dessa matriz est ̃ao no intervalo entre 10 e 50, desconsiderando os extremos. Em
seguida, gere uma segunda matriz com os elementos diferentes de 10 e 50, completando a
matriz com zero no lugar desses n ́umeros.*/
#include <stdio.h>

int main() {
    int matriz[3][7];
    int contadorIntervalo = 0;

    printf("Digite os elementos da matriz 3x7:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > 10 && matriz[i][j] < 50) {
                contadorIntervalo++;
            }
        }
    }

    printf("\nQuantidade de elementos no intervalo (10, 50): %d\n", contadorIntervalo);

    int segundaMatriz[3][7];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (matriz[i][j] != 10 && matriz[i][j] != 50) {
                segundaMatriz[i][j] = matriz[i][j];
            } else {
                segundaMatriz[i][j] = 0;
            }
        }
    }

    printf("\nSegunda matriz com zeros no lugar de 10 e 50:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", segundaMatriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}