/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetosConCompareTo; 

import CompararObjetos.*;
import CloneCopiaSuperficial.*;

/**
 *
 * @author ana
 */
// Ejemplo de comparación de objetos redefiniendo compareTo()
public class PruebasCompararObjetos {
   public static void main(String argsString[]) throws CloneNotSupportedException {

    
    Persona p1 = new Persona("Juan", 30);   
    Persona p2 = new Persona ("Juan", 30);
    Persona p3 = new Persona ("Antonio", 40);
     
      
    System.out.println("p1 es mayor que p2: " + (p1.compareTo(p2)) );
    System.out.println("p1 es mayor a p3: " + (p1.compareTo(p3)));
    System.out.println("P3 es mayor a p2: " + (p3.compareTo(p2))); 
     
    
    }  
} 
    

