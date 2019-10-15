import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.scene.layout.Pane;

public class Main extends Application implements EventHandler<ActionEvent>{

    // Se crean los botones a agregar
    Button guardar;
    Button abrir;
    Button cerrar;

    public static void main(String[] args){
        launch(args);

    }

    // Se hace el override del método start
    @Override
    public void start(Stage primaryStage) throws Exception{

        // Crea el título de la ventana
        primaryStage.setTitle("Ventana de Prueba");

        // Creo el botón, le asigno un texto y un evento
        guardar = new Button();
        guardar.setText("Guardar");
        guardar.setOnAction(this);

        // Creo el botón, le asigno un texto y un evento
        abrir = new Button();
        abrir.setText("Abrir");
        abrir.setOnAction(this);

        // Creo el botón, le asigno un texto y un evento
        cerrar = new Button();
        cerrar.setText("Cerrar");
        cerrar.setOnAction(this);

        Pane canvas = new Pane();

        // Añado los botones al pane
        canvas.getChildren().add(guardar);
        guardar.relocate(10, 60);

        canvas.getChildren().add(abrir);
        abrir.relocate(130, 60);

        canvas.getChildren().add(cerrar);
        cerrar.relocate(230, 60);

        // Se crea la escena
        Scene scene = new Scene(canvas, 300, 150);

        // Se hace un set con la escen creada y se muestra
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    // Este método es para manejar eventos y especificar qué hacer
    @Override
    public void handle(ActionEvent event){
        if(event.getSource() == abrir){
            System.out.println("Abriendo archivo...");

        }else if(event.getSource() == guardar){
            System.out.println("Guardando archivo...");

        }else{
            System.out.println("Cerrando archivo...");

        }

    }

}
