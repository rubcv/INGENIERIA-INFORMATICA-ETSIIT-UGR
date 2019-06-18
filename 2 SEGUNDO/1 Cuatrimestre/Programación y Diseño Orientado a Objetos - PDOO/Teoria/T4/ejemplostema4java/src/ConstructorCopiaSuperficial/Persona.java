/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ConstructorCopiaSuperficial;

/**
 *
 * @author ana
 */
class Persona {
        String nombre;
        int edad;
        Direccion dir;
    
    // Constructor de copia superficial
    Persona(Persona pc) {
        this.nombre=pc.nombre;
        this.edad=pc.edad;
        this.dir=pc.dir;// Comparten la dirección (segundo nivel)
    }
    
    Persona(String n, int e, Direccion d) {
        this.nombre=n;
        this.edad=e;
        this.dir=d; 
    }
}
