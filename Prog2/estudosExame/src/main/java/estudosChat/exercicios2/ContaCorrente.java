package estudosChat.exercicios2;

public class ContaCorrente extends Conta{

    public ContaCorrente(double saldo) {
        super(saldo);
    }

    @Override
    public void sacar(double valor){
        if(saldo > valor && saldo+2 == valor){
            saldo -= 2;
            saldo -= valor;
        }else {
            System.out.println("Saldo insuficiente");
        }
    }



}
