package org.example.exercicio3_bimestre;

public class Cliente {
    private int codigo;
    private static int contador = 0;
    private String nome;
    private Endereco endereco;
    private String telefone;

    public Cliente(){
        contador++;
        codigo = contador;
        nome = "";
        endereco = new Endereco();
        telefone = "";
    }

    public Cliente(String nome, Endereco endereco, String telefone){
        contador++;
        codigo = contador;
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public Endereco getEndereco(){
        return endereco;
    }

    public void setEndereco(Endereco endereco){
        this.endereco = endereco;
    }

    public String getTelefone(){
        return telefone;
    }

    public void setTelefone(String telefone){
        this.telefone = telefone;
    }


}
