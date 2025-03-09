package estudosChat;

public class Estagiario extends Funcionario{
    public Estagiario(double salario){
        super(salario);
    }

    @Override
    public double calcularBonus(){
        return getSalario() * 0.05;
    }
}
