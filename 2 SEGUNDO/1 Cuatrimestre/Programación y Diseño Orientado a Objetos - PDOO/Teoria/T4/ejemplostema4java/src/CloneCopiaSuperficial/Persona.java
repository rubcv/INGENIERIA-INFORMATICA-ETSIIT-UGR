/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CloneCopiaSuperficial;

/**
 *
 * @author ana
 */
 
    class Persona implements Cloneable{
        String nombre;
        int edad;
        Direccion dir;
    
    Persona(String n, int e, Direccion d) {
        this.nombre=n;
        this.edad=e;
        this.dir=d;
    }
    
    // para poder usar el método clone() por los objetos de esta clase es necesario redefinirlo
    @Override
    protected Object clone() throws CloneNotSupportedException {
	return super.clone(); // indica que tiene la misma implementación que la proporcionada por Object
    }
    
}
