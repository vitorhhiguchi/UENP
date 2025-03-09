//Media de um numero desconhecido de alunos, com um comparador para saber se ele foi aprovado ou não
#include <stdio.h>
int main(){

    float n1, n2, n3, n4, media;
    int codigo;
    char continuar = 's'; //inicializa para comparação

    while (continuar == 's'){ //enquanto a resposta for 's', ele vai continuar o programa
        printf("Escreva o codigo do aluno: ");
        scanf("%d", &codigo);
        printf("Escreva suas 4 notas: ");
        scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
        
        media = (n1 + n2 + n3 + n4) / 4;

        if(media >= 7){
            printf("Situacao do Aluno: APROVADO!\n");
        }
        else if(media < 4){
            printf("Situacao do Aluno: REPROVADO!\n");
        }
        else{
            printf("Situacao do Aluno: EXAME!\n");
        }


        printf("Codigo: %d,    Media: %.2f\n ", codigo, media);

        printf("Mais alunos ? Responda s ou n \n"); // o WHILE via continuar ??
        scanf(" %c", &continuar); // le a resposta
    }

    return 0;
}