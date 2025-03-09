#include <stdio.h>
int main(){

    char x;

    printf("Digite uma letra: ");
    scanf("%c", &x);

    if (x == 'a'){

        printf("A letra digital eh uma vogal!");

    }

    else if (x == 'e'){

        printf("A letra digitada eh uma vogal!");

    }
    
    else if (x == 'i'){

        printf("A letra digitada eh uma vogal!");

    }

    else if (x == 'o'){

        printf("A letra digitada eh uma vogal!");

    }

    else if (x == 'u'){

        printf("A letra digitada eh uma vogal!");

    }

    else{

        printf("A letra digitada nao eh uma vogal!");

    }

    return 0;
}