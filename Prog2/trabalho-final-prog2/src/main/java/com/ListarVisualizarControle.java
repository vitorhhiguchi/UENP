/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

import java.time.LocalDate;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import modelo.Producao;
import modelo.Vaca;

/**
 *
 * @author Vitor
 */
public class ListarVisualizarControle {
    @FXML
    private ComboBox<Vaca> combovaca;
    
    @FXML
    private TableView<Producao> tabelaProducao;
    
    @FXML
    public void initialize(){
        TableColumn<Producao, LocalDate> colunaData = new TableColumn<>("Data");
        colunaData.setCellValueFactory(new PropertyValueFactory<>("date"));
    }
}
