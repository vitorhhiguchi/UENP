/* Busca binaria
*/

#include <stdio.h>

int buscaBinaria(int *vet[], int tam, int element){
    int i, inicio, meio, final;
    inicio = 0;
    final = tam-1;
    while(inicio <= final){
        meio = (inicio+final)/2;
        if(element < vet[meio]){
            final = meio-1;
        }else{
            if(element > vet[meio]){
                inicio = meio+1;
            }else {
                return meio;
            }
        }
    }
    return -1;
}

int main(){
    int vet[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};

    if(buscaBinaria(vet, 10, 14) != -1){
        printf("Ok!\n");
    }else{
        printf("ERRO\n");
    }

    return 0; 
}