package estudosChat;

public class Veiculo {
    private String nome;

    public Veiculo(String nome){
        this.nome = nome;
        System.out.println("Iniciando Veiculo");
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void mover(){
        System.out.println("O veículo está se movendo!");
    }
}
