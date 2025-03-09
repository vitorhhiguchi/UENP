#include <stdio.h>
int main(){

    float altura;
    int idade, quantBrinquedos = 0;

    printf("Para poder brincar nos brinquedos, alguns tem algumas limitações, então digite sua idade e altura: ");
    scanf("%d%f", &idade, &altura);

    if(altura > 1.5 && idade >= 12){
        quantBrinquedos ++;
    }

    if(altura > 1.4 && idade >= 14){
        quantBrinquedos ++;
    }

    if(altura > 1.7 || idade >= 16){
        quantBrinquedos ++;
    }

    printf("A quantidade que o individuo pode andar eh de: %d brinquedos.", quantBrinquedos);

    return 0;
}