#include <stdio.h>
int main(){

    float horas, tarifa=5, taxaHoraExcedida, totalArrecadado=0;
    int placa;

    do{
        printf("Digite a placa do seu veiculo e o tempo que ele ficou no local: \n");
        scanf("%d%f", &placa, &horas);

        if(horas > 2){
            taxaHoraExcedida = tarifa + (horas - 2) * 3;
            tarifa = taxaHoraExcedida;
        }

        printf("[%d] placa do carro, horas estacionados: %.2f, o valor a pagar: %.2f\n", placa, horas, tarifa);
        totalArrecadado += tarifa;
    }while(placa);

    printf("O valor arrecadado no total foi de: %.2f", totalArrecadado);

    return 0;
}