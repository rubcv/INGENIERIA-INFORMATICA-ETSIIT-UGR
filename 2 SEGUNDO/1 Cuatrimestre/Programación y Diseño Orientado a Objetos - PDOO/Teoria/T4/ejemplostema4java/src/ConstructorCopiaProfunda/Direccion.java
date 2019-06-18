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
class Direccion {
     String calle;
      int numero;
      String codigoPostal;
      String ciudad;

    public Direccion(Direccion dc) {
        this.calle = dc.calle;
        this.numero =dc.numero;
        this.codigoPostal = dc.codigoPostal;
        this.ciudad = dc.ciudad;    
    } 
     public Direccion(String calle, int num, String cp, String ciudad) {
        this.calle = calle;
        this.numero = num;
        this.codigoPostal = cp;
        this.ciudad = ciudad;    
    } 
}
