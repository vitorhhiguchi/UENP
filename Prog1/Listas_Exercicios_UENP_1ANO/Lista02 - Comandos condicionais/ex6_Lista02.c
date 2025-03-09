#include <stdio.h>
int main(){

    int codigoProduto, quantidade;
    float valor, desconto;

    printf("Qual o produto escolhido?");
    scanf("%d", &codigoProduto);

    switch (codigoProduto){

        case 1:
            printf("Digite a quantidade do produto comprado: ");
            scanf("%d", &quantidade);
            valor = quantidade * 5.3;
            
            if(quantidade >= 15 || valor >= 40){

                desconto = valor - (valor * 0.15);
                printf("O cliente recebeu um desconto e vai pagar R$ %.2f reais", desconto);

            }

            else{

                printf("O cliente nao recebeu o desconto e devera pagar R$ %.2f reais", valor);

            }
        break;

        case 2:
            printf("Digite a quantidade do produto comprado: ");
            scanf("%d", &quantidade);
            valor = quantidade * 6;

            if(quantidade >= 15 || valor >= 40){

                desconto = valor - (valor * 0.15);
                printf("O cliente recebeu um desconto e vai pagar R$ %.2f reais", desconto);

            }

            else{

                printf("O cliente nao recebeu o desconto e devera pagar R$ %.2f reais", valor);

            }
        break;

        case 3:
            printf("Digite a quantidade do produto comprado: ");
            scanf("%d", &quantidade);
            valor = quantidade * 3.2;

            if(quantidade >= 15 || valor >= 40){

                desconto = valor - (valor * 0.15);
                printf("O cliente recebeu um desconto e vai pagar R$ %.2f reais", desconto);

            }

            else{

                printf("O cliente nao recebeu o desconto e devera pagar R$ %.2f reais", valor);

            }
        break;

        case 4:
            printf("Digite a quantidade do produto comprado: ");
            scanf("%d", &quantidade);
            valor = quantidade * 2.5;

            if(quantidade >= 15 || valor >= 40){

                desconto = valor - (valor * 0.15);
                printf("O cliente recebeu um desconto e vai pagar R$ %.2f reais", desconto);

            }

            else{

                printf("O cliente nao recebeu o desconto e devera pagar R$ %.2f reais", valor);

            }
        break;
        default:
            printf("Produto desconhecido!");
    }

    return 0;
}