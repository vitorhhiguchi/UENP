/*6. Implemente uma função que receba como parâmetro o peso (em quilos) e a altura (metros) de uma pessoa, calcule e retorne o seu IMC ( Índice de Massa Corporal), cujo cálculo é dado
por: IMC = peso/(altura * altura). Implemente outra função que receba como parâmetro o IMC de uma pessoa e a classifique de acordo com a Tabela 1.*/
#include <stdio.h>
#include <math.h>
int main(){

    float peso, altura, IMC = 0;  
    float calcularIMC(float peso, float altura);  // Declaração da função
    void classificacaoIMC(float imc); // Declaração da Função

    printf("Digite sua altura e peso: "); // Mostra a mensagem na tela
    scanf("%f%f", &peso, &altura); // Armazena os valores informados

    IMC = calcularIMC(peso, altura); // Armazenando o valor retornado pela função

    classificacaoIMC(); // Chamando a função

    return 0;
}

float calcularIMC(float peso, float altura){ // Função que calcula o IMC do indivíduo 
    float imc = 0; 
    imc = peso / (pow(altura, 2)); // Cálculo do IMC
    return imc; // Retornando o valor calculado
}

void classificacaoIMC(float imc){ // Função que classifica sua situação com IMC
    if(imc < 18.5){  // Comparações para mostrar ao usuário a classificação.
        printf("IMC abaixo do peso!");
    }
    else if(imc <= 24.9){
        printf("IMC peso normal!");
    }
    else if(imc <= 29.9){
        printf("O IMC dessa pessoa indica que ela esta com sobrepeso!");
    }
    else{
        printf("Obesidade!");
    }
}

