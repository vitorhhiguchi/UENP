/* Implemente a função completa recursiva de busca linear para os elementos de uma Lista encadeada e alocada dinamicamente.
Essa lista guarda a informação do tipo inteiro (int valor). A função recebe como entrada apenas o ponteiro para o ínicio da lista. 
Como saída a função recebe como entrada apenas o ponteiro para o início da lista. Como saída a função deve retornar o endereço onde
está localizado o elemento ou NULL caso não encontre o elemento.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
} Lista;

Lista *insereLista(Lista *lst, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = lst;
    return novo;
}

int buscaLinearRecursivaLista(Lista *lst, int valor){

    if(lst == NULL){
        return 0;
    }
    else if(lst->valor == valor){
        return lst;
    }
    else{
        return buscaLinearRecursivaLista(lst->prox, valor);
    }
}

void LiberaListaRecursivamente(Lista *lst){
    if(lst!=NULL){
        LiberaListaRecursivamente(lst->prox);
        free(lst);
    }
}

// void LiberaListaRecursivamente(Lista *lst){
//     if(lst!=NULL){
//         Lista *aux = lst->prox;
//         free(lst);
//         lst = aux;
//         LiberaListaRecursivamente(lst);
//     }
// }

void imprime(Lista *lst){
    for(Lista *p = lst; p!=NULL; p=p->prox){
        printf("%d ", p->valor);
    }
    printf("\n");
}

int main(){

    Lista *lst = NULL;

    lst = insereLista(lst, 4);
    lst = insereLista(lst, 6);
    lst = insereLista(lst, 2);
    lst = insereLista(lst, 3);
    lst = insereLista(lst, 1);

    // int funcBuscaLinear = buscaLinearRecursivaLista(lst, 2);
    // if(!funcBuscaLinear){
    //     printf("O valor nao esta na lista.\n");
    // }
    // else{
    //     printf("O endereco do valor eh %d\n", funcBuscaLinear);
    // }

    LiberaListaRecursivamente(lst);
    imprime(lst);

    return 0;
}