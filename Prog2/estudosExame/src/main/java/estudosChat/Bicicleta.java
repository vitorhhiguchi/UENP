package estudosChat;

public class Bicicleta extends Veiculo{

    public Bicicleta(String nome){
        super(nome);
    }

    @Override
    public void mover(){
        System.out.println("A bicicleta está se movimentando");
    }
}
