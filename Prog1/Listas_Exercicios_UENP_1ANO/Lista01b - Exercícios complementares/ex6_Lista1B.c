#include <stdio.h>
int main(){

    float numeroFuncio, horasTrabalhadas, valorHora, salario;

    printf("Escreva o seu numero de funcionario, numero de horas que voce trabalha e o valor que voce recebe por hora: ");
    scanf("%f%f%f", &numeroFuncio, &horasTrabalhadas, &valorHora);

    salario = horasTrabalhadas * valorHora;

    printf("O numero do funcionario eh %.2f, e o salario dele eh de: R$ %.2f reais.", numeroFuncio, salario);

    return 0;
}

// O Codigo esta lendo o numero do funcionario, quantas horas ele trabalha e quanto ele recebe por hora trabalhada, calculando assim o seu salario