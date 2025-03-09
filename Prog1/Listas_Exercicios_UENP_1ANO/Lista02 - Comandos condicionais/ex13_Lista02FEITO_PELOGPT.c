#include <stdio.h>

int main() {
    float saldoMedio, valorCredito;

    printf("Digite o saldo médio do cliente: R$ ");
    scanf("%f", &saldoMedio);

    if (saldoMedio > 400.0) {
        valorCredito = saldoMedio * 0.3;
    } 
    
    else if (saldoMedio > 300.0) {
        valorCredito = saldoMedio * 0.25;
    } 
    
    else if (saldoMedio > 200.0) {
        valorCredito = saldoMedio * 0.2;
    } 
    
    else {
        valorCredito = saldoMedio * 0.1;
    }

    printf("O valor do crédito especial é: R$ %.2f\n", valorCredito);

    return 0;
}