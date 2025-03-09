/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

import java.io.IOException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import modelo.Usuario;
import util.Dao;

/**
 *
 * @author Vitor
 */
public class LoginController {
    @FXML
    private TextField campoLogin;

    @FXML
    private PasswordField campoSenha;

    private Dao<Usuario> dao;

    @FXML
    public void initialize() {
        dao = new Dao<>(Usuario.class);
    }

    @FXML
    private void onEntrar(ActionEvent event) {
        String login = campoLogin.getText();
        String senha = campoSenha.getText();

        // Busca o usuário no banco
        Usuario usuario = dao.buscarPorChave("login", login);

        if (usuario != null && usuario.getSenha().equals(senha)) {
            abrirMenu(usuario.getNome());
        } else {
            exibirAlerta("Erro de Login", "Usuário ou senha incorretos!");
        }
    }

    @FXML
    private void usuarioIncluir(ActionEvent event) {
        exibirAlerta("Cadastro", "Funcionalidade de cadastro ainda não implementada.");
    }

    private void abrirMenu(String nomeUsuario) {
        try {
            // Carrega o FXML do menu
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/menu.fxml"));
            VBox root = loader.load();

            // Passa o nome do usuário para o controller do menu
            MenuControle menuController = loader.getController();
            menuController.setNomeUsuario(nomeUsuario);

            // Configura a nova cena
            Stage stage = (Stage) campoLogin.getScene().getWindow();
            stage.setScene(new Scene(root));
            stage.setTitle("Menu Principal");
        } catch (IOException e) {
            e.printStackTrace();
            exibirAlerta("Erro", "Não foi possível abrir o menu.");
        }
    }
    
    @FXML
    public void abrirCadastro() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/com/usuarioIncluir.fxml"));
            Parent root = loader.load();
            
            Stage stage = new Stage();
            stage.setScene(new Scene(root));
            stage.setTitle("Cadastro de Usuário");
            stage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void exibirAlerta(String titulo, String mensagem) {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}