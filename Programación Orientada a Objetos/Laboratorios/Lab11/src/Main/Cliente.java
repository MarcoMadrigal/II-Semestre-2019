package Main;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2018
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Cliente {
    private int id;
    private String nombre;
    private Membresia membresia;
    private static int contador = 1;

    public Cliente(String nombre) {
        this.id = contador++;
        this.nombre = nombre;
    }

    public Cliente(String nombre, Membresia membresia) {
        this.id = contador++;
        this.nombre = nombre;
        this.membresia = membresia;

    }

    public Membresia getMembresia() {
        return membresia;
    }

    public boolean hasMembresia(){
        boolean hasMembresia = this.membresia != null;
        return hasMembresia;
    }

    @Override
    public String toString() {
        String info;
        info = String.format("\t%-3d", this.id) + String.format("\t%-20s", this.nombre);
        if (this.hasMembresia()){
            info = info + String.format("\t%10s", this.getMembresia().getNombre());
        }
        return info;
    }
}
