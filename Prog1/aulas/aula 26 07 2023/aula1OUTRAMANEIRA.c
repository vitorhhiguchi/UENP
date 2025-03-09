#include <stdio.h>
int main(){

    int i, numeroMatricula, opcaoInscricao, quantidadeInscricao, quant1=0, quant2=0, quant3=0, quant4=0; 
    float valor=0, desconto=0, valorArrecadado1=0, valorArrecadado2=0, valorArrecadado3=0, valorArrecadado4=0, totalArrecadado=0;
    char escolaPublica; 

    printf("Digite a quantidade de inscricoes: \n");
    scanf("%d", &quantidadeInscricao);

    for(i=0; i< quantidadeInscricao; i++){
        printf("Digite seu numero de matricula, opcao de inscricao(1, 2, 3, 4), e se voce estudou em escola publica(S ou N): \n");
        scanf("%d%d %c", &numeroMatricula, &opcaoInscricao, &escolaPublica);

        switch(opcaoInscricao){
        case 1:
            if(escolaPublica == 'S' || escolaPublica == 's'){
                printf("Voce recebeu um DESCONTO por ter estudado em escola publica!\n");
                desconto = 50 * 0.5;
                valor = desconto;
                valorArrecadado1 += valor;
            }
            else{
                printf("Voce nao recebeu um desconto!\n");
                valor = 50;
                valorArrecadado1 += valor;
            }
            printf("O valor a ser pago por esse aluno eh de: %.2f\n", valor);
            quant1++;
            break;

        case 2:
            if(escolaPublica == 'S' || escolaPublica == 's'){
                printf("Voce recebeu um DESCONTO por ter estudado em escola publica!\n");
                desconto = 65 * 0.5;
                valor = desconto;
                valorArrecadado2 += valor;
            }
            else{
                printf("Voce nao recebeu um desconto!\n");
                valor = 65;
                valorArrecadado2 += valor;
            }
            printf("O valor a ser pago por esse aluno eh de: %.2f\n", valor);
            quant2++;
            break;
        
        case 3:
            if(escolaPublica == 'S' || escolaPublica == 's'){
                printf("Voce recebeu um DESCONTO por ter estudado em escola publica!\n");
                desconto = 80 * 0.5;
                valor = desconto;
                valorArrecadado3 += valor;
            }
            else{
                printf("Voce nao recebeu um desconto!\n");
                valor = 80;
                valorArrecadado3 += valor;
            }
            printf("O valor a ser pago por esse aluno eh de: %.2f\n", valor);
            quant3++;
            break;

        case 4:
            if(escolaPublica == 'S' || escolaPublica == 's'){
                printf("Voce recebeu um DESCONTO por ter estudado em escola publica!\n");
                desconto = 95 * 0.5;
                valor = desconto;
                valorArrecadado4 += valor;
            }
            else{
                printf("Voce nao recebeu um desconto!\n");
                valor = 95;
                valorArrecadado4 += valor;
            }
            printf("O valor a ser pago por esse aluno eh de: %.2f\n", valor);
            quant4++;
            break;
        
        default:
            printf("Opcao nao consta nas opcoes!\n");
            break;
        }
    }    

    printf("\n");
    totalArrecadado = valorArrecadado1 + valorArrecadado2 + valorArrecadado3 + valorArrecadado4;
    printf("O total arrecadado com os cursos foi o valor de R$ %.2f reais\n", totalArrecadado);
    printf("O total de alunos foi de %d. \n", quantidadeInscricao); 
    printf("Em cada opcao de curso se inscreveram: Opcao1 = %d, Opcao2 = %d, Opcao3 = %d, Opcao4 = %d\n", quantidadeInscricao, quant1, quant2, quant3, quant4);

    return 0;
}