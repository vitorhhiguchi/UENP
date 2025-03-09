#include <stdio.h>
int main(){

    int n, contador, i;
    float soma=0;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &n);

    contador = n;

    for(i=1; i <= contador; i++){
        soma += (float)i / n;
        printf("%.2f\n", soma);
        n = n - i;
    }

    printf("Resultado da soma: %.2f\n", soma);

    return 0;
}