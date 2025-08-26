public class Arquivo {
    private String nome;

    public GerenciadorArquivos(String nome) {
        this.nome = nome;
    }

    // get e setter
}

public class ProcessarDados {
    public void processarDados() {
        // Lógica para processar os dados do arquivo
    }
}

public class LeitorArquivo {
    public void lerArquivo() {
        try (BufferedReader br = new BufferedReader(new
            FileReader(nomeArquivo))) {
            String linha;
            int totalLinhas = 0;
            int totalPalavras = 0;
            int totalCaracteres = 0;
            while ((linha = br.readLine()) != null) {
                totalLinhas++;
                totalPalavras += linha.split(" ").length;
                totalCaracteres += linha.length();
            }
            System.out.println("Total de linhas: " + totalLinhas);
            System.out.println("Total de palavras: " +
            totalPalavras);
            System.out.println("Total de caracteres: " +
            totalCaracteres);
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " +
            e.getMessage());
        }
    }
}