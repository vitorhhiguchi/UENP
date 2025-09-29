public class Calabresa extends IngredienteDecorator {

    public Calabresa(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescricao() {
        return super.getDescricao() + ", Calabresa";
    }

    @Override
    public double getPreco() {
        return super.getPreco() + 7.50;
    }
}