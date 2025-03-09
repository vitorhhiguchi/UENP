module org.example.maquinadecoxinha {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens org.example.maquinadecoxinha to javafx.fxml;
    exports org.example.maquinadecoxinha;
}