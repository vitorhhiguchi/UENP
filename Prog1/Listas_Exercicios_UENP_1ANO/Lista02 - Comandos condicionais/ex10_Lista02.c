#include <stdio.h>
int main(){

    int interfaceGrafica, inteligenciaArtificial, encapsulamento, indentacao, structs;
    int nota = 0;

    printf("Digite 5 numeros (0 ou 1) representando os requisitos do trabalho:\n");
    scanf("%d%d%d%d%d", &interfaceGrafica, &inteligenciaArtificial, &encapsulamento, &indentacao, &structs);

    if (interfaceGrafica == 1 || inteligenciaArtificial == 1){
        nota++;
    }
    else{
        printf("O requisito 1 nao foi atendido! \n");
        nota = 0;
    }

    if (encapsulamento == 1 && indentacao == 1){
        nota++;
    }
    else{
        printf("O requisito 2 nao foi atendido! \n");
        nota = 0;
    }

    if (structs == 1){
        nota++;
    }
    else{
        printf("O requisito 3 nao foi atendido! \n");
        nota = 0;
    }

    if(nota == 0){
        printf("O trabalho nao atende aos requisitos minimos. Nota: 0\n");
    }
    else{
        printf("O trabalho sera avaliado!\n");
    }

    return 0;
}