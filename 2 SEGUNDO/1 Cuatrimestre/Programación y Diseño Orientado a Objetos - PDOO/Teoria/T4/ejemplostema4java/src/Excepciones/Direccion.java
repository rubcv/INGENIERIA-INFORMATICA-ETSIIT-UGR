/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Excepciones; 
/**
 *
 * @author ana
 */
class Direccion {
      String calle;
      int numero;
      String codigoPostal;
      String ciudad;
 
     Direccion(String calle, int num, String cp, String ciudad) throws Exception {
        this.calle = calle;
        this.setNumero(num); // hay que hacerlo así para asegurarnos que es un valor correcto
        this.setCodigoPostal(cp); // igual """""
        this.ciudad = ciudad;    
    } 
    // Método en el que se lanza una excepción de tipo Exception definida en el propio lenguaje
     void setCodigoPostal(String cp) throws Exception
    {
        if(cp.length() != 5) throw new Exception("código postal erróneo");
        this.codigoPostal = cp;
    }
    // Médoto en el que se lanza una excepción definida por el usuario
    void setNumero(int numero) throws DireccionException{
        if(numero <= 0) throw new DireccionException("el numero proporcionado no es correcto, debe ser mayor que cero");
    
    } 
}
