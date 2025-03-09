#include <stdio.h>
int main(){

    int x, y, n;
    
    printf("Digite 2 numeros: ");
    scanf("%d%d", &x, &y);

    for (n = x+1; n < y; n++){
        printf("%d\n", n);
    }

    return 0;
}