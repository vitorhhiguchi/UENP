package estudosChat;

abstract class Funcionario {
    private double salario;

    public Funcionario(double salario){
        this.salario = salario;
    }

    public abstract double calcularBonus();

    public double getSalario(){
        return salario;
    }

    public void setSalario(double salario){
        this.salario = salario;
    }
}
