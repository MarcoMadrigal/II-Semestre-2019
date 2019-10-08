import java.util.ArrayList;
public class CasoParticular{
    
    //Se define los atributos y listas dinámicas de CasoParticular
    private String fecha;
    private String hora;
    private String duracion;
    private ArrayList<String> casos= new ArrayList<String>();
    private ArrayList<String> oficialAsignado = new ArrayList<String>();
    private ArrayList<String> fechas = new ArrayList<String>();
    private ArrayList<String> horas = new ArrayList<String>();
    private ArrayList<String> duraciones = new ArrayList<String>();
    
    //Constructor vacío de CasoParticular
    public CasoParticular(){
        fecha=" ";
        hora=" ";
        duracion=" ";
    }

    //Constructor con parámetros de CasoParticular
    public CasoParticular(String fecha,String hora,String duracion){
        this.fecha=fecha;
        this.hora=hora;
        this.duracion=duracion;
    }

    //Agrega una fecha
    public void AgregarFecha(String fecha){
        fechas.add(fecha);
    }

    //Agrega una hora
    public void AgregarHora(String hora){
        horas.add(hora);
    }

    //Agrega una duración
    public void AgregarDuracion(String duracion){
        duraciones.add(duracion);
    }
    //Agrega un nombre al caso
    public void AgregarName(String name){
        casos.add(name);
    }

    //Asigna un oficial
    public void AsignarOficial(String oficial){
        oficialAsignado.add(oficial);

    }
    //Muestra un caso específico de un oficial
    public void MostrarCasoEspecifico(String name){
        int i=0;
        while ( i < oficialAsignado.size() && name.equals(oficialAsignado.get(i))){
            System.out.println("\nCASO PARTICULAR");
            System.out.println(" Oficial Asignado: " + oficialAsignado.get(i));
            System.out.println(" Caso: " + casos.get(i));
            System.out.println( " Fecha: "+fechas.get(i));
            System.out.println(" Hora: "+horas.get(i));
            System.out.println( " Duracion: "+duraciones.get(i)+"\n");
           
            i++;
        
        
        }
        

    }

    //Muestra todos los casos particulares
    public void MostrarCasoConOficial(){
        int i=0;

        while ( i < oficialAsignado.size()){
            System.out.println("\nCASO PARTICULAR");
            System.out.println(" Oficial Asignado: " + oficialAsignado.get(i));
            System.out.println(" Caso: " + casos.get(i));
            System.out.println( " Fecha: "+fechas.get(i));
            System.out.println(" Hora: "+horas.get(i));
            System.out.println( " Duracion: "+duraciones.get(i)+"\n");
           
            i++;
        
        
        }
        

    }
    //Elimina un caso particular
    public void eliminarCaso(String caso,String oficial){
        int i=0;

        while ( i < oficialAsignado.size() && oficial.equals(oficialAsignado.get(i))){
            if (caso.equals(casos.get(i))) {
                casos.remove(i);
                oficialAsignado.remove(i);
                fechas.remove(i);
                horas.remove(i);
                duraciones.remove(i);   
            }
           
            i++;
        
        
        }


    }
}