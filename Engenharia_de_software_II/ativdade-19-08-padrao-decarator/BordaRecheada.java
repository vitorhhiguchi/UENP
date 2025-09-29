public class BordaRecheada extends IngredienteDecorator {

    public BordaRecheada(Pizza pizza) {
        super(pizza);
    }


    @Override
    public String getDescricao() {
        return super.getDescricao() + " com Borda Recheada";
    }

    @Override
    public double getPreco() {
        return super.getPreco() + 8.00;
    }
}