#include <stdio.h>
int main(){
    
    int quantidadeDeProdutosEletronicos, quantidadeDeLojas, i, j, quantLoja1=0, quantLoja2=0, quantLoja3=0, quantLoja4=0, quantLoja5=0;
    int quantProd1=0, quantProd2=0, quantProd3=0, quantProd4=0, quantProd5=0;
    float custoLoja1, custoLoja2, custoLoja3, custoLoja4, custoLoja5;

    printf("Digite a quantidade de tipos de produtos eletronicos que sua fabrica produz: \n");
    scanf("%d", &quantidadeDeProdutosEletronicos);
    printf("Digite a quantidade de lojas que essa fabrica entrega os produtos: \n");
    scanf("%d", quantidadeDeLojas);

    int m, n;

    m = quantidadeDeProdutosEletronicos;
    n = quantidadeDeLojas;

    float precoDosProdutosEletronicos[m];
    int estoqueDasLojas[m][n];
    
    printf("Digite o preco dos produtos: \n");
    for(i=0; i<m; i++){
        scanf("%f", &precoDosProdutosEletronicos[i]);
    }

    print("Agora digite o estoque de cada produto em lojas diferentes: \n");

    // Não consegui pensar em uma maneira para conseguir criar variaveis para guardar a quantidade de cada loja, pq n sabemos ao certo a quantidade de lojas que vai ter
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &estoqueDasLojas[i][j]);

            if(estoqueDasLojas[i][0] > 0){
                quantLoja1 += estoqueDasLojas[i][0]
            }
            if(estoqueDasLojas[i][1] > 0){
                quantLoja2 += estoqueDasLojas[i][1]
            }
            if(estoqueDasLojas[i][2] > 0){
                quantLoja3 += estoqueDasLojas[i][2]
            }
            if(estoqueDasLojas[i][3] > 0){
                quantLoja4 += estoqueDasLojas[i][3]
            }
            if(estoqueDasLojas[i][4] > 0){
                quantLoja5 += estoqueDasLojas[i][4]
            }

            if(estoqueDasLojas[0][j] > 0){
                quantProd1 += estoqueDasLojas[0][j]
            }
            if(estoqueDasLojas[1][j] > 0){
                quantProd2 += estoqueDasLojas[1][j]
            }
            if(estoqueDasLojas[2][j] > 0){
                quantProd3 += estoqueDasLojas[2][j]
            }
            if(estoqueDasLojas[3][j] > 0){
                quantProd4 += estoqueDasLojas[3][j]
            }
            if(estoqueDasLojas[4][j] > 0){
                quantProd5 += estoqueDasLojas[4][j]
            }
        }
    }

    custoLoja1 = quantLoja1 + quantProd1;
    custoLoja2 = quantLoja2 + quantProd2;
    custoLoja3 = quantLoja3 + quantProd3;
    custoLoja4 = quantLoja4 + quantProd4;
    custoLoja5 = quantLoja5 + quantProd5;


    printf("A quantidade de produtos em cada uma das lojas eh de: \n");
    printf("Loja1: %d\n", quantLoja1);
    printf("Loja2: %d\n", quantLoja2);
    printf("Loja3: %d\n", quantLoja3);
    printf("Loja4: %d\n", quantLoja4);
    printf("Loja5: %d\n", quantLoja5);
    printf("A quantidade de cada um dos produtos armazenados em todas as lojas eh de: \n");
    printf("Produto1: %d\n", quantProd1);
    printf("Produto2: %d\n", quantProd2);
    printf("Produto3: %d\n", quantProd3);
    printf("Produto4: %d\n", quantProd4);
    printf("Produto5: %d\n", quantProd5);   
    printf("O valor do produto que possui maior estoque em cada uma das lojas eh de: \n");
    printf("O custo de cada loja eh de: \n");
    printf("Custo loja1: %d\n", custoLoja1);
    printf("Custo loja2: %d\n", custoLoja2);
    printf("Custo loja3: %d\n", custoLoja3);
    printf("Custo loja4: %d\n", custoLoja4);
    printf("Custo loja5: %d\n", custoLoja5);  

    return 0;
}