package estudosChat.questoesDaProva;

public class Retangulo extends Quadrado implements IForma{
    private int lado2;

    public Retangulo(int lado, int lado2){
        super(lado);
        this.lado2 = lado2;
    }

    @Override
    public double calcularArea(){
        return (double)(getLado()*lado2);
    }
}
