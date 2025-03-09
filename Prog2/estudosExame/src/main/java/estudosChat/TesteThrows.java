package estudosChat;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TesteThrows {
    static void lerArquivo() throws IOException {
        FileReader arquivo = new FileReader("arquivo.txt");
        BufferedReader br = new BufferedReader(arquivo);
        System.out.println(br.readLine());
    }
}
