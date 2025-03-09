#include <stdio.h>
int main (){

    float calcularAreaRetang(float base, float altura); // Instanciando a função
    float area = calcularAreaRetang(10.0, 20.0); // Salvando e chamando o valor chamado da função

    printf("Area com esses lados eh: %.2f", area);

    return 0;
}

float calcularAreaRetang(float base, float altura){
    float area = base * altura;
    return area;
}