package com;

import java.io.IOException;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import modelo.Vaca;
import util.Dao;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Vitor
 */
public class VacaExcluirControle {
    @FXML
    private ComboBox<Vaca> campoBrinco;
       
    @FXML
    private TextField campoNome;
    
    @FXML
    private TextField campoRaca;
    
    private Dao<Vaca> dao;

  @FXML
    private void initialize() {
        dao = new Dao<>(Vaca.class);

        List<Vaca> vacas = dao.listarTodos();
        ObservableList<Vaca> listaVacas = FXCollections.observableArrayList(vacas);
        campoBrinco.setItems(listaVacas);

        // Define o comportamento ao selecionar um brinco
        campoBrinco.setOnAction(event -> preencherCampos());
    }  

    private void preencherCampos() {
        Vaca vacaSelecionada = campoBrinco.getValue();
        if (vacaSelecionada != null) {
            campoNome.setText(vacaSelecionada.getNome());
            campoRaca.setText(vacaSelecionada.getRaca());
        } else {
            limparCampos();
        }
    }

    @FXML
    private void excluir() {
        Vaca vacaSelecionada = campoBrinco.getValue();

        if (vacaSelecionada == null) {
            mostrarErro("Selecione uma vaca para excluir.");
            return;
        }

        boolean sucesso = dao.excluir("brinco", vacaSelecionada.getBrinco());

        if (sucesso) {
            mostrarSucesso("Vaca excluída com sucesso!");
            atualizarComboBox();
            limparCampos();
        } else {
            mostrarErro("Erro ao excluir a vaca. Tente novamente.");
        }
    }

    @FXML
    private void cancelar() throws IOException {
        App.setRoot("menu");
    }

    private void limparCampos() {
        campoNome.clear();
        campoRaca.clear();
    }

    private void atualizarComboBox() {
        List<Vaca> vacas = dao.listarTodos();
        ObservableList<Vaca> listaAtualizada = FXCollections.observableArrayList(vacas);
        campoBrinco.setItems(listaAtualizada);
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

