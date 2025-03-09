package estudosChat;

public class PagamentoCartao implements Pagamento{
    @Override
    public void realizarPagamento(double valor) {
        System.out.println("Pagamento de R$" + valor + " realizado com sucesso!");
    }
}
