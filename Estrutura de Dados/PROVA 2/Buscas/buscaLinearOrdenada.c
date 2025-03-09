/* Busca linear ordenada

*/

#include <stdio.h>

int buscaLinear(int *vet[], int tam, int element){
    int i;
    //cria um for e percorre toda a lista até achar o elemento
    for(i=0; i < tam; i++){
        if(element == vet[i]){
            return i;
        }else{
            if(element < vet[i]){
                return -1;
            }
        }
    }
    return -1; // não achou
}

int main(){

    int vetor[10] = {10, 2, 3, 5, 6, 1, 4, 7, 9, 8};

    printf("Buscando elemento...\n");
    int pos = buscaLinear(vetor, 10, 12);
    
    if(pos > 0){
        printf("Elemento encontrado!\n");
        printf("vetor[%d] = %d", pos-1, vetor[pos]);
    }else{
        printf("Elemento NAO encontrado!\n");
    }

    return 0;
}