import java.util.Observer;
import java.util.Observable;

public class VerificadorLimitePeso implements Observer {
    private static final double LIMITE = 5.0;

    @Override
    public void update(Observable o, Object arg) {
        if (arg instanceof Double) {
            double peso = (Double) arg;
            if (peso > LIMITE) {
                System.out.println("Peso acima do limite de " + LIMITE + " kg!");
            } else {
                System.out.println("Peso dentro do limite de " + LIMITE + " kg.");
            }
        }
    }
}
