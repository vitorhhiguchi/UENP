/*1. Faça uma função para calcular a  ́area de “n” terrenos retangulares, em que “n”  ́e informado
pelo usuário. O programa recebe como entrada o comprimento e a largura de cada terreno
e, ao final, exibe a sua  ́area correspondente.*/
#include <stdio.h>

int main(){

    int numDeTerrenos;
    void calculoDeArea(int num); // Declaração da função, pois ela foi criada logo abaixo da main.

    printf("Digite a quantidade de terrenos: \n"); // Mostrando para o usuário a mensagem
    scanf("%d", &numDeTerrenos); // Salvando o valor escrito

    calculoDeArea(numDeTerrenos); // chamando a função

    return 0;
}

// Função para calcular determinadas quantidades de areas de um retangulo
void calculoDeArea(int num){ 
    int i;
    float largura, comprimento, area=0;
    for(i = 0; i < num; i++){   // Loop para receber os valores para calcular a area, e mostrando o resultado com os valores dados.
        printf("Digite o comprimento e a largura do terreno: \n");
        scanf("%f%f", &comprimento, &largura);
        area = comprimento * largura;
        printf("A area com os valores dado eh de: %.2f\n", area);
        printf("\n");
    }
    
}