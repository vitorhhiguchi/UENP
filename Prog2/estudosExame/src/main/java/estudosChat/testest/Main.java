package estudosChat.testest;
import estudosChat.financeiro.Pagamento;
import estudosChat.usuarios.Cliente;



public class Main {
    public static void main(String[] args) {
        Pagamento pag1 = new Pagamento(1);
        Cliente c1 = new Cliente("Vitor");

        pag1.mensagem();
        c1.imprime();

    }
}
