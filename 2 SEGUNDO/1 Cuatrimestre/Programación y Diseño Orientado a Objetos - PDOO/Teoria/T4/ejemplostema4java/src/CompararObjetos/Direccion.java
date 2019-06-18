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
     
 
}
