package org.example.exercicio3_bimestre;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

import java.util.ArrayList;

public class CadastroDeClientesController {
    private ArrayList<Cliente> clientes;
    private Buscador buscador;
    private Endereco endereco;

    @FXML
    private TextField txtNome;

    @FXML
    private TextField txtCEP;

    @FXML
    private TextField txtRua;

    @FXML
    private TextField txtNumero;

    @FXML
    private TextField txtCidade;

    @FXML
    private TextField txtEstado;

    @FXML
    private TextField txtTelefone;

    @FXML
    private void initialize(){
        clientes = new ArrayList<Cliente>();
    }

    @FXML
    private void busca(){
        buscador = new Buscador();
        try {
            endereco = buscador.buscar(txtCEP.getText());
            txtRua.setText(endereco.getRua());
            txtCidade.setText(endereco.getCidade());
            txtEstado.setText(endereco.getEstado());
        }
        catch (Exception e){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setHeaderText("Erro, CEP incorreto");
            alert.setContentText(e.getMessage());
            alert.show();
        }
    }

    @FXML
    private void limpar(){
        txtNome.setText("");
        txtCEP.setText("");
        txtRua.setText("");
        txtNumero.setText("");
        txtCidade.setText("");
        txtEstado.setText("");
        txtTelefone.setText("");
    }

    @FXML
    private void salvar(){
        if (txtNome.getText().isEmpty() || txtCEP.getText().isEmpty() || txtRua.getText().isEmpty()
                || txtCidade.getText().isEmpty() || txtEstado.getText().isEmpty()
                || txtTelefone.getText().isEmpty()) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setHeaderText("Há campos incompletos");
            alert.show();
        }else {
            Cliente cliente = new Cliente();
            cliente.setNome(txtNome.getText());
            cliente.setEndereco(endereco);
            cliente.setTelefone(txtTelefone.getText());

            txtNome.setText("");
            txtCEP.setText("");
            txtRua.setText("");
            txtNumero.setText("");
            txtCidade.setText("");
            txtEstado.setText("");
            txtTelefone.setText("");

            clientes.add(cliente);
            for(Cliente c : clientes){
                System.out.println(c.getNome());
            }
        }
    }
}
