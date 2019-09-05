import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    PilaTEC lista = new PilaTEC();
    int contador = 0;
    Scanner entrada = new Scanner(System.in);

    while(contador < 5){
      System.out.print("Ingrese un número entero: ");

      int numero = entrada.nextInt();
      lista.push(numero);
      contador++;

    }
    System.out.println();
    System.out.println("Se ingresaron los números");
    System.out.println(lista.toString());
    System.out.println();
  
    int tamaño = lista.getSize()-1;
    System.out.println("Los números son: ");
    while(tamaño >= 0){
      System.out.print(lista.get(tamaño)+" ");
      tamaño--;
    }
  }
}