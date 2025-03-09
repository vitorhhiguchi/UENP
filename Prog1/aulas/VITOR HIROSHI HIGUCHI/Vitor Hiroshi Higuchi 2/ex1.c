#include <stdio.h>
#include <string.h>
#define TAM 255
int main(){

    char string[TAM+1];
    int palavras;
    float porcentagemVogal;

    int totalDePalavras(char palavras[]);
    void ultimaPalavra(char palavras[]);
    float porcentagemDeVogais(char palavras[]);
    void mostrandoCaracter(char palavras[]);
    char criptografia(char palavras[]);


    printf("Digite uma string de no maximo 255 caracteres: ");
    fgets(string, TAM+1, stdin);
    puts(string);

    palavras = totalDePalavras(string);
    printf("O total de palavras na string eh de: %d\n", palavras);
    ultimaPalavra(string);
    porcentagemVogal = porcentagemDeVogais(string);
    printf("A porcentagem de vogais na string eh de: %.2f\n", porcentagemVogal);
    printf("A palavra criptografada: %c", criptografia(string));

    return 0;
}

/* Não consegui fazer a lógica completa, pelo fato que a ultima ocupação da string é o \0, então ele conta como um espaço tbm,
porém não consegui pensar em outra maneira de fazer o ex*/

int totalDePalavras(char palavras[]){
    int i, total=0;

    for(i=0; i < TAM; i++){
        if(palavras[i] == ' '){
            total++;
        }
    }

    total -= 1;

    return total;
}

// Para fazer essa função, n lembrava como calcular o tamanho da minha string, portanto importei a biblioteca string.h apenas para essa função
void ultimaPalavra(char palavras[]){
    int i, j=0, tamanho;

    tamanho = len(palavras[TAM]);
    char ultimPalavra[tamanho];

    for(i=tamanho-1; i>0; i--){
        if(palavras[i] == ' '){
            break;
        }
        else{
            ultimPalavra[j] = palavras[i];
        }
        j++;
    }

    puts(ultimPalavra);
    // Eu percebi que o print da palavra vai sair ao contrario, porém n conseugi pensar uma maneira de inverter a palavra
}

float porcentagemDeVogais(char palavras[]){
    float vog=0, cons=0, porcentagemVog=0, total;
    int i, espacos=0;

    for(i=0; i> TAM; i++){
        if(palavras[i] == ' '){
            espacos++;
        }

        if(palavras[i] == 'a' || palavras[i] == 'A' || palavras[i] == 'e' || palavras[i] == 'E' || palavras[i] == 'i' || palavras[i] == 'I' 
        || palavras[i] == 'o' || palavras[i] == 'O' || palavras[i] == 'u' || palavras[i] == 'U'){
            vog++;
        }
        else{
            cons++;
        }
    }
    
    cons = cons - (float)espacos;
    total = vog + cons;
    porcentagemVog = vog;
    porcentagemVog = porcentagemVog / total;
    porcentagemVog = porcentagemVog * 100;

    return porcentagemVog;
}

void mostrandoCaracter(char palavras[]){
    int pos1, pos2;

    printf("Digite duas posicoes da string: ");
    setbuf(stdin, NULL);
    scanf("%d%d", &pos1, &pos2);

    printf("O caracter nessas posicoes digitadas sao: %c e %c", palavras[pos1], palavras[pos2]);
}

// Não deu tempo
char criptografia(char palavras[]){
    int n, i;
    char palavraCriptografada[TAM+1];
    printf("Digite um numero para a criptografia da sua string: ");
    scanf("%d", &n);

    for(i=0; i<TAM; i++){
        if()
    }

    return
}
