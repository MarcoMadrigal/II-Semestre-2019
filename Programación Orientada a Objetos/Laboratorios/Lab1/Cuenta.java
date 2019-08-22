/* 
Nombre: Marco Madrigal Pérez
Carnet: 2019053902
Programación Orientada a Objetos - Laboratorio 1
*/
import java.time.LocalDate; // Paquete para fechas y horas

public class Cuenta{

// Atributos privados de la clase cuenta
private int id;

private double balance;

private double tasaDeInteresAnual;

private LocalDate fechaDeCreacion;

  // Constructor sin parámetros
  public Cuenta(){
    id = 0;
    balance = 0;
    tasaDeInteresAnual = 0;
    fechaDeCreacion = LocalDate.now();

  }
  // Constructor con parámetros
  public Cuenta(int id, double balance){

    this.id = id;
    this.balance = balance;
    tasaDeInteresAnual = 0;
    fechaDeCreacion = LocalDate.now();
  }
  // Método para solicitar el id de una cuenta
  public int getId(int id){
    return this.id;

  }
  // Método para modificar el Id de una cuenta
  public void setId(int id){
    this.id = id;

  }
  //Método para solicitar el balance de una cuenta
  public double getBalance(){
    return this.balance;
  }
  // Método para modificar el balance de una cuenta
  public void setBalance(double balance){
    this.balance = balance;

  }
  // Método para solicitar la tasa de interés anual de una cuenta
  public double getTasaDeInteresAnual(double tasaDeInteresAnual){
    return this.tasaDeInteresAnual;
  }
  // Método para modificar la tasa de interés anual de una cuenta
  public void setTasaDeInteresAnual(double tasaDeInteresAnual){
    this.tasaDeInteresAnual = tasaDeInteresAnual;
  }
  // Método para solicitar la fecha de creación de una cuenta
  public LocalDate getFechaDeCreacion(){
    return this.fechaDeCreacion;
  }
  // Método para averiguar la tasa de interés mensual de una cuenta
  public double obtenerTasaDeInteresMensual(){
    return tasaDeInteresAnual/12;
  }
  // Método para calcular la tasa de Interés mensual
  public double calcularInteresMensual(){
    return balance*tasaDeInteresAnual;

  }
  // Método para retirar dinero de una cuenta, modifica el balance de la cuenta
  public double retirarDinero(double montoRetirado){
    this.balance = this.balance-montoRetirado;
    return balance;

  }
  // Método para depositar dinero a una cuenta, modifica el balance de la cuenta
  public double depositarDinero(double montoIngresado){
    this.balance = this.balance+montoIngresado;
    return balance;
  }
}
