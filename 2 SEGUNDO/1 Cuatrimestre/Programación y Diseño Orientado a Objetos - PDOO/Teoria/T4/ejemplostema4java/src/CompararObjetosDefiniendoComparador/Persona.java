/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetosDefiniendoComparador;

import CompararObjetosConCompareTo.*;

/**
 *
 * @author ana
 */
 
    class Persona implements Comparable<Persona>{
        String nombre;
        int edad;
        
    
    Persona(String n, int e) {
        this.nombre=n;
        this.edad=e;        
    }

    @Override
    public int compareTo(Persona per) {
       // El criterio de comparación puede ser todo lo complejo que queramos
       // en este caso va a ser la edad
       
        int resultado = 0;
        if (edad < per.edad)
            resultado = -1;
        else if(edad > per.edad)
            resultado = 1;
        return resultado;
         
    // Podéis probar cambiando el criterio de orden, por ejemplo el nombre          
    }
    
    
}
