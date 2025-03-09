// Exercicio: calcular a media de 30 alunos
#include <stdio.h>
int main(){

    int aluno = 0;
    float media, nota1, nota2, nota3, nota4;

    while (aluno < 30){
        printf("Escrevas as 4 notas do aluno: \n");
        scanf("%f%f%f%f", &nota1, &nota2, &nota3, &nota4);

        media = (nota1 + nota2 + nota3 + nota4) / 4;
        printf("A media do aluno %d eh de: %.2f\n", aluno, media);
        
        aluno++;
    }

    return 0;
}