package Main;
import java.util.HashMap;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2018
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Factura {

    private float sumaProductosConImpuesto = 0f;
    private float sumaProductosSinImpuesto = 0f;
    private float descuento = 0f;
    private float totalAPagar = 0f;
    private Cliente cliente;
    private Carrito carrito;

    public Factura(Cliente cliente, Carrito carrito) {
        this.cliente = cliente;
        this.carrito = carrito;
        facturar();
    }

    public Factura(Carrito carrito) {
        this.carrito = carrito;
        facturar();
    }

    public void facturar(){
        for(HashMap.Entry<Producto, Float> e : this.carrito.getProductosPorCantidad().entrySet()){
            float cantidad = e.getValue();
            Producto producto = e.getKey();

            if(producto.hasPromocion()){
                aplicarPromocion(cantidad,producto);
            }
            sumaProductosSinImpuesto = sumaProductosSinImpuesto + (producto.getPrecioSinImpuesto()*cantidad);
            sumaProductosConImpuesto = sumaProductosConImpuesto + (producto.getPrecioConImpuesto()*cantidad);
        }
        if(this.cliente != null && this.cliente.hasMembresia()){
            System.out.println("Descuento por membresia"+this.sumaProductosConImpuesto*this.cliente.getMembresia().getPorcentajeDescuento());
            this.descuento = this.descuento + this.sumaProductosConImpuesto*this.cliente.getMembresia().getPorcentajeDescuento();
        }
        totalAPagar = sumaProductosConImpuesto - this.descuento;
    }

    public void aplicarPromocion(float cantidad, Producto producto){
        Promocion promo = producto.getPromocion();
        float cantidadMinimaPromocion = promo.getCantidad();
        while(cantidad >= cantidadMinimaPromocion){
            System.out.println("Descuento por promo "+promo.getDescuento());
            this.descuento = this.descuento + promo.getDescuento();
            cantidad -= cantidadMinimaPromocion;
        }
    }


    @Override
    public String toString() {
        String info =  "";
        for(HashMap.Entry<Producto, Float> e : this.carrito.getProductosPorCantidad().entrySet()) {
            float cantidad = e.getValue();
            info = info + this.carrito.enttryToString(cantidad,e.getKey());
        }

        info = info + String.format("\n%32s", "Total")
                + String.format("\t%10.2f", this.sumaProductosSinImpuesto)
                + String.format("\t%10.2f", this.sumaProductosConImpuesto);

        if(this.descuento != 0){
            float totalAPagar = this.sumaProductosConImpuesto-this.descuento;
            info = info + String.format("\n%32s", "Descuento")
                    + String.format("\t%22.2f",this.descuento)
                    + String.format("\n%32s", "Total a pagar")
                    + String.format("\t%22.2f",totalAPagar);
        }
        return info;
    }
}
