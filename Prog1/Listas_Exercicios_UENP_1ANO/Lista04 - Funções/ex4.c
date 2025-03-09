/*4. Faça um programa que calcule a potencia de um número qualquer fornecido pelo usuário. Para isso, implemente uma função que receba como parâmetro dois números inteiros x e n, 
calcule e retorne para o programa principal o resultado de x**n. NÃO USE nenhuma função pronta(ou seja, pow())*/
#include <stdio.h>
int main(){

    int x, n;
    int potenciaDeQualquerNumero(int numero, int potencia); // Declaração de função

    printf("Digite dois numeros inteiros: "); // Mostrando na tela a mensagem
    scanf("%d%d", &x, &n); // Armazenando os valores nas variaveis

    printf("O numero %d, elevado a %d eh igual a %d", x, n, potenciaDeQualquerNumero(x, n)); // Mostrando o resultado ja chamando a função

    return 0; 
}

int potenciaDeQualquerNumero(int numero, int potencia){  // Funçãoa que cálcula a pontecia de qualquer número
    int i, pot = 1;  // Declaração das variáveis de escopo
    for(i=0; i < potencia; i++){ // Looping para fazer o cálculo de potência
        pot = pot * numero;  // Calculo da potencia de um numero 
    }
    return pot;  // retornando o valor calculado
}