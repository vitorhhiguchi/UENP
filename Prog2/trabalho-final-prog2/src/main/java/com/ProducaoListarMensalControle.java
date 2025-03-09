package com;

import java.io.IOException;
import java.time.LocalDate;
import java.util.List;
import java.util.stream.Collectors;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import modelo.Producao;
import util.Dao;

/**
 * Classe de Controle para a Produção Mensal
 */
public class ProducaoListarMensalControle {

    @FXML
    private ComboBox<String> campoMes;

    @FXML
    private ComboBox<Integer> campoAno;
    
    @FXML
    private TableView<Producao> tabelaProducao;

    @FXML
    private TableColumn<Producao, String> colunaData;

    @FXML
    private TableColumn<Producao, Integer> colunaQuantidade;

    private Dao<Producao> daoProducao;

    @FXML
    private void initialize() {
        daoProducao = new Dao<>(Producao.class);

        // Configurar colunas
        colunaData.setCellValueFactory(new PropertyValueFactory<>("dataFormatada"));
        colunaQuantidade.setCellValueFactory(new PropertyValueFactory<>("quantidade"));

        // Preencher ComboBox de meses
        campoMes.getItems().addAll(
                "Janeiro", "Fevereiro", "Março", "Abril",
                "Maio", "Junho", "Julho", "Agosto",
                "Setembro", "Outubro", "Novembro", "Dezembro"
        );

        // Preencher ComboBox de anos (ex: de 2000 até o ano atual)
        int anoAtual = LocalDate.now().getYear();
        for (int i = 2000; i <= anoAtual; i++) {
            campoAno.getItems().add(i);
        }
    }

    @FXML
    private void buscarProducaoMensal() {
        String mesSelecionado = campoMes.getValue();
        Integer anoSelecionado = campoAno.getValue();

        if (mesSelecionado == null || anoSelecionado == null) {
            mostrarErro("Selecione o mês e o ano!");
            return;
        }

        // Obter o número do mês (de 1 a 12)
        int numeroMes = campoMes.getItems().indexOf(mesSelecionado) + 1;

        // Buscar todas as produções no banco
        List<Producao> producoes = daoProducao.listarTodos();

        // Filtrar as produções pelo mês e ano selecionados
        List<Producao> producoesFiltradas = producoes.stream()
                .filter(p -> p.getData().getMonthValue() == numeroMes &&
                             p.getData().getYear() == anoSelecionado)
                .collect(Collectors.toList());

        // Calcular a soma total das quantidades
        int totalLitros = producoesFiltradas.stream()
                .mapToInt(Producao::getQuantidade)
                .sum();

        // Adicionar uma linha com o total
        Producao totalProducao = new Producao();
        totalProducao.setData(null); // Linha "TOTAL"
        totalProducao.setQuantidade(totalLitros);
        producoesFiltradas.add(totalProducao);

        // Exibir os dados filtrados na tabela
        ObservableList<Producao> listaProducoes = FXCollections.observableArrayList(producoesFiltradas);
        tabelaProducao.setItems(listaProducoes);

        if (producoesFiltradas.size() == 1) { // Apenas a linha TOTAL foi adicionada
            mostrarErro("Nenhuma produção encontrada para o mês selecionado.");
        }
    }

    @FXML
    private void voltarMenu() throws IOException {
        App.setRoot("menu"); // Método para voltar ao menu principal
    }

    private void mostrarErro(String mensagem) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.show();
    }
}