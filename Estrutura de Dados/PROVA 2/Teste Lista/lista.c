#include <stdio.h>
#include <stdlib.h>

void lst_libera (Lista* lst){
    Lista* t;
    Lista* p = lst;
    if(p != NULL){
        t = p->prox;
        free(p)
        p=t;
    }

    lst_libera(p);
}