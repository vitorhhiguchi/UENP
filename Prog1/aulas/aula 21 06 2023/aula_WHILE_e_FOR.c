#include <stdio.h>
int main(){

    int x, y, count;

    printf("Escreva numeros inteiros: ");
    scanf("%d%d", &x, &y);
    count = x+1;

    while (count < y){
        printf("\n%d", count);
        count++;
    }

    return 0;

    





}