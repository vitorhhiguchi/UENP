//10. Faça uma função que receba um caractere e verifique se ele é uma vogal ou não.
#include <stdio.h>
int main(){
    char letra;
    void ehVogal(char letraa); // Declaração de função

    printf("Digite uma letra: ");
    scanf("%c", &letra);

    ehVogal(letra);
  
    return 0;
}

void ehVogal(char letraa){ // Função que mostra para o usuário se a letra informada é uma vogal ou não
    if(letraa == 'A' || letraa == 'a' || letraa == 'E' || letraa == 'e' || letraa == 'I' || letraa == 'i' || letraa == 'O' || letraa == 'o' || letraa == 'U' || letraa == 'u'){
        printf("A letra eh uma vogal!");
    }
    else{
        printf("A letra nao eh uma vogal!");
    }
}