#include <stdio.h>
int main(){

    int cafe, dinheiroRecebido, quantidadeDeCafe, trocoPerdido, notas; 

    printf("Qual a quantidade de notas o senhor(a) quer inserir? Aceito apenas notas de 5 reais) ");
    scanf("%d", &notas);

    dinheiroRecebido = notas * 5;
    cafe = 7;
    quantidadeDeCafe = dinheiroRecebido / cafe;
    trocoPerdido = dinheiroRecebido - (cafe * quantidadeDeCafe);

    printf("O senhor(a) ira perder %d reais(l) ", trocoPerdido);

    return 0;
}

/*Basicamente, o programa está lendo a quantidade de notas que uma pessoa esta colocando na máquina, e ela calcula quantos cafés vc consegue comprar com esse dinheiro 
e quanto de dinheiro do troco está sendo perdido.*/