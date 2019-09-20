import java.util.ArrayList;

public class Habitacion{

    private ArrayList<Dispositivos> cocina = new ArrayList<Dispositivos>();
    private ArrayList<Dispositivos> banno = new ArrayList<Dispositivos>();
    private ArrayList<Dispositivos> sala = new ArrayList<Dispositivos>();
    private ArrayList<Dispositivos> comedor = new ArrayList<Dispositivos>();
    private ArrayList<Dispositivos> cuarto = new ArrayList<Dispositivos>();
    private ArrayList<Dispositivos> sotano = new ArrayList<Dispositivos>();
    
    private String room;

    public Habitacion(){
        

    }


    public void setRoom(String room){
        this.room = room;
    }

    public Dispositivos getCocina(){
        return this.cocina.get(0);
    }

    public void setCocina(){
        
        this.cocina.add(new Microondas());
        this.cocina.add(new Refrigeradora());
        this.cocina.add(new ExtractorDeAire());

    }
    public void setBanno(){
        this.banno.add(new Lampara());
        this.banno.add(new Ducha());

    }

    public void setSala(){
        this.sala.add(new Televisor());
        this.sala.add(new Lampara());

    }

    public void setComedor(){
        this.comedor.add(new Lampara());

    }

    public void setCuarto(){
        this.cuarto.add(new Lampara());

    }

    public void setSotano(){
        this.sotano.add(new Computadora());
        this.sotano.add(new Secadora());
        this.sotano.add(new Lavadora());
        this.sotano.add(new Lampara());
    }

    public String encenderCuarto(String room){
        setRoom(room);
        return this.room + " encendida";
    }

    public String apagarCuarto(String room){
        setRoom(room);
        return this.room + " apagada";
    }
}