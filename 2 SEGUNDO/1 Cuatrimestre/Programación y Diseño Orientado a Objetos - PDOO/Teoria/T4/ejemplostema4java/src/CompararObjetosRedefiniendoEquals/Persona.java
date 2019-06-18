/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetosRedefiniendoEquals;
 
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
    @Override
    public boolean equals(Object obj2){
       if (obj2 == null) 
           return false;
       if (obj2 == this)
           return true;
       if (!(obj2.getClass().getSimpleName().equals("Persona")))
           return false;        
       Persona p1 = (Persona) obj2;
      if ( !this.nombre.equals(p1.nombre))
          return false;
      if (this.edad != p1.edad)
          return false;
      if(p1.dir == null || !this.dir.equals(p1.dir)) // devuelve true cuando dir es el mismo objeto
          return false;
      return true;
    }    
}
