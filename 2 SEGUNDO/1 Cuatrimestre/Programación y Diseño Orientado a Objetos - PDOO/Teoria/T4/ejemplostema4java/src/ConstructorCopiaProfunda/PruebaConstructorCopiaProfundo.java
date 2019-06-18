/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ConstructorCopiaProfunda;
 
/**
 *
 * @author ana
 */
public class PruebaConstructorCopiaProfundo {
     public static void main(String argsString[]) throws CloneNotSupportedException {

    Direccion d1= new Direccion("Calle del Agua", 58, "18888", "Murcia");

    Persona p1 = new Persona("Juan", 30, d1); 
    Persona p2 = new Persona(p1);
    System.out.println(p1.nombre);
    p2.nombre = "Luis";     
    System.out.println(p1.nombre); 

    System.out.println("La ciudad de " + p2.nombre + " es " + p2.dir.ciudad);
    p2.dir.ciudad = "Huelva";
    // En la copia profunda se crea un nuevo objeto para la dirección, 
    // por lo que son independientes uno de otro
    System.out.println("La ciudad de " + p1.nombre + " es " + p1.dir.ciudad);
    System.out.println("La ciudad de " + p2.nombre + " es " + p2.dir.ciudad);
}
}