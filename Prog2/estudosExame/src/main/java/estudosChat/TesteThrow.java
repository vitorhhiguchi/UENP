package estudosChat;

public class TesteThrow {
    static void verificarIdade(int idade){
        if(idade < 18){
            throw new IllegalArgumentException("Idade mínima é 18 anos!");
        }
        System.out.println("Acesso permitido");
    }
}
