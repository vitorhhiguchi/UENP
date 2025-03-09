module org.example.exercicio3_bimestre {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;
    requires com.google.gson;
    requires org.apache.httpcomponents.httpcore;
    requires org.apache.httpcomponents.httpclient;


    opens org.example.exercicio3_bimestre to javafx.fxml, com.google.gson;
    exports org.example.exercicio3_bimestre;
}