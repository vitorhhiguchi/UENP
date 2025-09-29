public class Queijo extends IngredienteDecorator {

    public Queijo(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescricao() {
        // Pega a descrição da pizza decorada e adiciona a sua.
        return super.getDescricao() + ", Queijo";
    }

    @Override
    public double getPreco() {
        // Pega o preço da pizza decorada e adiciona o seu.
        return super.getPreco() + 5.00;
    }
}