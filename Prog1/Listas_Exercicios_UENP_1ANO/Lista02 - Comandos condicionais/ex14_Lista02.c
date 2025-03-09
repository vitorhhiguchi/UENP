#include <stdio.h>
int main(){

    float trajeto, consumo_estimado;
    char tipo_veiculo;

    printf("Digite o trajeto em km percorrido: \n");
    scanf("%f", &trajeto);

    printf("Digite o tipo do veiculo (A, B ou C): \n");
    scanf(" %c", &tipo_veiculo);

    switch(tipo_veiculo){
        case'A':
        case'a':
            consumo_estimado = trajeto / 15;
            break;
        case'B':
        case'b':
            consumo_estimado = trajeto / 12;
            break;
        case'C':
        case'c':
            consumo_estimado = trajeto / 10;
            break;
        default:
            printf("Tipo de veiculo invalido! \n");
    }

    printf("O consumo estimado de combustivel eh de: %.2f litros", consumo_estimado);

    return 0;
}