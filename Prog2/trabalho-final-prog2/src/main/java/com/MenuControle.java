package com;

import java.io.IOException;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

/**
 *
 * @author Jose
 */
public class MenuControle {
    
    @FXML
    public void initialize(){
        
    }
    
    @FXML
    private void producaoIncluir() throws IOException{
        App.setRoot("producaoIncluir");
    }
    
    @FXML
    private void producaoListarPorVaca() throws IOException{
        App.setRoot("producaoListarPorVaca");
    }
    
    @FXML
    private void producaoListarDiario() throws IOException{
        App.setRoot("producaoListarDiario");
    }
    
    @FXML
    private void producaoListarMensal() throws IOException{
        App.setRoot("producaoListarMensal");
    }
    
    @FXML
    private void vacaAlterar() throws IOException{
        App.setRoot("vacaAlterar");
    }
    
    @FXML
    private void vacaIncluir() throws IOException{
        App.setRoot("vacaIncluir");
    }
    
    @FXML
    private void vacaExcluir() throws IOException{
        App.setRoot("vacaExcluir");
    }
    
    @FXML
    private void usuarioIncluir() throws IOException {
        App.setRoot("usuarioIncluir");
    }
    
    @FXML
    private void usuarioAlterar() throws IOException {
        App.setRoot("usuarioAlterar");
    }
    
    @FXML
    private void usuarioExcluir() throws IOException {
        App.setRoot("usuarioExcluir");
    }
    
    @FXML
    private void sair(){
        Platform.exit();
        System.exit(0);
    }
    
    @FXML
    private Label lblUsuario;

    public void setNomeUsuario(String nomeUsuario) {
        lblUsuario.setText("Bem-vindo, " + nomeUsuario + "!");
    }
}
