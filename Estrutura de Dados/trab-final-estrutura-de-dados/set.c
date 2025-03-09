#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "set.h"

Lista* createList(){
    return NULL;
}

void add(Lista** set, int elem){
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = elem;
    novo->prox = *set;
    *set = novo;
}

bool isEmpty(Lista* set){
    return (set == NULL);
}

int len(Lista* set) { 
    int count = 0; 
    int seen[1000] = {0};

    while (set != NULL) { 
        if (!seen[set->info]) { 
            printf("%d \n", set->info); 
            seen[set->info] = 1; 
            count++; 
        } 
        set = set->prox;
    } 

    return count; 
}

bool isIn(Lista* set, int elem){
    while(set != NULL){
        if(set->info == elem){
            return true;
        }
        set = set->prox;
    }
    return false;
}

bool isNotIn(Lista* set, int elem){
    while(set != NULL){
        if(set->info == elem){
            return false;
        }
        set = set->prox;
    }
    return true;
}

bool isDisjoint(Lista* set1, Lista* set2){
    Lista* ptr1 = set1;
    Lista* ptr2;

    while(ptr1 != NULL){
        ptr2 = set2;
        while(ptr2 != NULL){
            printf("Comparando %d com %d\n", ptr1->info, ptr2->info);
            if(ptr1->info == ptr2->info){
                printf("Elemento em comum encontrado: %d\n", ptr1->info);
                return false;
            }
            ptr2 = ptr2->prox;
        }
        ptr1 = ptr1->prox;
    }

    return true;
}

void removeElem(Lista** set, int elem){
    Lista* atual = *set;
    Lista* anterior = NULL;

    while(atual != NULL){
        if(atual->info == elem){
            if(anterior == NULL){
                *set = atual->prox;
            } else{
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

Lista* pop(Lista** set) {
    if(*set == NULL) {
        return NULL;
    }

    srand(time(NULL));
    
    int tamanho = len(*set);
    int indice_aleatorio = rand() % tamanho;

    Lista* atual = *set;
    Lista* anterior = NULL;

    for(int i=0; i < indice_aleatorio; i++){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        *set = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    atual->prox = NULL;
    return atual;
}

void clearSet(Lista* set){
    Lista* temp;
    while(set != NULL){
        temp = set->prox;
        free(set);
        set = temp;
    }
}


void addUnique(Lista** result, int elem){
    if(!isIn(*result, elem))
        add(result, elem);
}

Lista* unionSet(Lista* set1, Lista* set2){
    Lista* novo = createList();


    Lista* atual = set1;
    while(atual != NULL){
        addUnique(&novo, atual->info);
        atual = atual->prox;
    }

    atual = set2;
    while(atual != NULL){
        addUnique(&novo, atual->info);
        atual = atual->prox;
    }

    return novo;
}

Lista* intersection(Lista* set1, Lista* set2){
    Lista* novo = createList();

    Lista* atual = set1;
    while(atual != NULL){
        if(isIn(set2, atual->info))
            add(&novo, atual->info);
        atual = atual->prox;
    }

    return novo;
}


Lista* difference(Lista* set1, Lista* set2) {
    Lista* novo = createList();

    Lista* atual = set1;
    while (atual != NULL) {
        if (!isIn(set2, atual->info))
            add(&novo, atual->info);
        atual = atual->prox;
    }

    return novo;
}


Lista* symmetric_difference(Lista* set1, Lista* set2) {
    Lista* novo = createList();

    Lista* atual = set1;
    while (atual != NULL) {
        if (!isIn(set2, atual->info))
            add(&novo, atual->info);
        atual = atual->prox;
    }

    atual = set2;
    while (atual != NULL) {
        if (!isIn(set1, atual->info))
            add(&novo, atual->info);
        atual = atual->prox;
    }

    return novo;
}



bool isSubSet(Lista* set1, Lista* set2) {
    Lista* atual = set1;

    while(atual != NULL){
        if(!isIn(set2, atual->info))
            return false;
        atual = atual->prox;
    }

    return true;
}

bool isSuperSet(Lista* set1, Lista* set2) {
    Lista* atual = set2;
    
    while(atual != NULL) {
        if(!isIn(set1, atual->info))
            return false;
        atual = atual->prox;
    }

    return true;
}

void copy(Lista* set1, Lista** set2){
    *set2 = createList();

    Lista* atual = set1;

    while(atual != NULL){
        add(set2, atual->info);
        atual = atual->prox;
    }
}

void printSet(Lista* set){
    while (set != NULL) {
        printf("%d ", set->info);
        set = set->prox;
    }
    printf("\n");
}
