#include "urna.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpaTerminal(){
    system("cls");
}

int quantidadeDeChapas(){
    int quantChapas = 0

    printf("Digite a quantidade de chapas que serao registradas: ");
    scanf("%d", &quantChapas);

    if(quantChapas == 0  || quantChapas > 99){
        printf("A quantidade de chapas permitidas eh 1 ate 99!");
        quantChapas();
    }

    return quantChapas;
}