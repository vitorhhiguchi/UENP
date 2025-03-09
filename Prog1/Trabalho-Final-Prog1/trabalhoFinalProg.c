//Alunos Vitor Hiroshi Higuchi e Ozeia Moreira da Rocha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
    int generico;
    char categoria[50];
    char fabricante[50];
} Registro;

//Cadastrar registro utilizando arquivo binario
void cadastrarRegistro(){
    Registro registro;
    FILE *arquivo;
    arquivo = fopen("arquivo.bin", "ab");  // gravação, se nao tiver arquivo ele cria novo
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo \n");
    }else{
        printf("Digite o codigo do registro: ");
        scanf("%d", &registro.codigo);
        // Verificar se o código já existe no arquivo
        if (CodigoJaRegistrado(registro.codigo)) {
            printf("Produto com esse codigo ja existe! Escolha outro codigo.\n");
            fclose(arquivo);
            return;
        }
        printf("Digite o nome: ");
        scanf("%s", &registro.nome);
        printf("Digite o preco: ");
        scanf("%f", &registro.preco);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &registro.estoque);
        printf("Digite se o produto eh generico(1 para sim e 0 para nao): ");
        scanf("%d", &registro.generico);
        if(registro.generico != 1 && registro.generico != 0) {
            printf("Valor invalido \n");
            printf("Digite 1 para sim e 0 para nao: ");
            scanf("%d", &registro.generico);
        }
        printf("Digite a categoria: ");
        scanf("%s", &registro.categoria);
        printf("Digite o fabricante: ");
        scanf("%s", &registro.fabricante);
        fwrite(&registro, sizeof(Registro), 1, arquivo);
        fclose(arquivo);
        setbuf(stdin, NULL);
        printf("Produto cadastrado com sucesso\n");
    }
}

//Consultar registro por codigo
void consultarRegistro(int codigo){
    Registro registro;
    FILE *arquivo;
    arquivo = fopen("arquivo.bin", "rb"); // leitura de arquivo
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo \n");
    }else{
        while(fread(&registro, sizeof(Registro), 1, arquivo)){
            if(registro.codigo == codigo){
                printf("Codigo: %d \n", registro.codigo);
                printf("Nome: %s \n", registro.nome);
                printf("Preco: %.2f \n", registro.preco);
                printf("Estoque: %d \n", registro.estoque);
                printf("Generico: %d \n", registro.generico);
                printf("Categoria: %s \n", registro.categoria);
                printf("Fabricante: %s \n", registro.fabricante);
                fclose(arquivo);
                return;
            }
        }
        printf("Codigo nao encontrado! \n");
    }
    fclose(arquivo);
}

//Alterar registro por codigo
void alterarRegistro(int codigo){
    Registro registro;
    FILE *arquivo;
    arquivo = fopen("arquivo.bin", "rb+"); // Abre o arquivo para leitura e gravação
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo \n");
    }else{
        while(fread(&registro, sizeof(Registro), 1, arquivo)){
            if(registro.codigo == codigo){
                printf("Digite o codigo desse registro: ");
                scanf("%d", &registro.codigo);
                printf("-----NOVO PRODUTO-----\n");
                printf("Digite o nome: ");
                scanf("%s", &registro.nome);
                printf("Digite o preco: ");
                scanf("%f", &registro.preco);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &registro.estoque);
                printf("Digite o generico(1 para sim e 0 para nao): ");
                scanf("%d", &registro.generico);
                if(registro.generico != 1 && registro.generico != 0) {
                    printf("Valor invalido \n");
                    printf("Digite 1 para sim e 0 para nao: ");
                    scanf("%d", &registro.generico);
                }
                printf("Digite a categoria: ");
                scanf("%s", &registro.categoria);
                printf("Digite o fabricante: ");
                scanf("%s", &registro.fabricante);
                fseek(arquivo, -sizeof(Registro), SEEK_CUR);
                fwrite(&registro, sizeof(Registro), 1, arquivo);
                fclose(arquivo);
                printf("Produto alterado com sucesso\n");
                return;
            }
        }
    }
    printf("Codigo de produto nao encontrado\n");
    fclose(arquivo);
}


//Remover registro por codigo
void removerRegistro(int codigo){
    Registro registro;
    FILE *arquivo;
    FILE *arquivoTemp;
    arquivo = fopen("arquivo.bin", "rb");  // Abre o arquivo para leitura
    arquivoTemp = fopen("arquivoTemp.bin", "wb"); // Abre o arquivo para gravacação, e como ele n existe ele é criado
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo \n");
    }else{
        while(fread(&registro, sizeof(Registro), 1, arquivo)){
            if(registro.codigo != codigo){
                fwrite(&registro, sizeof(Registro), 1, arquivoTemp);
            }
        }
        fclose(arquivo);
        fclose(arquivoTemp);
        remove("arquivo.bin");
        rename("arquivoTemp.bin", "arquivo.bin");
        printf("Produto Removido com sucesso\n");
    }
}

//Exibir todos os registros
void exibirRegistros(){
    Registro registro;
    FILE *arquivo;
    arquivo = fopen("arquivo.bin", "rb"); // arquivo para leitura
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo \n"); // Abre o arquivo
    }else{
        fseek(arquivo, 0, SEEK_END); // Move o ponteiro para o final do arquivo
        int size = ftell(arquivo); // Obtém a posição atual do ponteiro, que é o tamanho do arquivo
        fseek(arquivo, 0, SEEK_SET); // Move o ponteiro de volta para o início do arquivo

        if(size == 0){
            printf("Nao ha registros ainda! \n");
        }else{
            while(fread(&registro, sizeof(Registro), 1, arquivo)){
                printf("Codigo: %d \n", registro.codigo);
                printf("Nome: %s \n", registro.nome);
                printf("Preco: %.2f \n", registro.preco);
                printf("Estoque: %d \n", registro.estoque);
                printf("Generico: %d \n", registro.generico);
                printf("Categoria: %s \n", registro.categoria);
                printf("Fabricante: %s \n", registro.fabricante);
                printf("\n");
            }
        }
        fclose(arquivo);
    }
}

// Conferir se ja foi registrado com esse codigo
int CodigoJaRegistrado(int codigo) {
    Registro registro;
    FILE *arquivo = fopen("arquivo.bin", "rb"); // Arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fread(&registro, sizeof(Registro), 1, arquivo)) {
        if (registro.codigo == codigo) {
            fclose(arquivo);
            return 1; // Código encontrado, já existe no arquivo
        }
    }

    fclose(arquivo);
    return 0; // Código não encontrado, pode ser usado
}

//Menu
void menu(){
    int opcao = 0;
    int codigo;
    while(1){
        switch(opcao){
            case 0:
                system("cls");
                printf("=============================================\n");
                printf("               MENU PRINCIPAL\n");
                printf("=============================================\n");
                printf("1 - Cadastrar registro\n");
                printf("2 - Consultar registro\n");
                printf("3 - Alterar registro\n");
                printf("4 - Remover registro\n");
                printf("5 - Exibir todos os registros\n");
                printf("6 - Sair\n");
                printf("=============================================\n");
                printf("Digite a opcao desejada: ");
                scanf("%d", &opcao);
                break;
            case 1:
                system("cls");
                cadastrarRegistro();
                system("pause");
                opcao = 0;
                break;
            case 2:
                system("cls");
                printf("Digite o codigo do registro que deseja consultar: ");
                scanf("%d", &codigo);
                consultarRegistro(codigo);
                system("pause");
                opcao = 0;
                break;
            case 3:
                system("cls");
                printf("Digite o codigo do registro que deseja alterar: ");
                scanf("%d", &codigo);
                alterarRegistro(codigo);
                system("pause");
                opcao = 0;
                break;
            case 4:
                system("cls");
                printf("Digite o codigo do registro que deseja remover: ");
                scanf("%d", &codigo);
                removerRegistro(codigo);
                system("pause");
                opcao = 0;
                break;
            case 5:
                system("cls");
                exibirRegistros();
                system("pause");
                opcao = 0;
                break;
            case 6:
                printf("Finalizando registros... \n");
                exit(0);
            default:
                printf("Opcao invalida \n");
                system("pause");
                opcao = 0;
                break;
        }
    }
}

int main(){
    menu();
    return 0;
}