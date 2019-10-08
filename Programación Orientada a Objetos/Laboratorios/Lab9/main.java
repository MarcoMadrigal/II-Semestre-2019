import java.util.Scanner;

import java.util.InputMismatchException;
public class main{
    //Clase Principal
    public static void main(String[] args){
        //Invoca a administrador y agrega 3 oficiales predeterminados
        Administrador admin= new Administrador();
        admin.AgregarOficial("Randall",19);
        admin.AgregarOficial("Jeremy",20);
        admin.AgregarOficial("Marco",21);
        
        Scanner sc= new Scanner(System.in); 
        
        //Menú del programa
        while(1==1){    
        try{
        System.out.println("\n-------------------------------------------------\n");
        System.out.println("\nOficiales registrados \n"+admin.getOficiales());
        System.out.println("\nOficial tiene que tener Nombre registrado y Contraseña = 1");
        System.out.println("Administrador por defecto Nombre= admin y Contraseña = 2\n");
        System.out.println("Iniciar Seción");
        System.out.println("\nNombre:");
        String nombre = sc.nextLine(); 
        System.out.println("\nContraseña:");
        int opcion = sc.nextInt();
        sc.nextLine();
        boolean go=admin.BuscarOficial(nombre);

        if (opcion == 1 && go==true){
            boolean out=false;
        while (!out){
            try{
            System.out.println("\n-----------------------------------------\n");
            System.out.println("\nBienvenido Oficial\n");
            System.out.println("\n¿Que acción desea realizar?\n");
            System.out.println("1. Ver Datos ");
            System.out.println("2. Ver Casos Asignados");
            System.out.println("3. Salir");
            int numero= sc.nextInt();
            sc.nextLine();
            switch (numero) {
                case 1:
                    System.out.println("\nOficial: "+ admin.ObtenerOficial(nombre).getName());
                    System.out.println("Número de oficial: "+ admin.ObtenerOficial(nombre).getNumOficial());

                    break;
                case 2:
                    admin.MostrarCasosParticulares(nombre);
                    admin.MostrarCasosRegulares(nombre);  
                    break;
                case 3:
                    out=true;
                    break;
                        
                default:
                    System.out.println("\nIngrese un número del 1 al 3\n");  
                    break;
            }
            }catch (InputMismatchException e) {
                System.out.println("\nIngrese un número del 1 al 3\n");   
                }
            
        }
    }
        else if(opcion == 2 && nombre.equals("admin")){
            boolean salir=false;
            while (!salir){
            try{
            System.out.println("\n----------------------------------------\n");
            System.out.println("\nBienvenido Administrador\n");
            System.out.println("\n¿Que acción desea realizar?\n");
            System.out.println("1. Asignar un Oficial a un Caso");
            System.out.println("2. Ver lista de Oficiales");
            System.out.println("3. Ver lista de Casos");
            System.out.println("4. Agregar un Oficial");
            System.out.println("5. Eliminar un Oficial");
            System.out.println("6. Eliminar un Caso");
            System.out.println("7. Salir");
            int numero= sc.nextInt();
            sc.nextLine();
            switch (numero) {
                
                case 1:
      
                    try{
                        System.out.println("\nNombre del Oficial:");
                        String name2 = sc.nextLine();
                        Boolean sigue=admin.BuscarOficial(name2);

                    
                        if (sigue ==true) {
                            System.out.println("\nTipo de Caso:\n");
                            System.out.println("1. Caso Particular");
                            System.out.println("2. Caso Regular");
                            int opp= sc. nextInt();
                            switch (opp) {
                                case 1:
                                
                                    Oficial oficial=admin.ObtenerOficial(name2);
                                    admin.AsignarCasoParticular(oficial);
                                    System.out.println("\n¡Se asignó Caso Particular correctamente!\n");
                            
                                    break;
                                case 2:
                                    Oficial oficial2=admin.ObtenerOficial(name2);
                                    admin.AsignarCasoRegular(oficial2);
                                    System.out.println("\n¡Se asignó Caso Particular correctamente!\n");
                                    
                                    break;
                                default:
                                    System.out.println("Por favor ingrese un número del 1 al 2");
                                break;
                            }    
                        }
                        else{

                            System.out.println("\nOficial no registrado\n");    
                        }
                    }catch (InputMismatchException e) {
                        System.out.println("\nIngrese un número del 1 al 2\n");   
                        }
                    
                    
                    break;
                
                
                case 2:
                    System.out.println("\n"+admin.getOficiales());   
                    break;
                
                
                case 3:
                    admin.MostrarTodo();
                    break;
                
                case 4:
                    try{
                        System.out.println("\nNombre del oficial: ");
                        String nomb= sc.nextLine();
                        System.out.println("\nNúmero del oficial: ");
                        int numm= sc.nextInt();
                        admin.AgregarOficial(nomb, numm);
                    }catch(InputMismatchException e){
                        System.out.println("\nIntroduzca bien las credenciales");
                        sc.nextLine();
                    }   
                case 5:
                try{
                    System.out.println("\nNombre del oficial: ");
                    String nom= sc.nextLine();
                    admin.eliminarOficial(nom);
                    }catch(InputMismatchException e){
                    System.out.println("\nIntroduzca bien las credenciales");
                    sc.nextLine();
                    }   
                    break;
                case 6:
                    try{
                    System.out.println("\nNombre del oficial: ");
                    String ofi= sc.nextLine();
                    System.out.println("\nNombre del Caso: ");
                    String caso= sc.nextLine();
                    admin.eliminarCasos(caso,ofi);
                    }catch(InputMismatchException e){
                    System.out.println("\nIntroduzca bien las credenciales");
                    sc.nextLine();
                    }   
                
                    break;
                
                case 7:
                    salir=true;
                    break;
                default:
                    System.out.println("\nIngrese un número del 1 al 5\n"); 
                    break;
            }
        
        
            }catch (InputMismatchException e){
                System.out.println("\nIngrese un número del 1 al 5\n");    
            }
        }
        }
        else{


            System.out.println("No estas registrado");
        }
    }catch(InputMismatchException e) {
        sc.nextLine();
        System.out.println("\nIntroduzca bien las credenciales");
    }





}

}
}