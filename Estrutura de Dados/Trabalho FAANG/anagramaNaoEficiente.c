#include <stdio.h>
#include <string.h>

int verificaAnagrama(char palavra1[], char palavra2[]) {
    int n1 = strlen(palavra1);
    int n2 = strlen(palavra2);
    
    if (n1 != n2) {
        return 0; // Se os tamanhos são diferentes, não são anagramas
    }

    for (int i = 0; i < n1; i++) {
        int encontrou = 0;
        for (int j = 0; j < n2; j++) {
            if (palavra1[i] == palavra2[j]) {
                encontrou = 1;
                palavra2[j] = '*'; // Marca a letra como usada
                break;
            }
        }
        if (!encontrou) {
            return 0; // Se uma letra de palavra1 não está em palavra2
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
