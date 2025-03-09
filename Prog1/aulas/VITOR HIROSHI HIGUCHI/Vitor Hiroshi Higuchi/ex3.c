#include <stdio.h>
#include <stdlib.h>

int main(){

    int quantDeProdutos, i, j, quantLojas, quantEmCadaLoja;

    printf("Digite quantas lojas tem o produto");
    scanf("%d", &quantLojas);

    printf("Digite a quantidade de produtos eletronicos: ");
    scanf("%d", &quantDeProdutos);

    float preco[quantDeProdutos];

    for(i=0; i<quantDeProdutos; i++){
        printf("Digite o preco do produto: ");
        scanf("%f", &preco[i]);
    }

    int quantProdutosCadaLoja[quantLojas];
    int quantidadeEmLojasDif[quantDeProdutos][quantLojas];

    for(i=0; i<quantDeProdutos; i++){
        for(j=0; j<quantLojas){
            printf("Digite a quantidade de produtos na loja %d", i);
            scanf("%d", &quantidadeEmLojasDif)

            quantProdutosCadaLoja[j] += quantidadeEmLojasDif;
        }
    }





    return 0;
}
