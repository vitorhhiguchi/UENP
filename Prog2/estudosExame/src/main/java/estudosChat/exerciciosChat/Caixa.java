package estudosChat.exerciciosChat;

public class Caixa<T> {
    private T item;

    public void setItem(T item){
        this.item = item;
    }

    public T getItem(){
        return item;
    }
}
