package Main;
import java.util.Scanner;



public class java {
    
    public static void main(String[] args){

 
        AdministradorArchivo admin = new AdministradorArchivo();
        admin.readFile();
        
        Supermercado supercito = new Supermercado("LOS PELELES");
        int indice;
        
        for(indice = 0; indice < admin.obtenerTamaño(); indice++){
            Producto item = admin.obtener(indice);
            
            if(admin.obtener(indice).getTipoVenta() == "POR_PESO"){
                supercito.agregarProductoInventarioVentaPorPeso(item.getNombre(), item.getPrecioSinImpuesto(), item.getPorcentajeImpuesto());
                
            }else{
                supercito.agregarProductoInventarioVentaPorPeso(item.getNombre(), item.getPrecioSinImpuesto(), item.getPorcentajeImpuesto());
            }
            
        }
        
        boolean loop = true;
        Scanner entrada = new Scanner(System.in);
        String nombre;
        String nombreProducto;
        float porcentajeDescuento;
        float porcentajeImpuesto;
        float precio;
        int opcionDos;
                
        while(loop == true){
            
            System.out.println("Elija una opción");
            System.out.println("1. Agregar una nueva membresia");
            System.out.println("2. Agregar cliente");
            System.out.println("3. Agregar nuevo producto al inventario");
            System.out.println("4. Imprimir inventario");
            System.out.println("5. Imprimir membresias");
            System.out.println("6. Imprimir clientes");
            System.out.println("7. Imprimir factura");
            System.out.println("8. Salir del programa");
    
            int opcion = entrada.nextInt();
            
            switch(opcion){
                case 1:
                    System.out.println("Ingrese el nombre de su membresía:");
                    nombre = entrada.next();
                    
                    System.out.println("Ingrese el porcentaje a descontar:");
                    porcentajeDescuento = entrada.nextFloat();
                    
                    supercito.agregarMembresia(nombre, porcentajeDescuento);
                    break;
                    
                case 2:
                    System.out.println("Ingrese el nombre del cliente");
                    nombre = entrada.next();
                    break;
                    
                case 3:
                    int opcionTres;
                    System.out.println("Ingrese el nombre del producto:");
                    nombreProducto = entrada.next();
                    
                    System.out.println("Ingrese el monto sin impuesto");
                    precio = entrada.nextFloat();
                    
                    System.out.println("Ingrese el porcentaje de impuesto");
                    porcentajeImpuesto = entrada.nextFloat();
                    
                    System.out.println("Elija de qué manera se valora su artículo");
                    System.out.println("1. Artículo unitario");
                    System.out.println("2. Artículo por peso ");
                    opcionTres = entrada.nextInt();
                    
                    if(opcionTres == 1){
                        supercito.agregarProductoInventarioVentaUnitaria(nombreProducto, precio, porcentajeImpuesto);
                    }else{
                        supercito.agregarProductoInventarioVentaPorPeso(nombreProducto, precio, porcentajeImpuesto);
                    }
                    
                    break;
                    
                case 4:
                    supercito.imprimirInventario();
                    
                    break;
                    
                case 5:
                    supercito.imprimirMembresias();
                    
                    break;
                    
                case 6:
                    supercito.imprimirClientes();
                    break;
                    
                case 7:
                    Carrito carrito = new Carrito();
                    System.out.println("Ingrese el nombre del cliente");
                    nombre = entrada.next();
                    
                    Cliente cliente = new Cliente(nombre);
                    
                    Factura factura = new Factura(cliente,carrito);
                    
                    supercito.imprimirFactura(factura);
                    break;
                    
                case 8:
                    loop = false;
                    break;
            }
        }
        
        
    }
}
