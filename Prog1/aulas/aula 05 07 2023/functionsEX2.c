//Faça uma função que recebe um número e retorne verdadeiro, caso o número seja negativo, ou falso, caso contrário.
#include <stdio.h>
int verdadeiroOuFalso (int num){
    if(num < 0){
        num = 1;
    }
    else{
        num = 0;
    }
    return num;
}

int main(){
    
    int num, comparar;

    printf("Digite um numero: ");
    scanf("%d", &num);

    comparar = verdadeiroOuFalso(num);
    printf("%d", comparar);

}