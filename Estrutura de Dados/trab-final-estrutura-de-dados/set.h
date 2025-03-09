#include <stdbool.h>

typedef struct Lista{
    int info;
    struct Lista* prox;
} Lista;

// Cria uma lista
Lista* createList();

// Adiciona um elemento na lista
void add(Lista** set, int elem);

// Confere se a lista está vazia
bool isEmpty(Lista* set);

// Retorna o tamanho da lista
int len(Lista* set);

// Retorna T se o elemento estiver no conjunto, retorna F caso não estiver
bool isIn(Lista* set, int elem);

// Retorna T se o elemento nao estiver no conjunto, retorna F caso estiver no conjunto
bool isNotIn(Lista* set, int elem);

// Retorna T se a intersecção entre os conjuntos for vazia, F caso contrario
bool isDisjoint(Lista* set1, Lista* set2);

// Remove elemento do conjunto
void removeElem(Lista** set, int elem);

// Remove e retorna um elemento arbitrário (aleatório) do conjunto.
Lista* pop(Lista** set);

// Remove todos os elementos do conjunto
void clearSet(Lista* set);

// Retorna a união dos conjuntos
Lista* unionSet(Lista* set1, Lista* set2); 
// Uma função auxiliar para a função UnionSet
void addUnique(Lista** result, int elem);

// Retorna a intersecção dos conjutos
Lista* intersection(Lista* set1, Lista* set2);

// Retorna um conjunto com os elementos que estão no 1 e não estão no 2
Lista* difference(Lista* set1, Lista* set2);

// Retorna um conjunto com os elementos exclusivos entre os dois conjuntos
Lista* symmetric_difference(Lista* set1, Lista* set2);

// Verifica se o conjunto 1 é um subconjunto de 2
bool isSubSet(Lista* set1, Lista* set2);

// Verifica se o conjunto 1 é um superconjunto de 2
bool isSuperSet(Lista* set1, Lista* set2);

// Faz uma cópia física do conjunto 1 para o 2 (não é para copiar o endereço de um no outro, é para copiar todos os elementos na memória).
void copy(Lista* set1, Lista** set2);

// Imprime o conjunto no terminal
void printSet(Lista* set);