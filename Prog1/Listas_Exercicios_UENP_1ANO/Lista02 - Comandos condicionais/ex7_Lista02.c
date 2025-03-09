#include <stdio.h>
int main() {

    float salario, reajuste;
    int codigo;

    printf("Digite o seu salario e seu codigo(cargo): ");
    scanf("%f%d", &salario, &codigo);

    switch(codigo){
        case 1:
            reajuste = salario * 0.1;
            salario = salario + reajuste;
            printf("O senhor(a) eh um vendedor(a) e vai receber um reajuste no valor de R$ %.2f reais, e vai passar a receber R$ %.2f reais.", reajuste, salario);
            break;

        case 2: 
            reajuste = salario * 0.07;
            salario = salario + reajuste;
            printf("O senhor(a) eh um auxiliar de escritorio e vai receber um reajuste no valor de R$ %.2f reais, e vai passar a receber R$ %.2f reais.", reajuste, salario);
            break;

        case 3:
            reajuste = salario * 0.12;
            salario = salario + reajuste;
            printf("O senhor(a) eh um auxiliar de enfermagem e vai receber um reajuste no valor de R$ %.2f reais, e vai passar a receber R$ %.2f reais.", reajuste, salario);
            break;

       case 4:
            reajuste = salario * 0.11;
            salario = salario + reajuste;
            printf("O senhor(a) eh um bibliotecario(a) e vai receber um reajuste no valor de R$ %.2f reais, e vai passar receber R$ %.2f reais.", reajuste, salario);
            break;
        default:
            printf("Cargo desconhecido!");
    }

    return 0;
}