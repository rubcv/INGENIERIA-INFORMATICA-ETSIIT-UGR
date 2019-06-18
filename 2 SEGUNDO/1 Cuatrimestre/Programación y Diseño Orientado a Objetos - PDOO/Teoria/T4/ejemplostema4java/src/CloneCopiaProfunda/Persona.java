/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CloneCopiaProfunda; 
/**
 *
 * @author ana
 */
class Persona {   // No se requiere la Interfaz Cloneable porque ésta no define ningún método
        String nombre;
        int edad;
        Direccion dir;
    
    Persona(String n, int e, Direccion d) {
        this.nombre=n;
        this.edad=e;
        this.dir= new Direccion(d);
    }
    // uso del constructor de copia en profundidad
    @Override
    protected Object clone() throws CloneNotSupportedException {
       return  new Persona(nombre,edad,dir);
        
    }
}
