import java.util.ArrayList;

/* 
Programación Orientada a Objetos
Laboratorio 6 | Controlador de una casa
Marco Madrigal Pérez | 2019053902

Objetos electrónicos:

Televisor
Refrigerador
Lampara
Lavadora
Secadora
Computadora
Microondas
Abanicos
Triturador de basura
Extractor de aire
Ducha
*/

public class main{
    public static void main(String[] args){

        Habitacion casa = new Habitacion();

        
        casa.setCocina();
        System.out.println(casa.getCocina());
        System.out.println(casa.apagarCuarto("Cocina"));
        System.out.println(casa.encenderCuarto("Sala"));
        
        casa.setBanno();
    }

}

