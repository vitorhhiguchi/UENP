/* 3. Faça um programa para calcular as raízes da equação de 2o grau. O programa recebe como entrada os números a, b, c, que correspondem aos coeficientes da equação de segundo grau
(ax2 + bx + c = 0). Em seguida, o programa deve mostrar as raízes da equação. Caso as raízes não existam, uma mensagem deve ser exibida (por exemplo, “Não existem raízes
reais”). Caso a equação não seja de segundo grau, uma mensagem também deve ser exibida (por exemplo, “Não é uma equação de segundo grau”).
Para isso, implemente funções para calcular e retornar o valor de delta e para calcular e retornar os valores das raízes x1 e x2 da equação. */
#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, delta = 0;  // declarando as varievareis, coeficiente da equação e o valor de delta
    float calcularDelta(float coefA, float coefB, float coefC); // declaração da função para calcular delta
    float calcularRaiz1(float coefB, float coefA, float delta); // declaração da função de calcular a raiz 1 da equação
    float calcularRaiz2(float coefB, float coefA, float delta); // delcaração da função de calcular a raiz 2 da equação

    // Texto pendi para digitar os coeficientes e armazenando eles
    printf("Digite os coeficientes do segundo grau: ");
    scanf("%f%f%f", &a, &b, &c);
    // Condição para ver se os valores dados realmente é uma equação de segundo grau
    if (a == 0){
        printf("Nao eh uma equacao de segundo grau."); // Caso o "a" = 0, ele entra no if, e mostra essa mensagem
        return 0;
    }
    // Armazenando o valor do calculo quando se chama a função
    delta = calcularDelta(a, b, c);
    // Comparação para ver quantas raízes tem, e mostrar para o usuário as raízes
    if (delta > 0){
        printf("Existe duas raizes reais\n");
        printf("X1 = %.2f e X2 = %.2f", calcularRaiz1(b, a, delta), calcularRaiz2(b, a, delta));
    }
    else if (delta == 0){
        printf("Ha apenas uma raiz real\n");
        printf("x1 = %.2f", calcularRaiz1(b, a, delta));
    }
    else{
        printf("Nao ha raizes reais\n");

    }

    return 0;
}
// Função que calcula o valor de delta
float calcularDelta(float coefA, float coefB, float coefC){
    float delta;
    delta = sqrt(pow(coefB, 2) - 4 * coefA * coefC); 
    return delta;
}   
// Função que calcula X' ou X1
float calcularRaiz1(float coefB, float coefA, float delta){
    float bhaskaraX1;
    bhaskaraX1 = ((-1 * coefB) + delta) / (2 * coefA);
    return bhaskaraX1;
}
// Função que calcula X" ou X2
float calcularRaiz2(float coefB, float coefA, float delta){
    float bhaskaraX2;
    bhaskaraX2 = ((-1 * coefB) - delta) / (2 * coefA);
    return bhaskaraX2;
}