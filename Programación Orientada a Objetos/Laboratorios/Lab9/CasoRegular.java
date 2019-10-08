import java.util.ArrayList;
public class CasoRegular{

    //Se asigna atributos y listas dinámicas de CasoRegular
    private String horario;
    private ArrayList<String> casosR= new ArrayList<String>();
    private ArrayList<String> oficialAsignado = new ArrayList<String>();
    private ArrayList<String> horarios = new ArrayList<String>();
    
    //Constructor vacío de CasoRegular
    public CasoRegular(){
        horario=" ";
    }

    //Constructor con parámetros de CasoRegular
    public CasoRegular(String horario){
        this.horario=horario;
    }

    //Agrega un horario
    public void AgregarHorario(String horario){
        horarios.add(horario);

    }

    //Agrega un nombre al caso
    public void AgregarName(String name){
        casosR.add(name);
        
    } 

    //Asigna un Oficial al caso
    public void AsignarOficial(String oficial){
        oficialAsignado.add(oficial);

    }
    //Muestra un caso específico de un oficial
    public void MostrarCasoEspecifico(String name){
        int i=0;
        while ( i < oficialAsignado.size() && name.equals(oficialAsignado.get(i))){
            System.out.println("\nCASO REGULAR");
            System.out.println(" Oficial Asignado: " + oficialAsignado.get(i));
            System.out.println(" Caso: " + casosR.get(i));
            System.out.println(" Horario: "+ horarios.get(i)+"\n");
            
            i++;
        
        
        }
        

    }
    //Muestra todos los casos regulares
    public void MostrarCasoConOficial(){
        int i=0;
        while ( i < oficialAsignado.size()){
            System.out.println("\nCASO REGULAR");
            System.out.println(" Oficial Asignado: " + oficialAsignado.get(i));
            System.out.println(" Caso: " + casosR.get(i));
            System.out.println(" Horario: "+ horarios.get(i)+"\n");

            i++;
        
        
        }
        

    }

    //Elimina un caso regular
    public void eliminarCaso(String caso,String oficial){
        int i=0;

        while ( i < oficialAsignado.size() && oficial.equals(oficialAsignado.get(i))){
            if (caso.equals(casosR.get(i))) {
                casosR.remove(i);
                oficialAsignado.remove(i);
                horarios.remove(i);
  
            }
           
            i++;
        
        
        }


    }
}