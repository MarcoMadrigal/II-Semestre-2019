IC-2101 Programación Orientada a Objetos

Prof: MSc. Samanta Ramijan Carmiol

Laboratorio 11 | Comprensión de Código y Archivos
En el laboratorio 7 realizamos un ejercicio de modelado para un pequeño Supermercado, en este laboratorio se espera a partir del código disponible en https://github.com/tec-ramijan/cursos/tree/master/programacion_orientada_objetos/08.ejercicio_supermercado/src y del diagrama de clases dispobible en https://github.com/tec-ramijan/cursos/blob/master/programacion_orientada_objetos/08.ejercicio_supermercado/ClasesSupermercado.png

a. Importe en su proyecto las clases:

● Carrito.java
● Cliente.java
● Factura.java
● Membresia.java
● Producto.java
● Promocion.java

b. Cree un archivo productos.xls que contenga la información de al menos 10 productos, con el siguiente formato:
Nombre          Precio sin impuesto     Porcentaje Impuesto    Tipo de Venta
Coca-Cola 2lt     1300                              0.13          UNIDAD
Tomate            700                               0.00           PESO

c. Cree una clase AdministradorArchivo.java que contenga un método que permita cargar el archivo de productos en la memoria del programa. Para esto investigue acerca del manejo de archivos en Java y recuerde manejar las posibles excepciones.

d. Cree su propia clase Main.java que cree una instancia de la clase supermercado, utilice la clase AdministradorArchivo.java para popular los productos y solicite al usuario el resto de la información restante de promociones y membresías para configurar el supermercado.
