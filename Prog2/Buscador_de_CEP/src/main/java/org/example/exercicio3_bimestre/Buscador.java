package org.example.exercicio3_bimestre;

import com.google.gson.Gson;
import java.io.IOException;
import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.util.EntityUtils;

public class Buscador {

    public Endereco buscar(String cep) throws IllegalArgumentException, IOException, Exception {
        // cep não está no formato 99999-999
        if (!cep.matches("\\d{5}-\\d{3}")) {
            throw new IllegalArgumentException("O formato não é válido");
        }
        EnderecoInterno enderecoInterno = null;
        HttpGet request = new HttpGet("https://viacep.com.br/ws/" + cep + "/json/");
        CloseableHttpClient httpClient = HttpClientBuilder.create().disableRedirectHandling().build();
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(request);
        } catch (java.net.UnknownHostException uhe) {
            // não foi possível conectar ao servidor de busca de Cep
            throw new IOException("Erro ao conectar com o serviço ViaCep");
        }
        HttpEntity entity = response.getEntity();
        String retorno = EntityUtils.toString(entity);

        // se o CEP não foi encontrado
        if (retorno.contains("erro")) {
            response.close();
            httpClient.close();
            throw new IOException("O CEP não existe ou está em um formato inválido");
        }
        Gson gson = new Gson();
        enderecoInterno = gson.fromJson(retorno, EnderecoInterno.class);
        response.close();
        httpClient.close();
        return enderecoInterno.mapear();

    }


    private class EnderecoInterno {
        private String cep;
        private String logradouro;
        private String complemento;
        private String bairro;
        private String localidade;
        private String uf;
        private String ibge;
        private String gia;
        private String ddd;
        private String siafi;

        public EnderecoInterno() {
        }

        public Endereco mapear() {
            return new Endereco(cep, logradouro, "", localidade, uf);
        }

        public String getCep() {
            return cep;
        }

        public void setCep(String cep) {
            this.cep = cep;
        }

        public String getLogradouro() {
            return logradouro;
        }

        public void setLogradouro(String logradouro) {
            this.logradouro = logradouro;
        }

        public String getComplemento() {
            return complemento;
        }

        public void setComplemento(String complemento) {
            this.complemento = complemento;
        }

        public String getBairro() {
            return bairro;
        }

        public void setBairro(String bairro) {
            this.bairro = bairro;
        }

        public String getLocalidade() {
            return localidade;
        }

        public void setLocalidade(String localidade) {
            this.localidade = localidade;
        }

        public String getUf() {
            return uf;
        }

        public void setUf(String uf) {
            this.uf = uf;
        }

        public String getIbge() {
            return ibge;
        }

        public void setIbge(String ibge) {
            this.ibge = ibge;
        }

        public String getGia() {
            return gia;
        }

        public void setGia(String gia) {
            this.gia = gia;
        }

        public String getDdd() {
            return ddd;
        }

        public void setDdd(String ddd) {
            this.ddd = ddd;
        }

        public String getSiafi() {
            return siafi;
        }

        public void setSiafi(String siafi) {
            this.siafi = siafi;
        }

    }

//    public static void main(String[] args) {
//        Buscador buscador = new Buscador();
//        Endereco endereco = new Endereco();
//        try {
//            endereco = buscador.buscar("86360-000");
//            System.out.println(endereco.getCidade());
//        }
//        catch(Exception e){
//            System.out.println(e.getMessage());
//        }
//    }

}