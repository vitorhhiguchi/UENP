#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(){

    float raio, perimetro, area;

    printf("Escreva o valor de um raio de circulo: ");   
    scanf("%f", &raio);

    perimetro = 2 * 3.14 * raio;      // o valor de 3.14 eu tirei do número aproximado de pi, que faz parte da fórmula
    area = 3.14 * (pow(raio,2)); 

    printf("O perimetro do circulo com o raio informado e: %.2f \n", perimetro);
    printf("A area e: %.2f \n", area);

    return 0;
}

/*Professor, eu tentei colocar aquela biblioteca <locale.h> que o senhor indicou na aula, porém quando utilizo os acentos nas palavras elas bugam. 
Talvez eu tenha entendido errado como funciona, mas não era que n bugava as palavras quando utiliza essa biblioteca ?*/

//Básicamente, o programa está lendo o valor de um raio dado a ele, e então ele calcula área do circulo e o perimetro com esse valor.

