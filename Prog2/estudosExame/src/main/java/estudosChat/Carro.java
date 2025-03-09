package estudosChat;

public class Carro extends Veiculo{

    public Carro(String nome){
        super(nome);
    }

    @Override
    public void mover(){
        System.out.println("O carro está se movimentando!");
    }
}
