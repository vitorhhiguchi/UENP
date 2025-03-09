#include <stdio.h>
int main(){

    float saldo_medio, valor_do_credito;

    printf("Digite o seu saldo medio do ultimo ano: ");
    scanf("%f", &saldo_medio);

    if (saldo_medio > 400){
        valor_do_credito = saldo_medio * 0.3;
    }
    
    else if (saldo_medio > 300 && saldo_medio <= 400){
        valor_do_credito = saldo_medio * 0.25;
    }

    else if (saldo_medio > 200 && saldo_medio <= 300){
        valor_do_credito = saldo_medio * 0.2;
    }

    else if (saldo_medio <= 200){
        valor_do_credito = saldo_medio * 0.1;
    }

    printf("O valor do seu credito especial eh de: R$ %.2f reais", valor_do_credito);
    
    return 0;
}