package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TestaSomador {
    public static void main(String[ ] args) throws InterruptedException, ExecutionException {

        ExecutorService pool = Executors.newFixedThreadPool(2);
        int QUANTIDADE = 1_000;
        Integer v1[] = new Integer[QUANTIDADE];
        Random gerador = new Random();
        for (int i = 0; i < QUANTIDADE; i++) {
            v1[i] = gerador.nextInt();
        }

        long inicio = System.currentTimeMillis();
        int meio = v1.length / 2;
        Integer[] primeiraMetade = Arrays.copyOfRange(v1, 0, meio);
        Integer[] segundaMetade = Arrays.copyOfRange(v1, meio, v1.length);
        Somador s1 = new Somador( primeiraMetade );
        Somador s2 = new Somador( segundaMetade );
        Future<List<Integer>> futuro = pool.submit(s1); // inicia execução
        Future<List<Integer>> futuro2 = pool.submit(s2);
        ArrayList<Integer> teste = new ArrayList();
        teste.addAll(futuro.get());
        teste.addAll(futuro2.get());
//        List<Integer> resultado = futuro.get();
//        resultado.addAll(futuro2.get());

        long fim = System.currentTimeMillis();
        System.out.println("Tempo decorrido: " + (fim - inicio));
    }
}
