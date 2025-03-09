package estudosChat;

public class PagamentoPix implements Pagamento{
    @Override
    public void realizarPagamento(double valor){
        System.out.println("Pagamento de R$ " + valor + " realizado via PIX");
    }
}
