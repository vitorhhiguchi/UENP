package estudosChat;

import java.util.List;

public class Util {
    public static <T> void imprimir(T elemento) {
        System.out.println(elemento);
    }

    public static void adicionarNumero(List<? super Integer> lista){
        lista.add(10);
        lista.add(20);
    }
}
