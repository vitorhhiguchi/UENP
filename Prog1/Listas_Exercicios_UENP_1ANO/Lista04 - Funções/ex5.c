/*5. Implemente uma função que receba como parâmetro 2 notas e uma opção correspondendo
ao cálculo da média. Caso a opção seja a letra “a”, deve ser calculada a média aritmética;
caso a opção seja a letra “p”, deve ser calculada a média ponderada (pesos 3 e 2); caso a
opção seja a letra “h”, deve ser calculada a média harmônica. Retorne a média devidamente
calculada para o programa principal. */
#include <stdio.h>
int main(){
    float nota1, nota2, media; 
    char tipoMedia;  
    float mediaNotas(float n1, float n2, char tipoDeMedia);  // Declaração da função

    printf("Digite suas notas e tipo de media: ");  // Mostrando mensagem na tela
    scanf("%f%f %c", &nota1, &nota2, &tipoMedia); // Armazenando os valores de entradas nessas variáveis

    media = mediaNotas(nota1, nota2, tipoMedia); // Armazenando o valor quando chama a função

    printf("A media das notas eh de: %.2f", media); // Mostrando para o usuário o cálculo da média
    return 0;
}

float mediaNotas(float n1, float n2, char tipoDeMedia){  // Função que calcula 3 tipos de médias com os valores informados
    float mediaAritmetica = 0, mediaPonderada = 0, mediaHarmonica = 0; // Preciso fazer um return em cada switch case, pelo fato que tem 3 contas diferentes

    switch (tipoDeMedia){ // Escolhas para fazer qual operação de média
    case 'A':  // Case A, calculo de média aritmética
    case 'a':
        mediaAritmetica = (n1 + n2) / 2; // Cálculo da média aritmética
        return mediaAritmetica; // Retornando o valor calculado
        break;
    
    case 'P':  // Case p, calcula a média Ponderada
    case 'p':
        mediaPonderada = ((n1 * 3) + (n2 * 2)) / (3 + 2); // Cálculo da média Ponderada 
        return mediaPonderada;  //  Retorna o valor calculado
        break;

    case 'H': // Case H, calcula a média harmônica
    case 'h':
        mediaHarmonica = 2 / ((1/n1) + (1/n2));  // Cálculo da média Harmônica
        return mediaHarmonica; // Retorna o valor calculado
        break;

    default: 
        return 0;
        break;

    
    }
}