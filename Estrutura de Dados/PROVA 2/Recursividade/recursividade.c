#include <stdio.h>

int fatorial(int n){
    if(n==1){
        return 1;
    }else{
        return n*fatorial(n-1); 
    }
}

int main(){

    int numero;

    printf("Digite um numero: \n");
    scanf("%d", &numero);

    int factor = fatorial(numero);

    printf("O fatorial do numero %d = %d", numero, factor);

    return 0;
}