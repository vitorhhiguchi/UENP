#include <stdio.h>
int main(){

    float nota1, nota2, nota3, nota4, media;

    printf("Escreva suas notas: ");
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);
    scanf("%f", &nota4);

    media = ((nota1 * 1.5) + (nota2 * 2) + (nota3 * 3) + (nota4 * 3.5)) / (1.5 + 2 + 3 + 3.5);  
    // A formula de media ponderada é Mp = p1 * x + p2 * x2 + p3 * x3 + ... + pn * xn / p1 +p2 + ... + pn
    
    printf("A media do aluno e: %.2f", media);
    
    return 0;
}

//Bom, básicamente esse algoritmo lê as 4 notas de um aluno, e calcula sua média ponderada.