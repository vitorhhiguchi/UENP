#include <stdio.h>
int main(){

    float horas, minutos, segundos;

    printf("Escreva um horario: ");
    scanf("%f", &horas);
    scanf("%f", &minutos);
    scanf("%f", &segundos);

    segundos = segundos;
    segundos = segundos + horas * 3600;  
    segundos = segundos + minutos * 60;
    
    printf("O horario dado em segundos e: %.2f", segundos);

    return 0;
}

/*O algoritmo básicamente está lendo um horário que consta horas, minutos, segundos. Após receber esse valor ele transforma tudo em segundos.*/