package com;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import modelo.Vaca;
import util.Dao;

/**
 *
 * @author Jose
 */
public class VacaIncluirControle {

    @FXML
    private TextField campoBrinco;
    @FXML
    private TextField campoNome;
    @FXML
    private TextField campoRaca;

    private Dao<Vaca> dao;

    @FXML
    private void initialize() {
        dao = new Dao(Vaca.class);
    }

    @FXML
    private void gravar() {
        if (campoBrinco.getText().isBlank() || campoRaca.getText().isBlank()) {
            mostrarErro("Preencha os campos obrigatórios");
            return;
        }
        String brinco = campoBrinco.getText().toUpperCase();
        Vaca temp = dao.buscarPorChave("brinco", brinco);
        if (temp != null) {
            mostrarErro("Já existe este brinco");
            return;
        }
        Vaca vaca = new Vaca(brinco, campoNome.getText(), campoRaca.getText());
        dao.inserir(vaca);
        limparCampos();
        mostrarSucesso("Vaca cadastrada");
    }

    @FXML
    public void voltarMenu() throws IOException {
        App.setRoot("menu");
    }

    private void limparCampos() {
        this.campoBrinco.setText("");
        this.campoNome.setText("");
        this.campoRaca.setText("");
    }

    private void mostrarSucesso(String mensagem) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.show();
    }

    private void mostrarErro(String mensagem) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.show();
    }

}
