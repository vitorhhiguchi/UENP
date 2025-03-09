#include <stdio.h>
int main(){

    float gasto, valorTotal, gorjetaGarcom;

    printf("Quanto o senhor(a) gastou no restaurante?");
    scanf("%f", &gasto);

    gorjetaGarcom = gasto * 0.1;

    valorTotal = gasto + gorjetaGarcom;

    printf("O valor total gasto foi de R$ %.2f reais \n", valorTotal);
    printf("O valor que senhor pagou a mais para o garcom foi de R$ %.2f reais \n.", gorjetaGarcom);

    return 0;
}

// O codigo esta lendo quanto foi gasto pelo cliente e tambem calcula junto a gorjeta do garçom, mostrando no fim quanto ele vai ter que pagar