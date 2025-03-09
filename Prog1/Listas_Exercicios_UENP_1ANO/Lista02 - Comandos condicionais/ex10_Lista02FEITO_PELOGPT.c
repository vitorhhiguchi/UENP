#include <stdio.h>

int main() {
    int interfaceGrafica, inteligenciaArtificial, encapsulamento, indentacao, structs;
    int nota = 0;

    printf("Digite 5 números (0 ou 1) representando os requisitos do trabalho:\n");
    scanf("%d %d %d %d %d", &interfaceGrafica, &inteligenciaArtificial, &encapsulamento, &indentacao, &structs);

    if (interfaceGrafica == 1 || inteligenciaArtificial == 1) {
        nota++;
    } 
    
    else {
        printf("O requisito 1 não foi atendido.\n");
        nota = 0;
    }

    if (encapsulamento == 1 && indentacao == 1) {
        nota++;
    } 
    
    else {
        printf("O requisito 2 não foi atendido.\n");
        nota = 0;
    }

    if (structs == 1) {
        nota++;
    } 
    
    else {
        printf("O requisito 3 não foi atendido.\n");
        nota = 0;
    }

    if (nota == 0) {
        printf("O trabalho não atende aos requisitos mínimos. Nota: 0\n");
    } 
    
    else {
        printf("O trabalho será avaliado. Nota: %d\n", nota);
    }

    return 0;
}