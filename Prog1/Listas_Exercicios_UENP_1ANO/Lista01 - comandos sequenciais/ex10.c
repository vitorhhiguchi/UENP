#include <stdio.h>
int main(){

    float distanciaTotalKM, combusGasto, consumoMedio;

    printf("Qual foi a distancia percorrida em km? ");
    scanf("%f", &distanciaTotalKM);
    printf("Qual foi o total de combustivel gasto em litros? ");
    scanf("%f", &combusGasto);

    consumoMedio = distanciaTotalKM / combusGasto;

    printf("O consumo medio do veiculo foi de %.2f km/l \n", consumoMedio);

    return 0;
}

// O Programa está lendo o total de km andado por algum veiculo e quanto ele gastou de gasolina, a partir disso ele calcula a media de km/l