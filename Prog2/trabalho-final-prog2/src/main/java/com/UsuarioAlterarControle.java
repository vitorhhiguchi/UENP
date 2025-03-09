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
public class UsuarioAlterarControle {
    @FXML
    private TextField campoLogin;

    @FXML
    private TextField campoNome;

    @FXML
    private PasswordField campoSenha;
    
    private Dao<Usuario> dao;

    @FXML
    private void initialize() {
        dao = new Dao<>(Usuario.class);

        // Adiciona um evento ao perder o foco do campo de login
        campoLogin.focusedProperty().addListener((obs, oldVal, newVal) -> {
            if (!newVal) { // Quando o foco sai do campo
                carregarDadosUsuario();
            }
        });
    }

    private void carregarDadosUsuario() {
        String login = campoLogin.getText().trim();

        if (login.isEmpty()) {
            mostrarErro("Digite um login para buscar o usuário.");
            return;
        }

        // Busca o usuário pelo login
        Usuario usuario = dao.buscarPorChave("login", login);

        if (usuario == null) {
            mostrarErro("Usuário não encontrado!");
            limparCampos();
        } else {
            // Preenche os campos, mas mantém a senha protegida
            campoNome.setText(usuario.getNome());
            campoSenha.setText(usuario.getSenha());
        }
    }

    @FXML
    private void salvarAlteracoes() {
        String login = campoLogin.getText().trim();
        String nome = campoNome.getText().trim();
        String senha = campoSenha.getText().trim();

        if (login.isEmpty() || nome.isEmpty() || senha.isEmpty()) {
            mostrarErro("Todos os campos são obrigatórios!");
            return;
        }

        Usuario usuarioAtualizado = new Usuario();
        usuarioAtualizado.setLogin(login);
        usuarioAtualizado.setNome(nome);
        usuarioAtualizado.setSenha(senha);

        dao.alterar("login", login, usuarioAtualizado);
        mostrarSucesso("Dados do usuário alterados com sucesso!");
        limparCampos();
    }

    @FXML
    private void cancelar() throws IOException {
        App.setRoot("menu");
    }    
    
    private void limparCampos() {
        campoLogin.clear();
        campoNome.clear();
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
