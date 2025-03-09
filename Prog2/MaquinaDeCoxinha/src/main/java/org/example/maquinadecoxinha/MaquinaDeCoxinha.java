package org.example.maquinadecoxinha;

public class MaquinaDeCoxinha {
    private int estoque;

    public MaquinaDeCoxinha(){
        this.estoque = 0;
    }

    public int getEstoque(){
        return estoque;
    }

    public void setEstoque(int estoque){
        this.estoque = estoque;
    }

    public void abastecerCozinhas(int quant){
        if(quant > 0) {
            estoque = estoque + quant;
        }
    }

    public void venderCoxinha(){
        if(getEstoque()>0){
            setEstoque(getEstoque()-1);
        }
    }

    public void venderCoxinha(int quant){
        if(getEstoque()>0 && getEstoque() >= quant) {
            setEstoque(getEstoque()-quant);
        }
    }

    public void zerarCoxinhas(){
        setEstoque(0);
    }
}
