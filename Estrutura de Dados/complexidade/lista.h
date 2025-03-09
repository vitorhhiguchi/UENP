struct Lista {
    int data;
    struct Lista* prox;
};
typedef struct Lista Lista;

Lista* criaLista();
Lista* criaNoLista(Lista* list, int val);
Lista* insereOrdenado(Lista* list, int val);
void freeLista(Lista* list);
