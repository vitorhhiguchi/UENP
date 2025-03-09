#include <stdio.h>
int main(){

    float salario, imposto, gratificacao;

    printf("Escreva seu salario: ");
    scanf("%f", &salario);

    gratificacao = 50;
    imposto = salario * 0.12;
    salario = salario - imposto + gratificacao;
    
    printf("O salario que voce vai receber pagando os impostos e recebendo uma gratificacao e de: R$ %.2f reais. ", salario);

    return 0;
}

/*O algoritmo basicamente pede o salario de alguem, e com o salario informado ele já calcula quanto realmente essa pessoa tem "livre" para ele,
e junto com a gratificação.*/