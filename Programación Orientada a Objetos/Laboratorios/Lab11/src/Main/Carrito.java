package Main;
import java.util.HashMap;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2018
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Carrito {
    private HashMap<Producto, Float> productosPorCantidad;

    public Carrito() {
        this.productosPorCantidad = new HashMap<Producto, Float>();
    }

    public HashMap<Producto, Float> getProductosPorCantidad() {
        return productosPorCantidad;
    }

    public void agregarProductoUnitario(Producto producto){
        actualizarCantidadProducto(producto, 1f);
    }

    public void agregarProductoUnitario(Producto producto, int cantidad){
        actualizarCantidadProducto(producto, (float)cantidad);
    }

    public void agregarProductoPorPeso(Producto producto, float cantidad){
        actualizarCantidadProducto(producto, cantidad);
    }

    public void actualizarCantidadProducto(Producto producto, float cantidad){
        if(this.productosPorCantidad.get(producto) == null){
            this.productosPorCantidad.put(producto,cantidad);
        }else{
            float cantidadActual = this.productosPorCantidad.get(producto);
            this.productosPorCantidad.put(producto,cantidadActual+cantidad);
        }
    }

    public String enttryToString(float cantidad, Producto producto){
        String info;
        info =  String.format("\n\t%-3.2f", cantidad)
                + String.format("\t%20s", producto.getNombre())
                + String.format("\t%10.2f", producto.getPrecioSinImpuesto()*cantidad)
                + String.format("\t%10.2f", producto.getPrecioConImpuesto()*cantidad);
        return info;
    }
}
