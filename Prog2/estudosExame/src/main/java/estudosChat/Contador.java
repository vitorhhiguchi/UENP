package estudosChat;

public class Contador {
    private static int totalObjetos = 0;

    public Contador() {
        totalObjetos++;
    }

    public static int getTotalObjetos() {
        return totalObjetos;
    }
}
