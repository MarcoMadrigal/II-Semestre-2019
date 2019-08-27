//clase principal
public class Trabajador{

  private String nombre;
  private int id;
  private String departamento;
  private String puesto;
  private String email;
  private double salario;
  private int telefono;
  private int edad;
  private String horario;
//constructor con datos base
  public Trabajador(){
    nombre = "";
    id = 0;
    departamento = "";
    puesto="";
    email = "";
    salario = 0;
    telefono = 0;
    edad = 0;
    horario = "";
  }
//constructor con parametros a llamar
  public Trabajador(String nombre, int id){
    this.nombre = nombre;
    this.id = id;
    departamento = "";
    email = "";
    salario = 0;
    telefono = 0;
    edad = 0;
    horario = "";
  }
//miles de getters y setters
  public String getNombre() {
    return this.nombre;
  }

  public void setNombre(String nombre){
    this.nombre = nombre;
  }

  public int getId() {
    return this.id;
  }

  public void setId(int id){
    this.id = id;
  }

  public String getDepartamento() {
    return this.departamento;
  }

  public void setDepartamento(String departamento){
    this.departamento = departamento;
  }

  public String getPuesto() {
    return this.puesto;
  }

  public void setPuesto(String puesto){
    this.puesto = puesto;
  }

  public String getEmail() {
    return this.email;
  }

  public void setEmail(String email){
    this.email = email;
  }

  public double getSalario() {
    return this.salario;
  }

  public void setSalario(double salario){
    this.salario = salario;
  }

  public int getTelefono() {
    return this.telefono;
  }

  public void setTelefono(int telefono){
    this.telefono = telefono;
  }

  public int getEdad() {
    return this.edad;
  }

  public void setEdad(int edad){
    this.edad = edad;
  }

  public String getHorario() {
    return this.horario;
  }

  public void setHorario(String horario){
    this.horario = horario;
  }

  

  @Override
  public String toString(){
      
    StringBuilder sb = new StringBuilder();

    sb.append("\nNombre: ");
    sb.append(nombre);

    sb.append("\nID: ");
    sb.append(id);

    sb.append("\nDepartamento: ");
    sb.append(departamento);

    sb.append("\nPuesto: ");
    sb.append(puesto);

    sb.append("\nEmail: ");
    sb.append(email);

    sb.append("\nSalario: ");
    sb.append(salario);

    sb.append("\nTelefono: ");
    sb.append(telefono);

    sb.append("\nEdad: ");
    sb.append(edad);

    sb.append("\nHorario: ");
    sb.append(horario);

    return sb.toString();
  }

}
