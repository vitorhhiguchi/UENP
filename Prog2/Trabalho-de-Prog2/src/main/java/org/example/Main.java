package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        LeitorArquivo leitor = new LeitorArquivo();
        String caminho = leitor.lerArquivo("C:\\Users\\Vitor\\IdeaProjects\\Trabalho1_Prog2\\src\\main\\java\\org\\example\\arquivo.txt");
        String caminho2 = leitor.lerArquivo("C:\\Users\\Vitor\\IdeaProjects\\Trabalho1_Prog2\\src\\main\\java\\org\\example\\arquivo2.txt");

        System.out.println(SpamDetector.calcularSpam(caminho));
        System.out.println(SpamDetector.calcularSpam(caminho2));
    }
}