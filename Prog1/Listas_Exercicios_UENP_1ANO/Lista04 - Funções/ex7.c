// 7. Faça uma função que receba um número inteiro qualquer, calcule e mostre a tabuada deste número.
#include <stdio.h>
int main(){
    int numero;
    void tabuada(int num); // Declaração de função

    printf("Digite um numero inteiro: "); // Mostra para o usuário a mensagem
    scanf("%d", &numero); // Armazenando o valor informado

    tabuada(numero); // Chamando a função
    return 0;
}

void tabuada(int num){ // Função que calcula a tabuada do número informado
    int i, multipli;
    // Loop para calcular e mostrar a tabuada
    for(i = 1; i <= 10; i++){
        multipli = i * num;
        printf("%d X %d = %d\n", num, i, multipli); 
    }
}