import java.util.Observable;

public class Balanca extends Observable {
    private double peso;

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
        setChanged();
        notifyObservers(peso);
    }
}
