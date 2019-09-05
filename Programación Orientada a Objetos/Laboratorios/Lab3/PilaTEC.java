import java.util.ArrayList;

// Se extiende la clase PilaTEC de ArrayList
public class PilaTEC extends ArrayList{

  // Constructor de la clase
  public PilaTEC(){
    super();
  }

  // Función para saber si la lista está vacía
  public boolean isEmpty(){
    return super.isEmpty();
  }

  // Función para conseguir el tamaño de la lista
  public int getSize(){
    return super.size();
  }

  // Función para conseguir un 
  public Object peek(){
    return super.get(getSize()-1);
  }

  public Object pop(){
    Object o = super.get(getSize()-1); super.remove(getSize()-1);
    return o;
  }

  public void push(Object o){
    super.add(o);
  }

  @Override
  public String toString(){
    return "pila: "+super.toString();

  }
}