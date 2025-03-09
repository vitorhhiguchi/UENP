#include <stdio.h>
int main(){

    int x, y, z;

    printf("Digite 3 numeros inteiros: ");
    scanf("%d%d%d", &x, &y, &z);

    if(x <= y && x <= z){

        printf("O menor numero entre eles foi o: %d", x);

    }

    else if( y <= x && y <= z){

        printf("O menor numero entre eles foi o: %d", y);

    }

    else if( z <= x && z <= y){

        printf("O menor numero entre eles foi o: %d", z);

    }




    return 0;
}