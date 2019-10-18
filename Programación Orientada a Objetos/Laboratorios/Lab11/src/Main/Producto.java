package Main;
/**********************************************************************
 Instituto Tecnológico de Costa Rica
 Estructuras de Datos IC-2001
 II Semestre 2018
 Profesora: Samanta Ramijan Carmiol

 Ejemplos Prácticos: Aplicacion Completa
 **********************************************************************/
public class Producto extends Object{

    enum tipoVenta {
        POR_PESO,
        POR_UNIDAD
    }

    private static int contador = 1;
    private int id;
    private String nombre;

    private float precioSinImpuesto;
    private float porcentajeImpuesto;
    private float precioConImpuesto;
    private tipoVenta tipo;
    private Promocion promocion;

    public Producto(String nombre, float precioSinImpuesto, float porcentajeImpuesto, tipoVenta tipo) {
        this.id = contador++;
        this.nombre = nombre;
        this.precioSinImpuesto = precioSinImpuesto;
        this.porcentajeImpuesto = porcentajeImpuesto;
        this.tipo = tipo;
        precioConImpuesto = precioSinImpuesto + (precioSinImpuesto*porcentajeImpuesto);
    }
    

    public String getNombre() {
        return nombre;
    }

    public float getPrecioSinImpuesto() {
        return precioSinImpuesto;
    }

    public float getPrecioConImpuesto() {
        return precioConImpuesto;
    }
    
    public String getTipoVenta(){
        return tipo.name();
        
    }
    
    public float getPorcentajeImpuesto(){
        return porcentajeImpuesto;
        
    }
    
    public void setPromocion(String nombre, int cantidad, float precio){
        this.promocion = new Promocion(nombre, cantidad, precio, this);
    }

    public Promocion getPromocion() {
        return promocion;
    }

    public boolean hasPromocion() {
        boolean hasPromo = false;
        if(promocion!= null){
            hasPromo = true;
        }
        return hasPromo;
    }
    


    @Override
    public String toString() {
        String info;
        info = String.format("\t%-3d", this.id)
                + String.format("\t%20s", this.nombre)
                + String.format("\t%10.2f", this.precioSinImpuesto)
                + String.format("\t%10.2f", this.precioConImpuesto);
        if (this.promocion != null){
            info = info + this.promocion.toString();
        }
        return info;
    }
}
