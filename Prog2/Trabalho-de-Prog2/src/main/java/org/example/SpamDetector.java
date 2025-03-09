package org.example;

public class SpamDetector {
    public static final String[][] termosSpams = {
            {"Oferta exclusiva", "10"},
            {"Clique aqui", "8"},
            {"Você foi selecionado", "9"},
            {"Ganhe dinheiro rápido", "10"},
            {"Parabéns, você ganhou", "10"},
            {"Aproveite agora", "8"},
            {"Nenhum custo", "9"},
            {"Oferta limitada", "9"},
            {"Garantido", "10"},
            {"Não perca", "8"},
    };

    public static String calcularSpam(String str){
        int count = 0;

        for(String[] aux : termosSpams){
            String termos = aux[0];
            int peso = Integer.parseInt(aux[1]);
            if(str.toLowerCase().contains(termos.toLowerCase())){
                count += peso;
            }
        }

        if(count > 70){
            return "O texto é um spam! Pontuação: " + count;
        }else if(count<=70 && count >=31){
            return "Potecialmente suspeito! Pontuação: " + count;
        }else if(count <=30 && count>=5){
            return "Fracamente suspeito! Pontuação: " + count;
        }
        return "Não é um spam!! Pontuação: " + count;
    }
}
