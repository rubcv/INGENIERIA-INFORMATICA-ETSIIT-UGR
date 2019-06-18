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
 
 class Direccion implements Cloneable{
      String calle;
      int numero;
      String codigoPostal;
      String ciudad;

    Direccion(String calle, int num, String cp, String ciudad) {
        this.calle = calle;
        this.numero = num;
        this.codigoPostal = cp;
        this.ciudad = ciudad;    
    } 
    
    // Para poder usar el método clone() por los objetos de esta clase es necesario redefinirlo  
    @Override
    protected Object clone() throws CloneNotSupportedException {
	return super.clone(); // indica que tiene la misma implementación que la proporcionada por Object
    }    
 
}
