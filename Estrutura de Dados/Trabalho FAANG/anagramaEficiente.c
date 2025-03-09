#include <stdio.h>
#include <string.h>

int verificaAnagrama(char palavra1[], char palavra2[]) {
    if (strlen(palavra1) != strlen(palavra2)) {
        return 0; // Tamanhos diferentes não podem ser anagramas
    }

    int contador[256] = {0}; // Assume o conjunto ASCII

    // Conta as letras da primeira palavra
    for (int i = 0; palavra1[i] != '\0'; i++) {
        contador[(unsigned char)palavra1[i]]++;
    }

    // Subtrai as letras da segunda palavra
    for (int i = 0; palavra2[i] != '\0'; i++) {
        contador[(unsigned char)palavra2[i]]--;
        if (contador[(unsigned char)palavra2[i]] < 0) {
            return 0; // Se a contagem ficar negativa, não é um anagrama
        }
    }

    return 1; // São anagramas
}

int main() {
    char palavra1[100], palavra2[100];
    
    printf("Digite a primeira palavra: ");
    scanf("%s", palavra1);
    printf("Digite a segunda palavra: ");
    scanf("%s", palavra2);

    if (verificaAnagrama(palavra1, palavra2)) {
        printf("As palavras sao anagramas.\n");
    } else {
        printf("As palavras nao sao anagramas.\n");
    }

    return 0;
}
