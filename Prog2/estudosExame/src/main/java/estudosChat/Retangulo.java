package estudosChat;

public class Retangulo {
    private double largura;
    private double altura;

    public Retangulo(){
        System.out.println("Objeto retangulo instanciado com sucesso!");
    }

    public Retangulo(double largura, double altura){
        this.largura = largura;
        this.altura = altura;
    }

    public double calcularArea(){
        return largura*altura;
    }

    public double getLargura(){
        return largura;
    }

    public void setLargura(double largura){
        this.largura = largura;
    }

    public double getAltura(){
        return altura;
    }

    public void setAltura(double altura){
        this.altura = altura;
    }
}
