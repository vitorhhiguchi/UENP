#include <stdio.h>
int main (){

    float lado1, lado2, area;

    printf("Digite dois lados de um retangulo: ");
    scanf("%f%f", &lado1, &lado2);

    float calcularAreaRetang(float base, float altura); // Instanciando a função
    area = calcularAreaRetang(lado1, lado2); // Salvando e chamando o valor chamado da função

    printf("Area com esses lados eh: %.2f", area);

    return 0;
}

float calcularAreaRetang(float base, float altura){
    float area = base * altura;
    return area;
}