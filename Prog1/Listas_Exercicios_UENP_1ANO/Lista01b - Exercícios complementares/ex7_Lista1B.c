#include <stdio.h>
int main(){

    float dias, kmRodado, totalaPagar;

    printf("Digite quantos dias voce ficou com o carro e quanto km rodados: ");
    scanf("%f%f", &dias, &kmRodado);

    totalaPagar = ((dias * 30) + (kmRodado * 0.01)) - (((dias * 30) + (kmRodado * 0.01)) * 0.1);
    
    printf("O valor total que devera ser pago eh de: R$ %.2f reais.", totalaPagar);


    return 0;
}

// O programa le quantos dias vc fico com um carro alugado, quantos kms vc rodou, e o total a pagar