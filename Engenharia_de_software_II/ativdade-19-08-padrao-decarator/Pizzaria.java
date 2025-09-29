public class Pizzaria {

    public static void main(String[] args) {
        System.out.println("--- Pedido 1: Pizza de Queijo ---");
        
        // 1. Começamos com a pizza base
        Pizza pizzaSimples = new PizzaBase();
        
        // 2. Decoramos com queijo
        pizzaSimples = new Queijo(pizzaSimples);
        
        System.out.println("Descrição: " + pizzaSimples.getDescricao());
        System.out.printf("Preço: R$ %.2f\n", pizzaSimples.getPreco());
        System.out.println("------------------------------------------");

        
        System.out.println("\n--- Pedido 2: Pizza Completa ---");
        
        // Montamos uma pizza mais complexa encadeando os construtores
        Pizza pizzaCompleta = new BordaRecheada(
                                new Calabresa(
                                    new Queijo(
                                        new PizzaBase()
                                    )
                                )
                              );

        System.out.println("Descrição: " + pizzaCompleta.getDescricao());
        System.out.printf("Preço: R$ %.2f\n", pizzaCompleta.getPreco());
        System.out.println("------------------------------------------");
    }
}