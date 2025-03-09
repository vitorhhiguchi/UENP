typedef struct medicamento Medicamento;

typedef struct arvore Arvore;

// Inicializar o programa
void menu();

// Cria a árvore
Arvore* CriaArvore();

// Cria um medicamento
Medicamento* CriaMedicamento(char* nome , int codigo , float valor , int* data_de_validade);

// Insere um medicamento na árvore
Arvore* InsereArvoreMedicamento(FILE* fp, Arvore* arv, Medicamento* );

// Retira o medicamento da árvore
Arvore* RetiraArvoreMedicamento(FILE* fp, Arvore* arv, int id_medicamento);

// Atualizar o preço do produto
Arvore* AtualizaPreco (FILE *fp, Arvore *arv, int id_medicamento, float preco); 

// Verifica se há o medicamento determinado
int VerificaArvoreMedicamento(FILE* fp, Arvore* arv, int id_medicamento);

// Verifica a validade do medicamento
void VerificaArvoreValidade(FILE* fp, Arvore* arv, int* data, int* validade);

// Imprime em ordem todos os medicamento
void imprimeArvoreMedicamentos(FILE* fp, Arvore* arv);

/* libera memoria */
void fim(Arvore *arv);