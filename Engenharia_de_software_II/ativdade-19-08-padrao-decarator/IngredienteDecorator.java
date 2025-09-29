public abstract class IngredienteDecorator implements Pizza {
    // Referência para o objeto que está sendo decorado.
    // Pode ser uma PizzaBase ou outra Pizza já decorada.
    protected Pizza pizzaDecorada;

    public IngredienteDecorator(Pizza pizza) {
        this.pizzaDecorada = pizza;
    }

    // Por padrão, delegamos a chamada para o objeto decorado.
    // As subclasses irão sobrescrever isso para adicionar seu comportamento.
    @Override
    public String getDescricao() {
        return pizzaDecorada.getDescricao();
    }

    @Override
    public double getPreco() {
        return pizzaDecorada.getPreco();
    }
}