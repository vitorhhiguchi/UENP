#include <stdio.h>
int main(){

    float num1, num2, num3, mediaArit;
    int acimaMedia = 0;

    printf("Digite 3 numeros positivos: ");
    scanf("%f%f%f", &num1, &num2, &num3);

    mediaArit = (num1 + num2 + num3) / 3;

    if (num1 > mediaArit){

        acimaMedia++;

    }
    
    if (num2 > mediaArit){

        acimaMedia++;

    }
    
    if (num3 > mediaArit){

        acimaMedia++;

   }

    printf("A media aritmetica eh de: %.2f\n", mediaArit);
    printf("A Quantidade de numeros acima da media eh de: %d\n", acimaMedia);
    
    return 0;
}