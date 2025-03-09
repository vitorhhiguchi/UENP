/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

import java.io.IOException;
import java.time.LocalDate;
import java.util.List;
import java.util.stream.Collectors;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import modelo.Producao;
import util.Dao;

/**
 *
 * @author Vitor
 */
public class ProducaoDiariaControle {
    @FXML
    private DatePicker campoData;

    @FXML
    private TableView<Producao> tabelaProducao;
    @FXML
    private TableColumn<Producao, LocalDate> colunaData;

    @FXML
    private TableColumn<Producao, Integer> colunaQuantidade;

    private Dao<Producao> daoProducao;
    
    @FXML
    private void initialize() {
        daoProducao = new Dao<>(Producao.class);

        // Configurar as colunas da tabela
        colunaData.setCellValueFactory(new PropertyValueFactory<>("data"));
        colunaQuantidade.setCellValueFactory(new PropertyValueFactory<>("quantidade"));
    }

    @FXML
    private void buscarProducaoDiaria() {
        LocalDate dataSelecionada = campoData.getValue();

        if (dataSelecionada == null) {
            mostrarErro("Selecione uma data!");
            return;
        }

        // Buscar todas as produções no banco
        List<Producao> producoes = daoProducao.listarTodos();

        // Filtrar as produções pela data selecionada
        List<Producao> producoesFiltradas = producoes.stream()
                .filter(p -> p.getData().equals(dataSelecionada))
                .collect(Collectors.toList());

        // Calcular a soma das quantidades
        int totalLitros = producoesFiltradas.stream()
                .mapToInt(Producao::getQuantidade)
                .sum();

        // Adicionar uma linha especial com o total
        Producao totalProducao = new Producao();
        totalProducao.setData(null); // Data nula indica a linha de total
        totalProducao.setQuantidade(totalLitros);
        producoesFiltradas.add(totalProducao);

        // Atualizar a tabela
        ObservableList<Producao> listaProducoes = FXCollections.observableArrayList(producoesFiltradas);
        tabelaProducao.setItems(listaProducoes);

        if (producoesFiltradas.size() == 1) { // Somente a linha TOTAL foi adicionada
            mostrarErro("Nenhuma produção encontrada para a data selecionada.");
        }
    }

    @FXML
    private void voltarMenu() throws IOException {
        App.setRoot("menu");
    }
    
    private void mostrarErro(String mensagem) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.show();
    }
}
