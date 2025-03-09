/* Bubblesort
Perfonamnce:
Melhor caso: n(N)
Pior caso: o(n^2). Pois tem dois for
Não é bom para GRANDEs conjuntos de dados
*/

#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista* prox;
};
typedef struct lista Lista;

void bubbleSort(Lista *lst){
    for(Lista *i=lst; i != NULL; i = i->prox){
        for(Lista *j=lst; j != NULL; j = j->prox){
            if(j->valor > j->prox->valor){
                Lista *aux = (Lista*) malloc(sizeof(Lista*));
                aux->valor = j->valor;
                j->valor = j->prox->valor;
                j->prox->valor = aux->valor;                
            }
        }
    }
}

Lista* criaLista(){
    return NULL;
}

Lista* insereLista(Lista* lst, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista*));

    novo->valor = val;
    novo->prox = lst;

    return novo;
}

void imprimeLista(Lista* lst){
    Lista* novo;
    for(novo = lst; novo !=NULL; novo = novo->prox){
        printf("info = %d\n", novo->valor);
    }
}

void liberaLista(Lista* lst) {
    if (lst == NULL) {
        return;
    }
    liberaLista(lst->prox);
    free(lst);
}

int main(){

    Lista *lista;
    
    lista = criaLista();
    lista = insereLista(lista, 9);
    lista = insereLista(lista, 2);
    lista = insereLista(lista, 3);
    lista = insereLista(lista, 10);
    lista = insereLista(lista, 1);
    lista = insereLista(lista, 6);
    lista = insereLista(lista, 8);
    lista = insereLista(lista, 1);

    printf("Lista antes de ordenar!\n");
    imprimeLista(lista);

    lista = bubbleSort(lista);

    printf("Lista após ser ordenada!\n");
    imprimeLista(lista);


    return 0;
}