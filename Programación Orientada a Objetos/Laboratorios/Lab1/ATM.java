import java.util.Scanner;

public class ATM{
  /* Se crea un constructor sin parámetros, para que desde el main se pueda
  llamar y ejecutar todo el código del cajero automático */
  public ATM(){
    // Se inicializa el arreglo de cuentas, creando 10 objetos de tipo Cuenta
    Cuenta[] arreglocuentas = new Cuenta[10];
      arreglocuentas[0] = new Cuenta(0,100000);
      arreglocuentas[1] = new Cuenta(1,100000);
      arreglocuentas[2] = new Cuenta(2,100000);
      arreglocuentas[3] = new Cuenta(3,100000);
      arreglocuentas[4] = new Cuenta(4,100000);
      arreglocuentas[5] = new Cuenta(5,100000);
      arreglocuentas[6] = new Cuenta(6,100000);
      arreglocuentas[7] = new Cuenta(7,100000);
      arreglocuentas[8] = new Cuenta(8,100000);
      arreglocuentas[9] = new Cuenta(9,100000);

  // Se crea un objeto de tipo Scanner para las entradas del usuario
  Scanner entrada = new Scanner(System.in);

/* Ciclo principal para la ejecución infinita del programa, ya que no debe terminar
según las instrucciones*/
while(true){
  System.out.print("\nIngrese su id: "); 
  int numeroCuenta = entrada.nextInt(); // Se utiliza el objeto de tipo Scanner para guardar la entrada
  boolean estado = true;

 if (numeroCuenta < 10){
   // Ciclo para la ejecución del menú del cajero
  while(estado){
    System.out.println("\nMenú Principal\n"
                     + "1. Ver el balance actual\n"
                     + "2. Retirar dinero\n"
                     + "3. Depositar dinero\n"
                     + "4. Salir\n");

    System.out.print("Ingrese su opción: ");
    int opcion = entrada.nextInt();

    if (opcion == 1){
      // Se imprime el balance de la cuenta
      System.out.println("\nEl balance es de: "+arreglocuentas[numeroCuenta].getBalance());
    }
    if (opcion == 2){
      // Se ingresa el monto a retirar de la cuenta
      System.out.print("Ingrese el monto a retirar: ");
      double montoRetirar = entrada.nextInt(); // Se guarda la entra del usuario
      arreglocuentas[numeroCuenta].retirarDinero(montoRetirar); // Se realiza el retiro
    }
    if (opcion == 3){
      // Se ingresa el monto a depositar de la cuenta
      System.out.print("Ingrese el monto a depositar: ");
      double montoDepositar = entrada.nextInt(); // Se guarda la entrada del usuario
      arreglocuentas[numeroCuenta].depositarDinero(montoDepositar); // Se realiza el depósito
    }
    if (opcion == 4){
      estado = false; /* Se cambia la variable estado a false, para que se deje de
      ejecutar el ciclo del menú principal */
    }
    
  }
      
  }else{
    // Si el id no corresponde a ninguna cuenta, se imprime este mensaje y vuelve a iniciar el ciclo.
    System.out.println("No es el id correcto\n");
  }
}
  }
}