/* Desenvolva um Algoritmo onde o usuário irá inserir duas notas. Utilize duas funções, uma para somar e printar o valor e outra para dividir
e printar o valor*/
#include <stdio.h>

int soma (int num1, int num2){
    return num1 + num2;
}

int divisao (int num1, int num2){
    return num1 / num2;
}

int main(){

    int num1, num2, somar, dividir;

    printf("Digite o numero 1: \n");
    scanf("%d", &num1);
    printf("Digite o numero 2: \n");
    scanf("%d", &num2);

    somar = soma(num1, num2);
    dividir = divisao(num1, num2);
    
    printf("A soma desses numeros eh de: %d\n", somar);
    printf("A divisao desses numeros eh de: %d\n", dividir);
    
    return 0;
}