import java.util.Observer;
import java.util.Observable;

public class ImpressoraPeso implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        if (arg instanceof Double) {
            System.out.println("Novo peso: " + arg + " kg");
        }
    }
}
