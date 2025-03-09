#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

struct medicamento {
    char nome[20];
    int codigo;
    float valor;
    int data[3];
};

struct arvore {
    Medicamento* info;
    Arvore* esquerda;
    Arvore* direita;
};

void menu(){
    Arvore* arv = CriaArvore();
    Medicamento *med = NULL;
    char info[20];
    FILE *arq_entrada = fopen("entrada.txt", "r");
    FILE *arq_saida = fopen("saida.txt", "w");

    char nome[20];
    int codigo;
    float valor;
    int data[3];

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
            fscanf(arq_entrada, "%s %d %f %d %d %d", nome, &codigo, &valor, &data[0], &data[1], &data[2]);
            med = CriaMedicamento(nome, codigo, valor, data);
            arv = InsereArvoreMedicamento(arq_saida, arv, med);
        }

        else if(!strcmp("RETIRA", info)){//retira medicamento
            fscanf(arq_entrada, "%d", &codigo);
            arv = RetiraArvoreMedicamento(arq_saida, arv, codigo);
        }

        else if(!strcmp("IMPRIME_ARVORE", info)){//imprime arvore de medicamentos no txt
            imprimeArvoreMedicamentos(arq_saida, arv);
        }

        else if(!strcmp("ATUALIZA_PRECO", info)){//atualiza preco do medicamento
            fscanf(arq_entrada, "%d %f", &codigo, &valor);
            AtualizaPreco(arq_saida, arv, codigo, valor);
        }

        else if (!strcmp("VERIFICA_VALIDADE", info)){//verifica quais medicamenstos estao vencidos
            fscanf(arq_entrada, "%d %d %d", &data[0], &data[1], &data[2]);
            int encontrou = 0;
            VerificaArvoreValidade(arq_saida, arv, data, &encontrou);
            if(encontrou == 0){
              fprintf(arq_saida, "MEDICAMENTO VENCIDO NAO ENCONTRADO NA ARVORE\n");
            }
        }

        else if(!strcmp("VERIFICA_ARVORE", info)){//registra se certo medicamento esta na arvore
            fscanf(arq_entrada, "%d", &codigo);
            VerificaArvoreMedicamento(arq_saida, arv, codigo);
        }

        else if(!strcmp("FIM", info)){ //fim do arquivo, acaba o programa
            fim(arv);
        }

        else{
            fprintf(arq_saida, "INFORMACAO NAO CONHECIDA\n"); //caso a informacao nao seja reconhecida
        }
    }
    
    fclose(arq_entrada);
    fclose(arq_saida);
}


Arvore* CriaArvore(){
    return NULL;
}


Medicamento* CriaMedicamento(char* nome , int codigo , float valor , int* data_de_validade)
{   
    Medicamento *novo = (Medicamento*) malloc(sizeof(Medicamento));
    
    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->valor = valor;
    for(int i=0; i<3; i++){
        novo->data[i] = data_de_validade[i];
    }

    return novo;
}

Arvore* InsereArvoreMedicamento(FILE* fp, Arvore* arv, Medicamento* med)
{
    if (arv == NULL) {
        arv = (Arvore*) malloc(sizeof(Arvore));
        arv->info = med;
        arv->esquerda = arv->direita = NULL; // Mesma coisa de escrever arv->esquerda = NULL; e arv->direita = NULL;

        fprintf(fp, "MEDICAMENTO %s %d ADICIONADO \n", med->nome, med->codigo);
    }else if(med->codigo < arv->info->codigo){
        arv->esquerda = InsereArvoreMedicamento(fp, arv->esquerda, med);
    } else{  // med >= arv->info
        arv->direita = InsereArvoreMedicamento(fp, arv->direita, med);
    }

    return arv;
}

Arvore* RetiraArvoreMedicamento(FILE* fp, Arvore* arv, int id_medicamento)
{
    if(arv == NULL){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO NA ARVORE\n");
        return NULL;
    } else if(arv->info->codigo > id_medicamento){
        arv->esquerda = RetiraArvoreMedicamento(fp, arv->esquerda, id_medicamento);
    } else if(arv->info->codigo < id_medicamento){
        arv->direita = RetiraArvoreMedicamento(fp, arv->direita, id_medicamento);
    } else{
        if(arv->esquerda == NULL && arv->direita == NULL){ // nó sem filhos
            fprintf(fp, "MEDICAMENTO %s %d, RETIRADO COM SUCESSO\n", arv->info->nome, id_medicamento);
            free(arv->info);
            free(arv);
            arv = NULL;
        }else if(arv->esquerda == NULL){ // nó só tem filho à direita
            fprintf(fp, "MEDICAMENTO %s %d, RETIRADO COM SUCESSO\n", arv->info->nome, id_medicamento);
            Arvore* t = arv;
            arv = arv->direita;
            free(t->info);
            free(t);
        }else if(arv->direita == NULL){ //nó só tem filho à esquerda
            fprintf(fp, "MEDICAMENTO %s %d, RETIRADO COM SUCESSO\n", arv->info->nome, id_medicamento);
            Arvore* t = arv;
            arv = arv->esquerda;
            free(t->info);
            free(t);
        }else { // nó tem os dois filhos(pior caso)
            Arvore* f = arv->esquerda;
            while(f->direita != NULL){
                f = f->direita;
            }

            Medicamento* med_t = arv->info;
            arv->info = f->info; // trocando as infos
            f->info = med_t;
            arv->esquerda = RetiraArvoreMedicamento(fp, arv->esquerda, f->info->codigo);
        }
    }
    
    return arv;
}

// Atualiza preco do medicamento
Arvore* AtualizaPreco (FILE *fp, Arvore *arv, int id_medicamento, float preco){
    if(arv == NULL){
        fprintf(fp, "MEDICAMENTO ATUALIZAR PRECO NAO ENCONTRADO\n");
        return NULL;
    }else if(arv->info->codigo > id_medicamento){
        arv->esquerda = AtualizaPreco(fp, arv->esquerda, id_medicamento, preco);
    }else if(arv->info->codigo < id_medicamento){
        arv->direita = AtualizaPreco(fp, arv->direita, id_medicamento, preco);
    }else {
        arv->info->valor = preco;
        fprintf(fp, "PRECO ATUALIZADO %s %d %.2f\n", arv->info->nome, arv->info->codigo, arv->info->valor);
    }
    return arv;
}

int VerificaArvoreMedicamento(FILE* fp, Arvore* arv, int id_medicamento)
{
    if(arv == NULL){
        fprintf(fp, "MEDICAMENTO NAO ENCONTRADO NA ARVORE\n");
        return NULL;
    }else if(arv->info->codigo > id_medicamento){
        return VerificaArvoreMedicamento(fp, arv->esquerda, id_medicamento);
    } else if(arv->info->codigo < id_medicamento){
        return VerificaArvoreMedicamento(fp, arv->direita, id_medicamento);
    }else {
        fprintf(fp, "MEDICAMENTO ENCONTRADO %s %d %.2f %d %d %d", arv->info->nome, arv->info->codigo, arv->info->valor, arv->info->data[0], arv->info->data[1], arv->info->data[2]); // Passando pro arquivo
        return arv;
    }
}

void VerificaArvoreValidade(FILE* fp, Arvore* arv, int* data, int* validade)
{
    if(arv != NULL){
        if(data[2] > arv->info->data[2] || 
        (data[2] >= arv->info->data[2] && data[1] > arv->info->data[1]) ||
        (data[2] >= arv->info->data[2] && data[1] >= arv->info->data[1] && data[0] > arv->info->data[0])){ // Verificando o ano
            fprintf(fp,"MEDICAMENTO %s %d VENCIDO\n",arv->info->nome, arv->info->codigo);
            *validade = 1;
        }
        VerificaArvoreValidade(fp, arv->esquerda, data, validade); 
        VerificaArvoreValidade(fp, arv->direita, data, validade);
    }
}

void imprimeArvoreMedicamentos(FILE* fp, Arvore* arv)
{
    if(arv != NULL){
        imprimeArvoreMedicamentos(fp, arv->esquerda);
        fprintf(fp, "%s %d %.1f %d %d %d\n", arv->info->nome, arv->info->codigo, arv->info->valor, arv->info->data[0], arv->info->data[1], arv->info->data[2]);
        imprimeArvoreMedicamentos(fp, arv->direita);
    }
}

void fim(Arvore *arv){
    if (arv != NULL) {
        // percorre a arvore para liberar a memoria
        fim(arv->esquerda);
        fim(arv->direita);

        // Libera o medicamento associado ao nó
        free(arv->info);

        // Libera o nó atual
        free(arv);
    }
}