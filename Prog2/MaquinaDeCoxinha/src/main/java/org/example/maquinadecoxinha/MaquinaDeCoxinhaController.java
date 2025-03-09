package org.example.maquinadecoxinha;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import javax.swing.*;

public class MaquinaDeCoxinhaController {

    private MaquinaDeCoxinha maquinaDeCoxinha;

    @FXML
    private Label titulo;

    @FXML
    private TextField estoqueDeCoxinhas;

    @FXML
    private TextField campoAbastece;

    @FXML
    private TextField campoDeVenda;

    @FXML
    private Button enviarPedido;

    @FXML
    private Button venderApenasUm;

    @FXML
    private Button zerar;

    @FXML
    private Label labelAbastecer;

    @FXML
    private Label labelVender;

    @FXML
    private void initialize(){
        maquinaDeCoxinha = new MaquinaDeCoxinha();
    }

    @FXML
    private void atualizarEstoque(){
        estoqueDeCoxinhas.setText("Estoque " + String.valueOf(maquinaDeCoxinha.getEstoque()));
    }

    @FXML
    private void abastecer(){
        int quant = Integer.parseInt(campoAbastece.getText());
        maquinaDeCoxinha.abastecerCozinhas(quant);
        atualizarEstoque();
        campoAbastece.setText("");
    }

    @FXML
    private void venderUmaCoxinha(){
        maquinaDeCoxinha.venderCoxinha();
        atualizarEstoque();
        campoDeVenda.setText("");
    }

    @FXML
    private void venderQuantasQuiser(){
        maquinaDeCoxinha.venderCoxinha(Integer.parseInt(campoDeVenda.getText()));
        atualizarEstoque();
    }

    @FXML
    private void zerarMaquina(){
        maquinaDeCoxinha.zerarCoxinhas();
        atualizarEstoque();
    }
}