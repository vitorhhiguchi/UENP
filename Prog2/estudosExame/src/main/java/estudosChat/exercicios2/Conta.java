package estudosChat.exercicios2;

public abstract class Conta {
    protected double saldo;

    public Conta(double saldo){
        this.saldo = saldo;
    }

    public double getSaldo(){
        return saldo;
    }

    public abstract void sacar(double valor);

    public void depositar(double valor){
        saldo += valor;
    }
}
