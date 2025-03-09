#include <stdio.h>

int gVariavelGlobal = 2;  // Criando uma variável global, que pode ser utilizado em qualquer função

int main(void){

    printf("global: %d\n", gVariavelGlobal);

    void teste(void);  
    teste();
    teste();
    teste();

    return 0;
}

void teste(void){
    int variavelLocalAutomatica = 2; // a variável volta sempre quando é chamado
    variavelLocalAutomatica *= 2;

    static int variavelLocalEstatica = 2; // static faz com que o valor dado não se perca
    variavelLocalEstatica *= 2;  // portanto ela sempre vai aumentar o valor quando é chamado
    
    printf("Local Automatica = %d\n", variavelLocalAutomatica);
    printf("Local Estatica = %d\n", variavelLocalEstatica);
    printf("\n");
    printf("global: %d\n", gVariavelGlobal);
}