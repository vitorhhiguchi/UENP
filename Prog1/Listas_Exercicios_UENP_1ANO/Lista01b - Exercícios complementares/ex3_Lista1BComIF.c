#include <stdio.h>
#include <math.h>
int main(){

    float massa, altura, IMC; 

    printf("Escreva sua altura e peso: ");
    scanf("%f%f", &altura, &massa);

    IMC = massa / (pow(altura, 2));

    if (IMC > 18.5){

        printf("O IMC da pessoa com as informacoes dada e de: %.2f \n", IMC);
        printf("O IMC ESTA INDICANDO QUE A PESSOA ESTA COM BAIXO PESO %.2F", IMC);

    }  

    else if (IMC >= 18.5 && IMC >= 24.9){

        printf("O IMC da pessoa com as informacoes dada e de: %.2f \n", IMC);
        printf("O IMC ESTA INDICANDO QUE A PESSOA ESTA COM PESO NORMAL %.2F", IMC);

    }

    else if (IMC >= 25 && IMC >= 29.9){

        printf("O IMC da pessoa com as informacoes dada e de: %.2f \n", IMC);
        printf("O IMC ESTA INDICANDO QUE A PESSOA ESTA COM EXCESSO DE PESO %.2F", IMC);

    }

    else if (IMC > 30){

        printf("O IMC da pessoa com as informacoes dada e de: %.2f \n", IMC);
        printf("O IMC ESTA INDICANDO QUE A PESSOA ESTA COM OBESIDADE %.2F", IMC);

    }

    else{

       printf("O IMC da pessoa com as informacoes dada e de: %.2f \n", IMC); 
       printf("O IMC ESTA INDICANDO QUE A PESSOA ESTA COM OBESIDADE EXTREMA %.2F", IMC);

    }

    return 0;
}

//basicamente o codigo esta lendo sua altura e peso, e então calcula o IMC. E tambem fala se seu IMC esta com numeros bons ou não