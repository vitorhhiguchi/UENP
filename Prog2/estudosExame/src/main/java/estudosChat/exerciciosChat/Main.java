package estudosChat.exerciciosChat;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Carro c1 = new Carro("BMW", "M3", 2025);
        Carro c2 = new Carro("Honda", "Civic SI", 2025);

        c1.exibirInfo();
        c2.exibirInfo();

        System.out.println("----------------------");

        Animal cachorro = new Cachorro();
        Animal gato = new Gato();

        cachorro.emitirSom();
        gato.emitirSom();

        System.out.println("----------------------");
        //Ex 4

        Scanner scanner = new Scanner(System.in);

        try{
            System.out.println("Digite um numero inteiro: ");
            int num = scanner.nextInt();

            int resultado = 10 / num;
            System.out.println("Resultado: " + resultado);
        } catch (ArithmeticException e){
            System.out.println("Erro: " + e.getMessage());
        } catch (Exception e){
            System.out.println("Erro inesperado: " + e.getMessage());
        } finally {
            scanner.close();
            System.out.println("Finalizando programa...");
        }

        System.out.println("----------------------");
        Caixa<String> caixa = new Caixa<>();
        caixa.setItem("Oi jaga");
        System.out.println(caixa.getItem());
    }
}
