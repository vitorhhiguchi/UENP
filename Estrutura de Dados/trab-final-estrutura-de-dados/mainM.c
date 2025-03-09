#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

int main(){
    Lista* lista;

    lista = createList();
    add(&lista, 25);
    add(&lista, 25);
    add(&lista, 50);
    add(&lista, 50);
    add(&lista, 51);
    add(&lista, 51);
    add(&lista, 51);

    if(lista == NULL){
        printf("Lista criada com sucesso! Ponteiro: %p\n", lista);
    }else {
        printf("Erro ao criar lista.\n");
    }

    Lista* atual = lista; 
    while (atual != NULL) { 
        printf("%d ", atual->info); 
        atual = atual->prox; 
    }

    printf("\n");

    if(isEmpty(lista)){
        printf("Lista nao esta vazia!\n");
    }else{
        printf("Lista esta vazia!\n");
    }

    int tamDaLista = len(lista);

    printf("Tamanho da lista: %d\n", tamDaLista);

    bool encontrado = isIn(lista, 25);

    printf("Resultado da verificacao na lista: %s\n", encontrado ? "true" : "false");

    if (encontrado) { 
        printf("O numero esta na lista!\n"); 
    } else { 
        printf("O numero NAO esta na lista!\n"); 
    }

    encontrado = isIn(lista, 123);

    printf("Resultado da verificacao na lista: %s\n", encontrado ? "true" : "false");

    if (encontrado) { 
        printf("O numero esta na lista!\n"); 
    } else { 
        printf("O numero NAO esta na lista!\n"); 
    }

    printf("\n\n");

    bool naoEstaNaLista = isNotIn(lista, 2);

    printf("Resultado da verificacao na lista: %s\n", naoEstaNaLista ? "true" : "false");

    if (naoEstaNaLista) { 
        printf("O numero NAO esta na lista!\n"); 
    } else { 
        printf("O numero esta na lista!\n"); 
    }

    naoEstaNaLista = isNotIn(lista, 51);

    printf("Resultado da verificacao na lista: %s\n", naoEstaNaLista ? "true" : "false");

    if (naoEstaNaLista) { 
        printf("O numero NAO esta na lista!\n"); 
    } else { 
        printf("O numero esta na lista!\n"); 
    }

    printf("\n\n");

    Lista* lista2;

    lista2 = createList();

    add(&lista2, 25);
    add(&lista2, 25);
    add(&lista2, 50);
    add(&lista2, 50);
    add(&lista2, 51);
    add(&lista2, 51);
    add(&lista2, 51);

    if(lista2 == NULL){
        printf("Lista criada com sucesso! Ponteiro: %p\n", lista2);
    }else {
        printf("Erro ao criar lista.\n");
    }

    Lista* atual2 = lista2; 
    while (atual2 != NULL) { 
        printf("%d ", atual2->info); 
        atual2 = atual2->prox; 
    }

    printf("\n");

    bool resultadoIntersec = isDisjoint(lista, lista2);

    if (resultadoIntersec) { 
        printf("Nao ha numeros em comum entre as listas passadas!\n"); 
    } else { 
        printf("Ha numeros em comum entre as listas passadas!\n"); 
    }

    printf("\n");

    Lista* lista3;

    lista3 = createList();

    add(&lista3, 1);
    add(&lista3, 2);
    add(&lista3, 3);
    add(&lista3, 4);
    add(&lista3, 5);
    add(&lista3, 6);
    add(&lista3, 7);

    bool resultadoIntersec2 = isDisjoint(lista, lista3);

    if (resultadoIntersec2) { 
        printf("Nao ha numeros em comum entre as listas passadas!\n"); 
    } else { 
        printf("Ha numeros em comum entre as listas passadas!\n"); 
    }

    Lista* elem_pop = pop(&lista3);
    if (elem_pop != NULL) {
        printf("Elemento removido: %d\n", elem_pop->info);
        free(elem_pop); // Lembre-se de liberar a memória do nó removido
    } else {
        printf("A lista está vazia, nenhum elemento removido.\n");
    }

    lista3 = pop(&lista3);

    printSet(lista3);

    printf("\n");

    clearSet(lista3);

    printf("\n");
    
    printSet(lista3);

    return 0;
}