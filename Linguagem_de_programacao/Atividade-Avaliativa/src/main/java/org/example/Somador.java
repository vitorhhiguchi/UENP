package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.Callable;

public class Somador implements Callable <List<Integer>>{
    private Integer vetor[];

    public Somador(){}

    public Somador(Integer v[]){
        vetor = v;
    }

    private boolean ehPrimo(int numero ){
        if (numero <= 1) {
            return false;
        }
        if (numero == 2) {
            return true;
        }
        if (numero % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= numero; i += 2) {
            if (numero % i == 0) {
                return false;
            }
        }
        return true;
    }

    @Override
    public List<Integer> call() throws Exception {
        return Arrays.stream(vetor).filter(x->ehPrimo(x)).toList();
    }
}
