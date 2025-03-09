/* 6. Faça um programa receba a idade de várias pessoas, contabilize e mostre o total de pessoas
com menos de 18 anos e o total com mais de 30 anos. O programa deve ser encerrado quando for digitado o valor 0. */
#include <stdio.h>
int main(){

    int idade, menorDeIdade = 0, maisTrinta = 0;

    // Está exibindo a mensagem na tela e armazenando a idade
    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    // O Looping está comparando se a variável idade é 0 ou < 0, se for 0 ele acaba
    while(idade){
        // As condições é se a idade é < 18 ou > 30, e está incrementando 1, para saber a quantidade de pessoas
        if(idade < 18){
            menorDeIdade++;
        }
        else if(idade > 30){
            maisTrinta++;
        }
        // Exibindo a mensagem na tela e armazenando a resposta
        printf("Digite a idade (ou 0 para encerrar): ");
        scanf("%d", &idade); 
    }
    //Exibindo total de pessoas com as idades definidas
    printf("Total de pessoas com menos de 18 anos eh de: %d\n", menorDeIdade);
    printf("Total de pessoas com mais de 30 anos eh de: %d\n", maisTrinta);

    return 0;
}