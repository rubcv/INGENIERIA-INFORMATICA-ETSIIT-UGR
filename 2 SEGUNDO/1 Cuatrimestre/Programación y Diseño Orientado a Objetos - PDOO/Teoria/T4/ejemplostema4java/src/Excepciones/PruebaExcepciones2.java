/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Excepciones;

/**
 *
 * @author ana
 */
public class PruebaExcepciones2 {
      public static void main(String argsString[])   {
         
         try{
            Direccion d1= new Direccion("Calle del Agua", 58, "18888", "Murcia");
            System.out.println("Constructor usado con valores correctos");
            d1.setNumero(-5);
            System.out.println("modificador usado con valor erróneo");
         } catch(Exception e){
             System.err.println(e);
         } 
     // EJERCICIO: Modifica la clase Dirección para que el único 
     //    tipo de excepciones que lance sea de tipo DireccionException
     // Modifica todo lo que se te ocurra para ver cómo funcionan las excepciones
     // La funcionalidad general de las excepciones está definida en: 
         // http://docs.oracle.com/javase/7/docs/api/java/lang/Exception.html
    } 
}
