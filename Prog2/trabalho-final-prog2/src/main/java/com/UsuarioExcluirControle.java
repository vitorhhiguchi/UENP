/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import modelo.Usuario;
import util.Dao;

/**
 *
 * @author Vitor
 */
public class UsuarioExcluirControle {
    @FXML
    private TextField campoLogin;
    
    @FXML
    private PasswordField campoSenha;
    
    private Dao<Usuario> dao;

    
    @FXML
    private void initialize() {
        dao = new Dao<>(Usuario.class);
    }

    @FXML
    private void excluir() {
        String login = campoLogin.getText().trim();
        String senha = campoSenha.getText().trim();

        if (login.isEmpty() || senha.isEmpty()) {
            mostrarErro("Os campos Login e Senha devem ser preenchidos!");
            return;
        }

        Usuario usuario = dao.buscarPorChave("login", login);

        if (usuario == null) {
            mostrarErro("Usuário não encontrado!");
            return;
        }
        
        if (!usuario.getSenha().equals(senha)) {
            mostrarErro("Senha incorreta!");
            return;
        }

        // Se a senha estiver correta, exclui o usuário
        boolean sucesso = dao.excluir("login", login);

        if (sucesso) {
            mostrarSucesso("Usuário excluído com sucesso!");
            limparCampos();
        } else {
            mostrarErro("Erro ao excluir o usuário. Tente novamente.");
        }
    }

    @FXML
    private void cancelar() throws IOException {
        App.setRoot("menu");
    }

    private void limparCampos() {
        campoLogin.clear();
        campoSenha.clear();
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
