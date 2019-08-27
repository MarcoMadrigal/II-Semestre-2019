import java.util.Scanner;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class planilla{
  
  private boolean salir=false;
  private int opcion;
  
  private String nombre;
  private int Id;
  private String departamento;
  private String puesto;
  private String email;
  private double salario;
  private int telefono;
  private int edad;
  private String horario;

  private Trabajador aux;
  

  private boolean ingreso = false;
  private boolean putout = false;


  ArrayList<Trabajador> lista= new ArrayList<Trabajador>();

  Scanner mi_opcion = new Scanner(System.in);

  //Funcion para mostrar la lista
  public void mostrarTrabajador(){
  for(int i = 0; i < lista.size();i++)
    System.out.println(lista.get(i));


  }
  
 //Funcion para comparar y eliminar el empleado por medio del nombre
  public void eliminarTrabajador(){
    System.out.println("\nNombre del trabajador a despedir\n");
    nombre=mi_opcion.nextLine();
    nombre=mi_opcion.nextLine();
  

  for(int i = 0; i < lista.size();i++)    

    
    if(lista.get(i).getNombre().compareTo(nombre)==0){

      lista.remove(i);
      

    }
  
  }
  //Función para enseñar el perfilde un trabajador   
  public void iniciarTrabajador(){
    
    System.out.println("\nEscriba su nombre\n");
    nombre=mi_opcion.nextLine();
    nombre=mi_opcion.nextLine();
  

    for(int i = 0; i < lista.size();i++)    

    
      if(lista.get(i).getNombre().compareTo(nombre)==0){
        System.out.println("************************************\n");
        System.out.println(lista.get(i));
        System.out.println("************************************\n");

      }

  }
  
  //Menú de Trabajador
  public void MenuTrabajador(){
  
    while(!putout){
      try{    
        System.out.println("\n1.Ver información personal.\n");
        System.out.println("2. Registrar ingreso a trabajo.\n");
        System.out.println("3. Salir.\n");
        
        opcion=mi_opcion.nextInt();

        switch(opcion){
            
        case 1:
            iniciarTrabajador();
            break;
        case 2:
            ingreso = true;
            System.out.println("\nSu llegada se ha registrado correctamente.\n");
            break;
        case 3:
            putout = true;
            break;

          default:
            System.out.println("\nIntroduzca un número del 1 al 3.\n");
        
        }
      }catch(InputMismatchException e){
          System.out.println("\nIngrese un número o una letra.\n");
          
      }
    }
  }



  
  //Constructor de planilla
  public planilla(){
    
    
    //Menú de Recursos humanos
    while(!salir){
        System.out.println("\n0.Menú de Trabajador.\n");
        System.out.println("1.Ver planilla.\n");
        System.out.println("2.Ingresar un empleado.\n");
        System.out.println("3.Despido de un empleado.\n");
        System.out.println("4.Enviar salario.\n");
        System.out.println("5.Salir.\n");
      
      try{  
        opcion=mi_opcion.nextInt();

        switch(opcion){
            
          case 1:
            if (lista.isEmpty() == false){
            System.out.println("---------------------------------------------------------------");    
              mostrarTrabajador();
              System.out.println("---------------------------------------------------------------");

            }else{
              System.out.println("---------------------------------------------------------------");
              System.out.println("\nLista Vacía\n");
              System.out.println("---------------------------------------------------------------");
            }
                  
            break;
            
          case 2:
          
            System.out.println("\nNombre del trabajador:\n");
            nombre=mi_opcion.nextLine();
            nombre=mi_opcion.nextLine();
            
            System.out.println("\nId del trabajador:\n");
            Id=mi_opcion.nextInt();
        

            System.out.println("\nDepartamento:\n");
            departamento=mi_opcion.nextLine();
            departamento=mi_opcion.nextLine();

            System.out.println("\nPuesto:\n");
            puesto=mi_opcion.nextLine();


            System.out.println("\nEmail:\n");
            email=mi_opcion.nextLine();


            System.out.println("\nSalario:\n");
            salario=mi_opcion.nextDouble();


            System.out.println("\nTeléfono:\n");
            telefono=mi_opcion.nextInt();


            System.out.println("\nEdad:\n");
            edad=mi_opcion.nextInt();


            System.out.println("\nHorario:\n");
            horario=mi_opcion.nextLine();
            horario=mi_opcion.nextLine();
            aux=new Trabajador();

            aux.setNombre(nombre);
            aux.setId(Id);
            aux.setDepartamento(departamento);
            aux.setPuesto(puesto);
            aux.setEmail(email);
            aux.setSalario(salario);
            aux.setTelefono(telefono);
            aux.setEdad(edad);
            aux.setHorario(horario);

            lista.add(aux);
                  

            break;
            
          case 3:
            eliminarTrabajador();
            break;
            
          case 4:
            System.out.println("\nCantidad a depositar:\n");
            
            salario=mi_opcion.nextDouble();
            
            System.out.println("\nNombre al trabajador que se le realizará el deposito:\n");
            nombre=mi_opcion.nextLine();
            nombre=mi_opcion.nextLine();
            
            System.out.println("\nPeticion de depositar "
                              +salario+" Colones a "
                              +nombre+" enviada a Contabilidad\n");
            
            break;
            
          case 5:
            salir=true;
            break;

          case 0:
            MenuTrabajador();
            putout=false;
            break;
          
          default:
            System.out.println("Introduzca un número del 1 al 5");
        
        
        }  
      }catch(InputMismatchException e){
          System.out.println("Ingrese ya sea un número o una letra");

      }

    }
  
  }

}  


