#include <stdio.h>
#include <stdlib.h>

int main(){

    void maisDeDuasProvas(int idade[], int disciplina[], int prova[][]);
    void listagemAnliseTresProvas(int idade[], int disciplina[], int prova[][]);
    void mediaIdade(int idade[], int prova[][]);
    int i, j, idade[8], disciplina[5], provas[8][5];

    for(i=0; i<8; i++){
        printf("Digite a idade do do aluno %d: ", i+1);
        scanf("%d", &idade[i]);
    }

    for(i=0; i<5; i++){
        printf("Digite os codigos das discplinas: ");
        scanf("%d", &disciplina[i]);
    }

    for(i=0; i<8; i++){
        for(j=0; j<5; j++){
            printf("Digite quantas provas o aluno %d fez na disciplina %d: ", i+1, j+1);
            scanf("%d", &provas[i][j]);
        }
    }

    maisDeDuasProvas(idade, disciplina, provas);
    listagemAnliseTresProvas(idade, disciplina, provas);
    mediaIdade(idade, disciplina, provas);

    return 0;
}

void maisDeDuasProvas(int idade[], int disciplina[], int prova[][]){
    int i, j;
    for(i=0; i<8; i++){
        if(idade[i]>=18 && idade[i]>=25){
            for(j=0; j<5; j++){
                if(prova[i][j] > 2){
                    printf("O aluno %d, fez mais de duas provas na disciplina %d", i+1, j+1);
                }
            }
        }
    }
}

void listagemAnliseTresProvas(int idade[], int disciplina[], int prova[][]){
    int i, j;

    for(i=0; i<8; i++){
        for(j=0; j<5; j++){
            if(prova[i][j] < 3){
                printf("O aluno %d nao fez mais de tres provas na discplina %d\n", i+1, j+1);
            }
        }
    }

}

void mediaIdade(int idade[], int prova[][]){
    int i, j, count=0;
    float mediaIdade=0;

    for(i=0; i<8; i++){
        for(j=0; j<5; j++){
            if(prova[i][j] == 0){
                mediaIdade += idade[i];
                count++;
            }
        }
    }
    mediaIdade = mediaIdade/count++;

    printf("A media das idades de quem nao fez nenhuma em alguma disciplina eh de: %.2f", mediaIdade);
}