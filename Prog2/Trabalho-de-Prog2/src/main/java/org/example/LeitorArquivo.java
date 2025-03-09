package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.MalformedInputException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;

// package
// imports
public class LeitorArquivo {
    /**
     * O método recebe o caminho completo. Ex.
     "C:\\arquivos\\texto.txt"
     * @param caminho: o caminho completo do arquivo
     * @return As linhas do arquivo em uma única string.
     */
    public String lerArquivo(String caminho){
        String retorno = "";
        try {
            BufferedReader br =
                    Files.newBufferedReader(Paths.get(caminho),
                            StandardCharsets.UTF_8);
            String s;
            while ((s = br.readLine()) != null) {
                retorno += s;
            }
        }
        catch(NoSuchFileException ns){
            System.out.println("Arquivo não existe " + ns.toString());
        }
        catch(MalformedInputException mf){
            System.out.println("Erro na codificação: " + mf.toString());
        }
        catch(IOException io){
            System.out.println("Erro de leitura "+ io.toString());
        }
        catch(Exception e){
            System.out.println("Erro não identificado "+ e.toString());
        }
        return retorno;
    }
}