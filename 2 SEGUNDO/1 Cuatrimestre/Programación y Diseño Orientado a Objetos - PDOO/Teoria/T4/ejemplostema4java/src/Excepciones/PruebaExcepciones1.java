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
public class PruebaExcepciones1 {
     public static void main(String argsString[])   {
         
         try{
            Direccion d1= new Direccion("Calle del Agua", 58, "18888", "Murcia");
            System.out.println("Constructor usado con valores correctos");
            d1.setCodigoPostal("1234");
            System.out.println("modificador usado con valor erróneo");
         } catch(Exception e){
             System.err.println(e);
         } 
     }
}
