#include <stdio.h>
int main(){
    
    float reais, taxaConversaoEuro, taxaConversaoDolar, dolar, euro;

    printf("Escreva o valor do produto em reais: ");
    scanf("%f", &reais);

    printf("Agora escreva a taxa da conversao para dolar? ");   // taxa do dólar no dia que eu fiz era de: 5,04 (20/04/2023)
    scanf("%f", &taxaConversaoDolar);
    printf("Escreva a taxa de conversao para euro: ");      // taxa do euro no dua que eu fiz era de: 5,53 (20/04/2023)
    scanf("%f", &taxaConversaoEuro);
    
    dolar = reais / taxaConversaoDolar;
    euro = reais / taxaConversaoEuro;

    printf("O valor do produto em dolar e: %.2f", dolar);
    printf("O valor do produto em euro e: %.2f", euro);
    
    return 0;
}

/*O que esse algoritmo está fazendo é que ele lê um valor de um produto em reais, e transforma ele tanto dólar quanto em euros, dependendo da cotação do dia*/