#include <stdio.h>

int main() {
    float trajeto, consumo;
    char tipoVeiculo;

    printf("Digite o trajeto em km percorrido: ");
    scanf("%f", &trajeto);

    printf("Digite o tipo do veículo (A, B ou C): ");
    scanf(" %c", &tipoVeiculo);

    switch (tipoVeiculo) {
        case 'A':
        case 'a':
            consumo = trajeto / 15.0;
            break;
        case 'B':
        case 'b':
            consumo = trajeto / 12.0;
            break;
        case 'C':
        case 'c':
            consumo = trajeto / 10.0;
            break;
        default:
            printf("Tipo de veículo inválido.\n");
            return 1;
    }

    printf("O consumo estimado de combustível é: %.2f litros\n", consumo);

    return 0;
}