// Fazendo um jogo da velha
#include <stdio.h>
#define LIN 9 
#define COL 9
int main(){

    int i, j, posicaoLin, posicaoCol;
    float jogoDaVelha[LIN][COL];
    char jogada = 'X', linha1, linha2, linha3, linha4, linha5;
    
    for(i=0; i < LIN; i++){
        printf("Digite onde voce quer marcar o X(ou a bolinha): \n");    
        scanf("%d%d", &posicaoLin, &posicaoCol);

        if(i % 2 == 0){
            printf("Vez do X:\n");
            jogada = 'X';
            if(posicaoLin == 0 && posicaoCol == 0){
                linha1 = "%c |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";

            }
            else if(posicaoLin == 0 && posicaoCol == 1){
                linha1 = "   | %c  |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";
            }
            else if(posicaoLin == 0 && posicaoCol == 2){
                linha1 = "   |     | %c \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";                
            }
            else if(posicaoLin == 1 && posicaoCol == 0){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "%c |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";                       
            }
            else if(posicaoLin == 1 && posicaoCol == 1){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |  %c |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";       
            }
            else if(posicaoLin == 1 && posicaoCol == 2){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     | %c \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";       
            }
            else if(posicaoLin == 2 && posicaoCol == 0){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "%c |     |    \n";  
            }
            else if(posicaoLin == 2 && posicaoCol == 1){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |  %c |    \n";  
            }
            else if(posicaoLin == 2 && posicaoCol == 2){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     | %c \n";                  
            }
        }
        else{
            printf("Vez do O:\n");
            jogada = 'O';

            if(posicaoLin == 0 && posicaoCol == 0){
                linha1 = "%c |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";

            }
            else if(posicaoLin == 0 && posicaoCol == 1){
                linha1 = "   | %c  |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";
            }
            else if(posicaoLin == 0 && posicaoCol == 2){
                linha1 = "   |     | %c \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";                
            }
            else if(posicaoLin == 1 && posicaoCol == 0){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "%c |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";                       
            }
            else if(posicaoLin == 1 && posicaoCol == 1){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |  %c |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";       
            }
            else if(posicaoLin == 1 && posicaoCol == 2){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     | %c \n";
                linha4 = "--------------\n";
                linha5 = "   |     |    \n";       
            }
            else if(posicaoLin == 2 && posicaoCol == 0){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "%c |     |    \n";  
            }
            else if(posicaoLin == 2 && posicaoCol == 1){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |  %c |    \n";  
            }
            else if(posicaoLin == 2 && posicaoCol == 2){
                linha1 = "   |     |    \n";
                linha2 = "--------------\n";
                linha3 = "   |     |    \n";
                linha4 = "--------------\n";
                linha5 = "   |     | %c \n";                  
            }
        }
    }











}