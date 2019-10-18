package Main;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2019
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Promocion {
    private String nombre;
    private int cantidad;
    private float precio;
    private float descuento;

    private Producto producto;

    public Promocion(String nombre, int cantidad, float precio, Producto producto) {
        this.nombre = nombre;
        this.cantidad = cantidad;
        this.precio = precio;
        this.producto = producto;
        this.descuento = (producto.getPrecioConImpuesto()*cantidad) - precio;
    }

    public int getCantidad() {
        return cantidad;
    }

    public float getDescuento() {
        return descuento;
    }

    @Override
    public String toString() {
        return " ** " + " " + this.nombre;
    }
}
