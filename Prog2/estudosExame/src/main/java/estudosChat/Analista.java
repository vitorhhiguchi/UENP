package estudosChat;

public class Analista extends Funcionario {
    public Analista(double salario){
        super(salario);
    }

    @Override
    public double calcularBonus(){
        return getSalario() * 0.1;
    }
}
