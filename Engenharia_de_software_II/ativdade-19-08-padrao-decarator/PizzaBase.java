public class PizzaBase implements Pizza {

    @Override
    public String getDescricao() {
        return "Massa de pizza fina";
    }

    @Override
    public double getPreco() {
        return 20.00;
    }
}