package estudosChat;

public class Animal {
    protected String nome;

    public Animal(String nome){
        this.nome = nome;
    }

    protected void fazerSom() {
        System.out.println("O animal faz um som...");
    }
}
