
class Main { 
  public static void main(String[] args) {
    // Se crea un objeto de tipo Cuenta, usando el constructor con
    // parámetros
    Cuenta primera_cuenta = new Cuenta(1122,500000);

    // Se asigna la tasa de interés anual
    primera_cuenta.setTasaDeInteresAnual(0.045);

    // Se deposita dinero
    primera_cuenta.depositarDinero(150000);

    //Se retira dinero
    primera_cuenta.retirarDinero(200000);
    
    // Se imprime la información de la primera cuenta
    System.out.println("Primera cuenta"+ "\nBalance: "+primera_cuenta.getBalance()+"\nInterés Mensual: "+primera_cuenta.obtenerTasaDeInteresMensual()+"\nFecha: "+primera_cuenta.getFechaDeCreacion());

    /* Se crea un segundo objeto de tipo cuenta usando el constructor
    con parámetros */
    Cuenta segunda_cuenta = new Cuenta(2019,100000);

    // Se asigna información al segundo objeto creado
    segunda_cuenta.setTasaDeInteresAnual(0.050);
    segunda_cuenta.depositarDinero(100);

    // Se imprime la información de la segunda cuenta
    System.out.println("\nSegunda cuenta"+"\nBalance: "+segunda_cuenta.getBalance()+"\nInterés Mensual: "+segunda_cuenta.obtenerTasaDeInteresMensual()+"\nFecha: "+segunda_cuenta.getFechaDeCreacion());

    // Se crea un objeto de tipo ATM, para que se ejecute el código en ATM.java
    // El constructor básicamente contiene el código a ejecutar
    ATM cajeroautomatico = new ATM();
  }
}
