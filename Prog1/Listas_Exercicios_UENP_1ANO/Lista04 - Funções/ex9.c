// 9. Faça uma que receba uma determinada hora expressa no formato de horas, minutos e segundos e, em sequida, transforme no valor correspondente em segundos.
#include <stdio.h>
int main(){

    int horas, minutos, segundos;
    int transformarHoras(int hora, int minuto, int segundo);  // Declaração de variável

    printf("Digite o horario expresso em horas, minutos e segundos: "); // Mostra para o usuário a mensagem
    scanf("%d%d%d", &horas, &minutos, &segundos); // Armazenando valores

    printf("Transformando o horario passado, transformando pra segundos eh igual a: %d", transformarHoras(horas, minutos, segundos)); // Chamando a função e já mostrando para o usuário o resultado

    return 0;
}

int transformarHoras(int hora, int minuto, int segundo){ // Função que transforma o horário informado tudo para segundos
    int horaPraSeg = 0, minutoPraSeg = 0, totalSegundos;
    horaPraSeg = hora * 3600;
    minutoPraSeg = minuto * 60;
    totalSegundos = horaPraSeg + minutoPraSeg + segundo;
    return totalSegundos;
}   