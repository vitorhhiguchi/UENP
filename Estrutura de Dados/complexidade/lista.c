    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "lista.h"

    Lista* criaLista(){
        return NULL;
    }

    Lista* criaNoLista(Lista* list, int val){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->data = val;
        novo->prox = list;
        return novo;
    }

    Lista* insereOrdenado(Lista* list, int val){
        Lista* novo;
        Lista* ant = NULL;
        Lista* p = list;

        while(p != NULL && p->data > val){
            ant = p;
            p = p->prox;
        }
        novo = (Lista*) malloc(sizeof(Lista));
        novo->data = val;
        if(ant == NULL){
            novo->prox = list;
            list = novo;
        }else {
            novo->prox = ant->prox;
            ant->prox = novo;    
        }
        
        return list;
    }

    void freeLista(Lista* list){
        Lista* t;
        Lista* p = list;
        while(p != NULL){
            t = p->prox;
            free(p);
            p = t;
        }
    }

    int main(){

        Lista* lista1;
        FILE* arquivo;
        arquivo = fopen("arquivo.txt", "w+");
        clock_t start_time, end_time;
        double /*end_time,*/ tempoExecucao;

        if(arquivo == NULL){
            printf("Erro na abertura do arquivo\n");
            exit(1);
        }

        int count = 5000;
        for(int v=1; v<=11; v++){    
            count += 1000;
            for(int j = 0; j<30; j++){
                lista1 = criaLista();
                start_time = clock();
                for(int i=count; i>0; i--){
                    lista1 = insereOrdenado(lista1, i);
                }
                end_time = clock();
                tempoExecucao = (double )(end_time - start_time) / CLOCKS_PER_SEC;
                fprintf(arquivo, "%lf ", tempoExecucao);
                freeLista(lista1);
            }
            fprintf(arquivo, "\n");
        }

        fclose(arquivo);
        printf("Tempo gasto: %lf", tempoExecucao);

        return 0;
    }