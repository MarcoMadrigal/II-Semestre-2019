package Main;
import java.util.ArrayList;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2019
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Supermercado {

    private String nombre;
    private ArrayList<Producto> inventario;
    private ArrayList<Membresia> membresias;
    private ArrayList<Cliente> clientes;

    public Supermercado(String nombre) {
        this.nombre = nombre;
        this.inventario = new ArrayList<Producto> ();
        this.membresias = new ArrayList<Membresia> ();
        this.clientes = new ArrayList<Cliente> ();
    }

    public ArrayList<Membresia> getMembresias() {
        return membresias;
    }

    public ArrayList<Producto> getInventario() {
        return inventario;
    }

    public ArrayList<Cliente> getClientes() {
        return clientes;
    }

    public void agregarMembresia(String nombre, float porcentajeDescuento){
        this.membresias.add(new Membresia(nombre,porcentajeDescuento));
    }

    public void agregarCliente(String nombre){
        this.clientes.add(new Cliente(nombre));
    }

    public void agregarCliente(String nombre, Membresia membresia){
        this.clientes.add(new Cliente(nombre,membresia));
    }

    public void agregarProductoInventarioVentaUnitaria(String nombre, float precioSinImpuesto, float porcentajeImpuesto){
        this.inventario.add(new Producto(nombre,precioSinImpuesto,porcentajeImpuesto,Producto.tipoVenta.POR_UNIDAD));
    }

    public void agregarProductoInventarioVentaPorPeso(String nombre, float precioSinImpuesto, float porcentajeImpuesto){
        this.inventario.add(new Producto(nombre,precioSinImpuesto,porcentajeImpuesto,Producto.tipoVenta.POR_PESO));
    }


    public void imprimirInventario(){
        System.out.println("---------------------------------------------------------");
        System.out.println(String.format("%54s", "Productos a la venta"));
        System.out.println("---------------------------------------------------------");
        this.inventario.forEach((producto) -> System.out.println(producto.toString()));
    }

    public void imprimirMembresias(){
        System.out.println("---------------------------------------------------------");
        System.out.println(String.format("%54s", "Membresias"));
        System.out.println("---------------------------------------------------------");
        this.membresias.forEach((membresia) -> System.out.println(membresia.toString()));
    }

    public void imprimirClientes(){
        System.out.println("---------------------------------------------------------");
        System.out.println(String.format("%54s", "Clientes   "));
        System.out.println("---------------------------------------------------------");
        this.clientes.forEach((cliente) -> System.out.println(cliente.toString()));
    }


    public void imprimirFactura(Factura factura){
        System.out.println("---------------------------------------------------------");
        System.out.println(String.format("%54s", "Compras "));
        System.out.println("---------------------------------------------------------");
        System.out.println(factura.toString());
    }


}
