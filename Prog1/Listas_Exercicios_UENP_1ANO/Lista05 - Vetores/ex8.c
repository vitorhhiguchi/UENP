/*8. Fa ̧ca um programa receba a idade de v ́arias pessoas e armazene em um vetor, em seguida,
contabilize e mostre o total de pessoas com menos de 18 anos e o total com mais de 30
anos. O programa deve ser encerrado quando for digitado o valor 0.*/
#include <stdio.h>
int main(){

    int quant, menosDe18 = 0, maisDe30 = 0, i, parametro = 1;

    printf("Digite a quantidade de idades que vai ser inserido: ");
    scanf("%d", &quant);

    int idade[quant];

    for(i=0; i < quant; i++){
        printf("Digite a idade: ");
        scanf("%d", &idade[i]);

        if(idade[i] == 0){
            break;
        }

        if(idade[i] < 18)
            menosDe18++;
        else if(idade > 30)
            maisDe30++;

    }

    printf("Menores de 18: %d\nMais de 30: %d", menosDe18, maisDe30);

    return 0;
}