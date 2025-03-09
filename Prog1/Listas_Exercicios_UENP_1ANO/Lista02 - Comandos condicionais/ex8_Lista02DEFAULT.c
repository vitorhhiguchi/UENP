#include <stdio.h>
int main(){

    float x, y, media, diferenca, produto, divisao;
    int opcao;

    printf("Digite dois numeros: ");
    scanf("%f%f", &x, &y);
    printf("Escolha uma opcao de operacao: 1 2 3 4 ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            media = (x + y) / 2;
            printf("A media entre esses dois numeros eh de: %.2f", media);
            break;
            
        case 2:
                
            if(x >= y){
                    
                diferenca = x - y;
                printf("A diferenca eh de: %.2f", diferenca);
                
            }
                
            else{
                    
                diferenca = y - x;
                printf("A diferenca eh de: %.2f", diferenca);
                
            }
            break;

        case 3:

            produto = x * y;
            printf("O produto entre os numeros eh de: %.2f", produto);

            break;

        case 4:

            divisao = x / y;
            printf("O produto entre os numeros eh de: %.2f", divisao);
            
            break;

        default:
            printf("Error, valor invalido!");
    }
    
    return 0;
}