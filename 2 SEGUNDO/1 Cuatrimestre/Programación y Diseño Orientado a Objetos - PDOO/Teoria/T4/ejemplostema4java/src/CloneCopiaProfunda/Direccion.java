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
class Direccion {   // No se requiere la Interfaz Cloneable porque ésta no define ningún método
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
    public Direccion(Direccion dc) {
        this.calle = dc.calle;
        this.numero =dc.numero;
        this.codigoPostal = dc.codigoPostal;
        this.ciudad = dc.ciudad;    
    } 
    // Uso de constructor de copia en profundidad  
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return new Direccion (calle,numero,codigoPostal,ciudad);
    }    
}
