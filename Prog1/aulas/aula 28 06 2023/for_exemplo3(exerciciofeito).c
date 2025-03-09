// PROVAVELMENTE CAI EM PROVA
// Calcule e informa a média de 30 Alunos utilize FOR (4 notas)
#include <stdio.h>
int main(){

    float n1, n2, n3, n4, media;
    int i;

    for(i = 1; i <= 30; i++){
        printf("Digite as medias do aluno: ");
        scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
        
        media = (n1 + n2 + n3 + n4)/ 4;

        printf("A media do aluno %d eh: %.2f\n", i, media);
        
        if(media >= 7){
            printf("APROVADO!\n");
        }
        else if(media < 7 && media > 4){
            printf("EXAME!\n");
        }
        else{
            printf("REPROVADO!\n");
        }
    }

    return 0;
}