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
class Persona {
    String nombre;
        int edad;
        Direccion dir;
    
   Persona(String n, int e, Direccion d) {
        this.nombre=n;
        this.edad=e;
        this.dir=d;
    }
    Persona(Persona pc) {
        this.nombre=pc.nombre;
        this.edad=pc.edad;
        this.dir= new Direccion(pc.dir);
    }
    
}
