/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetos;
 
/**
 *
 * @author ana
 */
 
    class Persona{
        String nombre;
        int edad;
        Direccion dir;
    
    Persona(String n, int e, Direccion d) {
        this.nombre=n;
        this.edad=e;
        this.dir=d;
    }
    
    @Override
    public boolean equals(Object obj) {
        // Son iguales si sus nombres y edades coinciden
        Persona per = (Persona) obj;
        return ((this.nombre == per.nombre) && (this.edad == per.edad));
    }
    
    
}
