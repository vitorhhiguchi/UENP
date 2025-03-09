#include <stdio.h>
int main(){

    float valorDiaria, desconto, descontoOcupacaoDobrada, valorPadrao;

    printf("Digite o valor da diária: ");
    scanf("%f", &valorDiaria);
    
    desconto = valorDiaria - (valorDiaria * 0.30);    //não sei porque motivo, mas por 0.30 em fração não funciona de modo correto a conta.
    descontoOcupacaoDobrada = desconto * (45 * 0.7);  // 0.7, porque é o dobro de 35%
    valorPadrao = valorDiaria * (45 * 0.35); 

    printf("O valor da diaria aplicado com desconto e de: %.2f \n", desconto);
    printf("O total arrecadado com o dobro de ocupacao diaria com o desconto foi de: %.2f \n", descontoOcupacaoDobrada);
    printf("O total arrecado com 35 porcento de ocupacao e sem desconto e de: %.2f \n", valorPadrao);

    return 0;
}
/*O programa basicamente lê o valor de uma diário de um resort, aplica um desconto, calcula quanto que fica com o desconto dado, quanto que ele vai lucrar com o desconto
e com o dobro de ocupação, e sem o desconto com apenas metade das opuções informadas.*/