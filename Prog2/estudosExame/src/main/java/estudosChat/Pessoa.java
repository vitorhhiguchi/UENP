package estudosChat;

public class Pessoa {
    private String nome;
    private int idade;

    public Pessoa(){
        System.out.println("Objeto criado com sucesso");
    }

    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public void exibirInfo(){
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade);
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public int getIdade(){
        return idade;
    }

    public void setIdade(int idade){
        if(idade >= 0){
            this.idade = idade;
        } else{
            System.out.println("Idade inválida");
        }
    }
}