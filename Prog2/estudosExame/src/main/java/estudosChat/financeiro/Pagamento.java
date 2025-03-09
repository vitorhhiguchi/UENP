package estudosChat.financeiro;

public class Pagamento {
    private int codigo;

    public Pagamento(int codigo){
        this.codigo = codigo;
    }

    public void mensagem(){
        System.out.println("Mensagem do Pagamento "+codigo);
    }

    public int getCodigo(){
        return codigo;
    }

    public void setCodigo(int codigo){
        this.codigo = codigo;
    }

}
