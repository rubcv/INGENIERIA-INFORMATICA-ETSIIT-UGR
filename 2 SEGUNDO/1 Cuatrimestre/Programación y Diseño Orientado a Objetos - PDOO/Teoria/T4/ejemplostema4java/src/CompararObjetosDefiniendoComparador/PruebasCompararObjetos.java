/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetosDefiniendoComparador; 
 

/**
 *
 * @author ana
 */
// Ejemplo comparador de objetos definiendo una clase para ello.
public class PruebasCompararObjetos {
   public static void main(String argsString[]) throws CloneNotSupportedException {

    
    Persona p1 = new Persona("Juan", 30);   
    Persona p2 = new Persona ("Juan", 30);
    Persona p3 = new Persona ("Antonio", 40);
     
    PersonaComparador pc = new PersonaComparador();
    System.out.println("p1 es mayor que p2: " + (pc.compare(p1, p2)) );
    System.out.println("p1 es mayor a p3: " + (pc.compare(p1, p3)));
    System.out.println("P3 es mayor a p2: " + (pc.compare(p3, p2))); 
     
    
    }  
} 
    

