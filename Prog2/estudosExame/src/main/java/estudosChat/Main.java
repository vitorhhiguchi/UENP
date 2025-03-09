package estudosChat;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Pessoa Vitor = new Pessoa();

        Vitor.setNome("Vitor");
        Vitor.setIdade(20);

        Vitor.exibirInfo();

        System.out.println("----------------------");

        Pessoa PauloBriar = new Pessoa("Paulo do Briar", 30);
        PauloBriar.exibirInfo();

        Retangulo retangulo1 = new Retangulo();

        retangulo1.setAltura(2);
        retangulo1.setLargura(3);
        System.out.println("Area do retangulo: " + retangulo1.calcularArea());

        Retangulo retangulo2 = new Retangulo(8.9, 4.3);
        System.out.println("Area do retangulo: " + retangulo2.calcularArea());

        System.out.println("----------------------");

        Calculadora calculadora = new Calculadora();
        System.out.println("Multiplicação: " + calculadora.multiplicar(1,2));
        System.out.println("Multiplicação: " + calculadora.multiplicar(1.2,0.5));

        System.out.println("----------------------");

        Cachorro cachorro = new Cachorro("Pitucho");
        cachorro.fazerSom();
        cachorro.latir();

        Gato gato = new Gato("Lasanha");
        gato.fazerSom();
        gato.miar();

        System.out.println("----------------------");
        // Estudando modificadores static e final
        //🔹 static – Usado para definir atributos e métodos que pertencem à classe, e não a um objeto específico.
        //🔹 final – Pode ser usado para criar constantes, impedir herança ou evitar sobrescrita de métodos.
        //✔️ Variáveis final → Criam constantes.
        //✔️ Métodos final → Evitam sobrescrita.
        //✔️ Classes final → Impedem herança.

        System.out.println("Valor de PI: " + Matematica.PI);
        System.out.println("Soma: " + Matematica.somar(2,3));

        System.out.println("Versão do sistema: " + Configuracoes.VERSAO);
        Utilidades.imprimirMensagem("EU SOU UMA CLASSE FINAL, QUE TEM UM METODO ESTATICO!");

        // Entendendo como o static funciona a em uma classe, ela não pode ser escrita em uma classe externa, mas apenas
        // em uma classe interna.
        Externa.Interna obj = new Externa.Interna();
        obj.mensagem();

        // Entendendo o static em metodos e campos
        Contador c1 = new Contador();
        Contador c2 = new Contador();
        Contador c3 = new Contador();

        System.out.println("Total de objetos criados: " + Contador.getTotalObjetos());

        System.out.println("----------------------");
        // Estudando sobre herança
        Carro carro1 = new Carro("BMW M3");
        System.out.println("Nome do carro: " + carro1.getNome());
        carro1.mover();

        Bicicleta bicicleta1 = new Bicicleta("Ogi 7.0");
        System.out.println("Nome da bicicleta: " + bicicleta1.getNome());
        bicicleta1.mover();

        // Exemplo de polimorfismo
        Veiculo v1 = new Carro("BMW M2");
        Veiculo v2 = new Bicicleta("OGGI 7.2");

        v1.mover();
        v2.mover();

        // Desafio
        Funcionario analista = new Analista(3000);
        Funcionario gerente = new Gerente(5000);
        Funcionario estagiario = new Estagiario(1200);

        System.out.println("Bônus do analista comum: R$ " + analista.calcularBonus());
        System.out.println("Bônus do gerente: R$ " + gerente.calcularBonus());
        System.out.println("Bônus do estagiário: R$ " + estagiario.calcularBonus());

        System.out.println("----------------------");

        //Classes abstratas

        // Entendendo interfaces
        Pagamento pagamento1 = new PagamentoCartao();
        Pagamento pagamento2 = new PagamentoPix();
        Pagamento pagamento3 = new PagamentoBoleto();

        pagamento1.realizarPagamento(100);
        pagamento2.realizarPagamento(50);
        pagamento3.realizarPagamento(200);

        System.out.println("----------------------");
        // Tratamento de exceções
        try {
            int[] numeros = {1, 2, 3};
            System.out.println(numeros[5]); // Acessando posição inválida
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Erro: Índice fora dos limites do array.");
        } finally {
            System.out.println("Isso sempre será executado!");
        }

        // TesteThrow.verificarIdade(16);
        TesteThrow.verificarIdade(19);

        try {
            TesteThrows.lerArquivo();
        } catch (IOException e){
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }

        System.out.println("----------------------");
        ContaBancaria minhaConta = new ContaBancaria(1000);

        try{
            System.out.println("Tentando sacar R$500...");
            minhaConta.sacar(500);

            System.out.println("Tentando sacar R$800...");
            minhaConta.sacar(800);
        } catch(IllegalArgumentException e){
            System.out.println("Erro: " + e.getMessage());
        } catch(SaldoInsuficienteException e){
            System.out.println("Erro: " + e.getMessage());
        } finally {
            System.out.println("Saldo final: R$ " + minhaConta.getSaldo());
        }

        System.out.println("----------------------");
        try{
            int a = 10, b = 0;
            int resultado = a/b;
            System.out.println("Resultado: " + resultado);
        } catch (ArithmeticException e){
            System.out.println("Erro: divisão por zero não permitida!");
        }

        try {
            Scanner scanner = new Scanner(new File("arquivo_inexistente.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("Erro: Arquivo não encontrado!");
        }

        //String texto = null;
        //System.out.println(texto.length());

        System.out.println("----------------------");
        Caixa<String> caixaDeTexto = new Caixa<>();
        caixaDeTexto.guardar("Olá, Genéricos!");
        System.out.println(caixaDeTexto.pegar());

        Caixa<Integer> caixaDeNumeros = new Caixa<>();
        caixaDeNumeros.guardar(42);
        System.out.println(caixaDeNumeros.pegar());

        Util.imprimir("Texto genérico");
        Util.imprimir(123);
        Util.imprimir(3.13);

        System.out.println("----------------------");
        Numero<Integer> n1 = new Numero<>(10);
        Numero<Double> n2 = new Numero<>(5.5);

        System.out.println(n1.getDobro());
        System.out.println(n2.getDobro());

        List<Number> listaNumeros = new ArrayList<>();
        Util.adicionarNumero(listaNumeros);

        System.out.println(listaNumeros);
    }
}
