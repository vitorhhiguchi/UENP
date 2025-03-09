//Ex2: Calcular o fatorial de un numero n
#include <stdio.h>
int main(){

    int fat, n;

    printf("Digite um numero: ");
    scanf("%d", &n);
    fat = 1;

/*Esse while basicamente esta fazendo o que? Ele esta comparando o numero que vc escreveu, fat *= n mesma coisa que fat = fat * n
Então o programa faz com que o fat receba uma fatorial de um numero qualquer.*/
    while (n > 1){
        fat *= n;
        n--;
    }

    printf("\n%d", fat);
    return 0;
}