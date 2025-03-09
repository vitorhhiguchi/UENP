#include <stdio.h>
int main(){

    float nota1, nota2, nota3, nota4, mediaNotas;
    float mediaPassar;

    printf("Escreva suas notas: ");
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);
    scanf("%f", &nota4);

    mediaNotas = ((nota1 * 1.5) + (nota2 * 2) + (nota3 * 3) + (nota4 * 3.5)) / (1.5 + 2 + 3 + 3.5);  
    // A formula de media ponderada é Mp = p1 * x + p2 * x2 + p3 * x3 + ... + pn * xn / p1 +p2 + ... + pn
    
    printf("A media do aluno e: %.2f \n", mediaNotas);

    printf("Escreva a media necessaria para passar: ");
    scanf("%f", &mediaPassar);
    
    if (mediaNotas >= mediaPassar) {
        printf("Parabens, voce esta APROVADO");
    }
    else{
        printf("Infelizemente, voce foi REPROVADO");
    }



/*    if (mediaNotas >= 70) {      
        printf("Parabens, voce esta APROVADO")           MEDIA NECESSARIA PARA PASSAR NA UENP
    }
    else{
        printf("Infelizemente, voce foi REPROVADO")
    } */



    return 0;
}

//Bom, básicamente esse algoritmo lê as 4 notas de um aluno, e calcula sua média ponderada.
//Esse outro programa que eu fiz agora, aprimorei o algoritmo, com a estrutura condicional IF, fazendo com que mostre se o aluno foi aprovado ou reprovado. 