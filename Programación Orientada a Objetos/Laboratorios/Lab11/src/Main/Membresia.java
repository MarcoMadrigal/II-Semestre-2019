package Main;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2018
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Membresia {
    private int id;
    private String nombre;
    private float porcentajeDescuento;
    private static int contador = 1;

    public Membresia(String nombre, float porcentajeDescuento) {
        this.nombre = nombre;
        this.porcentajeDescuento = porcentajeDescuento;
        this.id = contador++;
    }

    public String getNombre() {
        return nombre;
    }

    public float getPorcentajeDescuento() {
        return porcentajeDescuento;
    }

    @Override
    public String toString() {
        String info;
        info = String.format("\t%20s", this.nombre)
                + String.format("\t%10d%s", (int)(porcentajeDescuento*100),"% de descuento");
        return info;

    }
}
