#include <stdio.h>
int main(){

    int numero;
    int continuacao;

    do{
        printf("Digite um numero qualquer: \n");
        scanf("%d", &numero); 
        
        if (numero % 2 == 0){
            printf("O numero eh PAR!\n");
        }
        else{
            printf("O numero eh IMPAR!\n");
        }

        printf("Gostaria de continuar com as comparacoes ? Caso queira digite 0, caso nao digite 1. \n");
        scanf("%d", &continuacao);

    } while (continuacao != 0);

    return 0;
}