public class Main {
    public static void main(String[] args) {
        Balanca balanca = new Balanca();
        ImpressoraPeso impressora = new ImpressoraPeso();
        VerificadorLimitePeso verificador = new VerificadorLimitePeso();

        balanca.addObserver(impressora);
        balanca.addObserver(verificador);

        System.out.println("Alterando peso para 3.2 kg:");
        balanca.setPeso(3.2);

        System.out.println("\nAlterando peso para 6.7 kg:");
        balanca.setPeso(6.7);
    }
}
