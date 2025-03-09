#include <stdio.h>
#include <stdlib.h>

struct noArv {
    char info;
    NoArv* esq;
    NoArv* dir;
}

typedef struct noArv NoArv;

NoArv* arv_criavazia(void);
NoArv* arv_cria(char c, NoArv* esquerda, NoArv* direita);
NoArv* arv_libera(NoArv* arv);
int arv_vazia(NoArv* arv);
int arv_pertence (NoArv* arv, char c);
void arv_imprime (NoArv* arv);

NoArv* arv_criavazia(void){
    return NULL;
}

NoArv* arv_cria (char c, NoArv* esquerda, NoArv* direita){
    // Criamos uma variavel temporaria para ser o nó
    NoArv* p = (NoArv*) malloc(sizeof(NoArv));
    
    // Se P for NULL saimos da função
    if(p==NULL) exit(1);

    // Definimos o valor de P, de acordo com os valores passado para a função
    p->info = c;
    p->esq = esquerda;
    p->dir = direita;

    // retornamos o nó P, para ser inserido na arvore
    return p;
}

NoArv* arv_libera(NoArv* arv){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }

    return NULL;
}