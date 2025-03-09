package estudosChat.exercicios2;

public class Carro implements IVeiculo{
    private int velocidade;

    public Carro() {
        this.velocidade = 0;
    }

    @Override
    public void acelerar() {
        velocidade += 10;
    }

    @Override
    public void frear() {
        if (velocidade >= 10)
            velocidade -= 10;
    }

    @Override
    public int getVelocidade() {
        return velocidade;
    }
}
