#include <stdio.h>
int main(){

    int fat, n, i;

    printf("Digite um numero: ");
    scanf("%d", &n);

    fat = 1;
    for (i = n; i > 1; i--){
        fat *= i;
    }

    printf("Fatorial de %d! = %d \n", n, fat);

    return 0;
}