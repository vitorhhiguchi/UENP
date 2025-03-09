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
public class UsuarioIncluirControle {
    @FXML 
    private TextField campoLogin;
   
    @FXML 
    private TextField campoNome;
    
    @FXML 
    private PasswordField campoSenha;
    
    private Usuario usuario;
    private Dao<Usuario> dao;
        
    @FXML
    private void initialize(){
        dao = new Dao(Usuario.class);
    }
    
    @FXML
    private void gravar(){
        if (campoLogin.getText().isBlank() || campoNome.getText().isBlank() || campoSenha.getText().isBlank()) {
            mostrarErro("Todos os campos são obrigatórios!");
            return;
        }
        
        Usuario existente = dao.buscarPorChave("login", campoLogin.getText());
        if (existente != null) {
            mostrarErro("Já existe um usuário com este login!");
            return;
        }
        
        Usuario usuario = new Usuario();
        usuario.setLogin(campoLogin.getText());
        usuario.setNome(campoNome.getText());
        usuario.setSenha(campoSenha.getText());

        dao.inserir(usuario);
        limparCampos();
        mostrarSucesso("Usuario cadastrado com sucesso");
    }

    @FXML
    private void cancelar() throws IOException {
        App.setRoot("menu");
    }
    
    @FXML
    public void voltarMenu() throws IOException {
        App.setRoot("menu");
    }

    private void limparCampos() {
        this.campoLogin.setText("");
        this.campoNome.setText("");
        this.campoSenha.setText("");
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
