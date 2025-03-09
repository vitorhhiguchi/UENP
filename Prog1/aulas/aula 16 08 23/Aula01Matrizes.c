// Aula de matriz
#include <stdio.h>
int main(){

    float alunosENotas [5][5]; // Declaração de uma matriz
    /* Tipo de variável nome_da_variavel [quantidade de linhas] [quant de colunas]
    Só podemos armazenar tamanhos inteiros */

    int i, j, lin, colun;

    // Exemplo de como fazer uma definição de tamanho de matriz digitado por um usuário
    printf("Entre com as dimensões da matriz: ");
    scanf("%d%d", &lin, &colun); 
    // Definindo uma matriz com os valores recebidos
    int matriz[lin][colun];

    return 0;
}