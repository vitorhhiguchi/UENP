package estudosChat;

public class Gerente extends Funcionario{
    public Gerente(double salario){
        super(salario);
    }

    @Override
    public double calcularBonus(){
        return getSalario()*0.2;
    }
}
