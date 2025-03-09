#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255
int main(){

    int totalPalavras(char str, int tam);
    char ultimaPalavra(char str, int tam);
    float porcentagemDeVogais(char str, int tam);
    char criptografia(char str, int tam);

    char string[MAX+1];
    int tamanho;

    printf("Entre com sua string: ");
    fgets(string, MAX+1, stdin);

    puts(string);
    tamanho = totalPalavras(string, MAX);
    printf("%d, tamanho", tamanho);
    










    return 0;
}

int totalPalavras(char str, int tam){

}

int tamanhoDaString(char str, int tam){
    int tamanho = 0, i;

    while(str[i] != '\o'){
        tamanho++;
        i++;
    }

    return tamanho;
}

char criptografia(char str, int tam){
    
}