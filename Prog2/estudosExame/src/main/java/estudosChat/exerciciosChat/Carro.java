package estudosChat.exerciciosChat;

public class Carro {
    private String marca;
    private String modelo;
    private int ano;

    public Carro(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    public void exibirInfo(){
        System.out.println("Marca " + marca);
        System.out.println("Modelo " + modelo);
        System.out.println("Ano " + ano);
    }

    public String getMarca(){
        return marca;
    }

    public void setMarca(String Marca){
        this.marca = marca;
    }

    public String getModelo(){
        return modelo;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public int getAno(){
        return ano;
    }

    public void setAno(int ano){
        this.ano = ano;
    }
}
