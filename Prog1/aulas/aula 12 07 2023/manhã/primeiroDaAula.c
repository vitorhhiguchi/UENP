#include <stdio.h>

int main(){

    void imprimaMensagem(void); // declara a função, pois estamos criando ela depois

    imprimaMensagem();

    return 0;
}

void imprimaMensagem(void){
    printf("teste.");
}