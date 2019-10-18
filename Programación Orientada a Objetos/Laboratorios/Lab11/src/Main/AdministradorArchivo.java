package Main;

import static Main.Producto.tipoVenta.POR_PESO;
import static Main.Producto.tipoVenta.POR_UNIDAD;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class AdministradorArchivo {
    
    private ArrayList<Producto> listaProductos;
    private String nombre;
    private String tipoVenta;
    private float precioSinImpuesto;
    private float porcentajeImpuesto;
    
    
    public AdministradorArchivo(){
        listaProductos = new ArrayList<Producto>();
        
    }
    
    public int obtenerTamaño(){
        return listaProductos.size();
    }
    
    public void imprimirArrayList(){
        for(int ind = 0; ind < obtenerTamaño();){
            System.out.println(obtener(ind));
            ind++;
        }
    }
    
    
    public Producto obtener(int pos){
      return listaProductos.get(pos);
    }

    public void readFile(){
        try{
            FileInputStream file = new FileInputStream("productos.xlsx");
        
            XSSFWorkbook libro = new XSSFWorkbook(file);
               
            XSSFSheet hoja = libro.getSheetAt(0);
            
            Iterator<Row> filas = hoja.iterator();
            Iterator<Cell> celdas;
            
            Row fila;
            Cell celda;
            int contador = 0;
            while(contador < 1){
                fila = filas.next();
                contador++;
                
            }
            while(filas.hasNext()){
                fila = filas.next();
                
                celdas = fila.cellIterator();
                contador = 0;
                
                while(celdas.hasNext()){
                    celda = celdas.next();
                    
                    switch(celda.getCellType()){
                    
                        case Cell.CELL_TYPE_NUMERIC:
                            if(contador == 1){
                                precioSinImpuesto = (float)celda.getNumericCellValue();
                                contador++;
                                
                            }else{    
                                porcentajeImpuesto = (float)celda.getNumericCellValue();
                                contador++;
                            }
                        
                            break;
                            
                        case Cell.CELL_TYPE_STRING:
                            if(contador == 0){
                                nombre = celda.getStringCellValue();
                                contador++;
                            
                            }else{    
                                tipoVenta = celda.getStringCellValue();
                                contador++;
                            
                            }

                        
                            break;
                    }

                }
                if(tipoVenta == "Unidad"){
                    Producto producto = new Producto(nombre, precioSinImpuesto, porcentajeImpuesto, POR_UNIDAD);
                    listaProductos.add(producto);
                }else{
                    Producto producto = new Producto(nombre, precioSinImpuesto, porcentajeImpuesto, POR_PESO);
                    listaProductos.add(producto);
                }

            }
            
            imprimirArrayList();
           
            
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    
    }
            
}
