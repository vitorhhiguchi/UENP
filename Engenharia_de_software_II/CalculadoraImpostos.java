public class CalculadoraImpostos {
    public double calcularImposto(double valor, String tipoImposto)
    {
        double imposto = 0.0;
        if (tipoImposto.equals("ICMS")) {
            imposto = valor * 0.18; // Taxa de ICMS
        } else if (tipoImposto.equals("ISS")) {
            imposto = valor * 0.05; // Taxa de ISS
        } else if (tipoImposto.equals("IPI")) {
            imposto = valor * 0.10; // Taxa de IPI
        } else if (tipoImposto.equals("IOF")) {
            imposto = valor * 0.03; // Taxa de IOF
        }
        return imposto;
    }
}