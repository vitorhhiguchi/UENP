package estudosChat;

public class ContaBancaria {
    private double saldo;

    public ContaBancaria(double saldo){
        this.saldo = saldo;
    }

    public void sacar(double valor) throws SaldoInsuficienteException {
        if(valor <= 0 ){
            throw new IllegalArgumentException("O valor do saque deve ser positivo!");
        }
        if(valor > saldo){
            throw new SaldoInsuficienteException("Saldo insuficiente! Saque negado.");
        }
        saldo -= valor;
        System.out.println("Saque de R$ " + valor + " realizado com sucesso!");
    }

    public double getSaldo(){
        return saldo;
    }

    public void setSaldo(double saldo){
        this.saldo = saldo;
    }
}
