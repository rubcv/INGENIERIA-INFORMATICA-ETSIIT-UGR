/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompararObjetosDefiniendoComparador;

import java.util.Comparator;

/**
 *
 * @author ana
 */
public class PersonaComparador implements Comparator<Persona>{

    @Override
    public int compare(Persona p1, Persona p2) {
       // El criterio de comparación puede ser todo lo complejo que queramos
       // en este caso va a ser la edad
       
        int resultado = 0;
        if (p1.edad < p2.edad)
            resultado = -1;
        else if(p1.edad > p2.edad)
            resultado = 1;
        return resultado;
         
    // Podéis probar cambiando el criterio de orden, por ejemplo el nombre          
    
    }
    
}
