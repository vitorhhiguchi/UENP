#include <stdio.h>
int main(){

    int numero;

    do{
        printf("Digite um numero qualquer ou 0 para sair: \n");
        scanf("%d", &numero); 
        
        if (numero % 2 == 0){
            printf("O numero eh PAR!\n");
        }
        else{
            printf("O numero eh IMPAR!\n");
        }
    } while (numero != 0);

    return 0;
}