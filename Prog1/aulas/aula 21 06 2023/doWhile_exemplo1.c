#include <stdio.h>
int main(){

    int x, y, count;
    
    printf("Digite 2 numeros: ");
    scanf("%d%d", &x, &y);
    count = x + 1;

    do{
        printf("%d\n", count);
        count++;
    } while (count < y);

    return 0;
}