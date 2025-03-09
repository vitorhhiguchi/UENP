#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void menu(){
    Lista *lst = CriaLista();
    Medicamento *med = NULL, medicamentotemp;
    char info[20];
    FILE *arq_entrada = fopen("entrada.txt", "r");
    FILE *arq_saida = fopen("saida.txt", "w");

    //Verificando se o arquivo existe
    if(arq_entrada == NULL){
        printf("O arquivo entrada.txt nao existe!\n");
        exit(1);
    }

    if(fgetc(arq_entrada) == EOF){
        printf("O arquivo esta vazio!");
        exit(1);
    }

    rewind(arq_entrada); // Fazer o ponteiro que passou o arquivo inteiro voltar ao inicio

    while(1){
         if(feof(arq_entrada)){ //quando chega no fim do arquivo para o loop
            break;
        }

        fscanf(arq_entrada, "%s", info); //le a informacao

        if(!strcmp("MEDICAMENTO", info)){ //registra medicamento

            fscanf(arq_entrada, "%s %d %f %d %d %d", medicamentotemp.nome, &medicamentotemp.codigo, &medicamentotemp.valor, &medicamentotemp.data[0], &medicamentotemp.data[1], &medicamentotemp.data[2]);
            med = CriaMedicamento(medicamentotemp.nome, medicamentotemp.codigo, medicamentotemp.valor, medicamentotemp.data);
            lst = InsereListaMedicamento(arq_saida, lst, med);

        }

        else if(!strcmp("RETIRA", info)){//retira medicamento

            fscanf(arq_entrada, "%d", &medicamentotemp.codigo);
            lst = RetiraListaMedicamento (arq_saida , lst , medicamentotemp.codigo);

        }

        else if(!strcmp("IMPRIME_LISTA", info)){//imprime lista de medicamentos no txt
            ImprimeListaMedicamentos (arq_saida, lst);
        }

        else if(!strcmp("ATUALIZA_PRECO", info)){//atualiza preco do medicamento

            fscanf(arq_entrada, "%d %f", &medicamentotemp.codigo, &medicamentotemp.valor);
            AtualizaPreco(arq_saida, lst, medicamentotemp.codigo, medicamentotemp.valor);

        }

        else if (!strcmp("VERIFICA_VALIDADE", info)){//verifica quais medicamenstos estao vencidos
            fscanf(arq_entrada, "%d %d %d", &medicamentotemp.data[0], &medicamentotemp.data[1], &medicamentotemp.data[2]);
            VerificaListaValidade(arq_saida , lst , medicamentotemp.data);
        }

        else if(!strcmp("VERIFICA_LISTA", info)){//registra se certo medicamento esta na lista
            fscanf(arq_entrada, "%d", &medicamentotemp.codigo);
            VerificaListaMedicamento(arq_saida, lst, medicamentotemp.codigo);
        }

        else if (!strcmp("ORDENA_LISTA_VALOR", info)){//ordena lista pelo valor
            lst = OrdenaListaValor (lst);
        }

        else if (!strcmp("ORDENA_LISTA_VALIDADE", info)){//ordena lista pela validade
            lst = OrdenaListaVencimento (lst);
        }

        else if(!strcmp("FIM", info)){ //fim do arquivo, acaba o programa
            fim(lst);
        }

        else{
            fprintf(arq_saida, "INFORMACAO NAO CONHECIDA\n"); //caso a informacao nao seja reconhecida
        }
    }
    
    fclose(arq_entrada);
    fclose(arq_saida);

}



// Cria um novo medicamento
Medicamento* CriaMedicamento(char* nome, int codigo, float valor, int* data_de_validade){
    Medicamento *novo = (Medicamento*) malloc(sizeof(Medicamento));
    
    strcpy(novo->nome, nome); // Copiando o nome lido para o medicamento
    novo->codigo = codigo;
    novo->valor = valor;
    for(int i=0; i<3; i++){
        novo->data[i] = data_de_validade[i];
    }

    return novo;
}

// Criar a lista para armazenar os medicamentps
Lista* CriaLista(){
    return NULL;
}

// Inserir medicamento na lista
Lista* InsereListaMedicamento(FILE* fp, Lista* l, Medicamento* m){
    fprintf(fp, "MEDICAMENTO %s %d ADICIONADO \n", m->nome, m->codigo);

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->m = m;
    novo->prox = l;
    return novo;
}

// Retirar um medicamento de uma determinada lista
Lista* RetiraListaMedicamento(FILE* fp, Lista* l, int id_medicamneto){
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->m->codigo != id_medicamneto){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO\n");
        return l;
    }

    if(ant == NULL){
        l = p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    fprintf(fp, "MEDICAMENTO %s %d, RETIRADO COM SUCESSO\n", p->m->nome, id_medicamneto);

    free(p->m);
    free(p);
    return l;
}

//Atualiza o preço do medicamneto
void AtualizaPreco (FILE *fp, Lista *p, int id_medicamento, float preco){//atualiza preco do medicamento
    int encontrou = 0;
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento){
            aux->m->valor = preco;
            fprintf(fp, "PRECO ATUALIZADO %s %d %.2f\n", aux->m->nome, aux->m->codigo, aux->m->valor);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        fprintf(fp, "MEDICAMENTO ATUALIZAR PRECO NAO ENCONTRADO\n");
    }
}

// Verifica se um medicamento esta presente em uma determinada lista
int VerificaListaMedicamento(FILE* fp, Lista* p, int id_medicamento){
    int encontrou = 0; // Variavel de parametro para saber se foi encontrado o medicamento ou não
    // Conferir se é encontrado o codigo do medicamento!
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->codigo == id_medicamento){
            fprintf(fp, "MEDICAMENTO ENCONTRADO %s %d %.2f %d %d %d", aux->m->nome, aux->m->codigo, aux->m->valor, aux->m->data[0], aux->m->data[1], aux->m->data[2]); // Passando pro arquivo
            encontrou = 1;
        }
    }
    if(!encontrou){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    }
}

// Verifica se um medicamento está vencido na lista 
int VerificaListaValidade(FILE* fp, Lista* p, int* data){
    int encontrou = 0;
    for(Lista *aux = p; aux != NULL; aux = aux->prox){
        if(aux->m->data[2] < data[2]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
        if(aux->m->data[2] == data[2] && aux->m->data[1] < data[1]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
        if(aux->m->data[2] == data[2] && aux->m->data[1] == data[1] && aux->m->data[0] < data[0]){
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", aux->m->nome, aux->m->codigo);
            encontrou = 1;
        }
    }
    if(encontrou == 0){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    }
}

// Imprime todos os medicamentos
void ImprimeListaMedicamentos(FILE* fp, Lista* p){
    Lista *l;
    for(l = p; l != NULL; l = l->prox){
        fprintf(fp, "%s %d %.1f %d %d %d\n", l->m->nome, l->m->codigo, l->m->valor, l->m->data[0], l->m->data[1], l->m->data[2]);
    }
}

// Ordena a lista pelo valor do medicamento
// Lista* OrdenaListaValor(Lista* p){
//     for(Lista *i = p; i != NULL; i = i->prox){
//         for(Lista *j = p; j != NULL; j = j->prox){
//             if(i->m->valor < j->m->valor){
//                 Medicamento *aux = i->m;
//                 i->m = j->m;
//                 j->m = aux;
//             }
//         }
//     }
//     return p;
// }

// SelectionSort
// Lista* OrdenaListaValor(Lista* p) {
//     for (Lista *i = p; i != NULL; i = i->prox) {
//         Lista *min = i;
//         for (Lista *j = i->prox; j != NULL; j = j->prox) {
//             if (j->m->valor < min->m->valor) {
//                 min = j;
//             }
//         }
//         if (min != i) {
//             Medicamento *aux = i->m;
//             i->m = min->m;
//             min->m = aux;
//         }
//     }
//     return p;
// }

//Bubblesort
Lista* OrdenaListaValor(Lista* p) {
    if (p == NULL) return p;

    int trocou;
    do {
        trocou = 0;
        Lista *atual = p;
        while (atual->prox != NULL) {
            if (atual->m->valor > atual->prox->m->valor) {
                // Troca os medicamentos
                Medicamento *aux = atual->m;
                atual->m = atual->prox->m;
                atual->prox->m = aux;
                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
    
    return p;
}


// Ordena a lista pela data de validade
Lista* OrdenaListaVencimento(Lista* p){
    for(Lista *i = p; i != NULL; i = i->prox){
        for(Lista *j = p; j != NULL; j = j->prox){
            if(i->m->data[2] < j->m->data[2]){
                Medicamento *aux = i->m;
                i->m = j->m;
                j->m = aux;       
            }
            if(i->m->data[2] == j->m->data[2] && i->m->data[1] < j->m->data[1]){
                Medicamento *aux = i->m;
                i->m = j->m;
                j->m = aux;
            }
            if(i->m->data[2] == j->m->data[2] && i->m->data[1] == j->m->data[1] && i->m->data[0] < j->m->data[0]){
                Medicamento *aux = i->m;
                i->m = j->m;
                j->m = aux;
            }
        }
    }
    return p;
}

void fim(Lista *l){
    Lista *aux;
    Lista *p = l;
    while(p != NULL){
        aux = p->prox; // guarda referencia para o proximo elemento
        free(p->m); //libera memoria apontada para medicamentos
        free(p); // libera memoria apontada para p
        p = aux; // faz aponta p para o proximo
    }
    exit(0);
}