package estudosChat;

public class Numero <T extends Number>{
    private T valor;

    public Numero(T valor){
        this.valor = valor;
    }

    public double getDobro(){
        return valor.doubleValue()*2;
    }
}
