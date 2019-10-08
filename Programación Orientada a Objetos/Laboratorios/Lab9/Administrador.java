import java.util.ArrayList;
import java.util.Scanner;
public class Administrador{
    //Se define las listas dinámicas y se invoca los Casos
    private ArrayList<Oficial> oficiales = new ArrayList<Oficial>();
    private ArrayList<String> nameOficiales= new ArrayList<String>();
    CasoParticular casoParticular =new CasoParticular();
    CasoRegular casoRegular= new CasoRegular();
    Scanner sc= new Scanner(System.in);

    //Constructor de Administrador
    public Administrador(){

    }

    //Agrega un oficial
    public void AgregarOficial(String name, int num){
        oficiales.add(new Oficial(name,num));
        nameOficiales.add(name);
    }

    //Devuelve la lista de nombres de los Oficiales
    public ArrayList<String> getOficiales(){
        
        return nameOficiales;
    }

    //Busca un oficial
    public boolean BuscarOficial(String name){
        int i=0;
        while ( i < oficiales.size()){
            if (name.equals(oficiales.get(i).getName())){

                return true;
            }
            
            i++;
        
        
        }
        
        return false;

    }
    //Muestra los casos particulares de un oficial
    public void MostrarCasosParticulares(String name){
        casoParticular.MostrarCasoEspecifico(name);
        
    }
    //Muestra los casos regulares de un oficial      
    public void MostrarCasosRegulares(String name){
        casoRegular.MostrarCasoEspecifico(name);
        
    }
    //Elimina un oficial
    public void eliminarOficial(String name){
        int i=0;
        while ( i < oficiales.size()){
            if (name.equals(oficiales.get(i).getName())){

                oficiales.remove(i);
                nameOficiales.remove(i);
            }
            
            i++;
        
        }
    }
    //Obtiene un oficial de la lista dinámica de Oficiales
    public Oficial ObtenerOficial(String name){
        int i=0;
        while ( i < oficiales.size()){
            if (name.equals(oficiales.get(i).getName())){

                return oficiales.get(i);
            }
            
            i++;
        
        
        }
        
        return new Oficial();

    }

    //Asigna un caso particular a un oficial
    public void AsignarCasoParticular(Oficial oficial){
        System.out.println("Nombre del Caso:");
        String nombreCaso = sc.nextLine();
        casoParticular.AgregarName(nombreCaso);
        System.out.println("Fecha:");
        String fecha = sc.nextLine();
        System.out.println("Hora:");
        String hora = sc.nextLine();
        System.out.println("Duración:");
        String duracion= sc.nextLine();
        casoParticular.AgregarFecha(fecha);
        casoParticular.AgregarDuracion(duracion);
        casoParticular.AgregarHora(hora);
        casoParticular.AsignarOficial(oficial.getName());
        
       
    }
    //Asigna un caso regular a un oficial
    public void AsignarCasoRegular(Oficial oficial){
        System.out.println("Nombre del Caso:");
        String nombreCaso = sc.nextLine();
        System.out.println("Horario:");
        String horario = sc.nextLine();        
        casoRegular.AgregarHorario(horario);
        casoRegular.AgregarName(nombreCaso);
        casoRegular.AsignarOficial(oficial.getName());
        
    }
    //Muestra todos los casos actuales
    public void MostrarTodo(){
        casoParticular.MostrarCasoConOficial();
        casoRegular.MostrarCasoConOficial();
    }

    //Elimina un caso a base del oficial y del nombre del caso
    public void eliminarCasos(String caso, String oficial){

        casoParticular.eliminarCaso(caso, oficial);
        casoRegular.eliminarCaso(caso, oficial);

    }

}