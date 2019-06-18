/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.concurrent.ThreadLocalRandom;

/**
 *
 * @author manjaro
 */
public class Dice {
    static private Dice instance = null; // Variable instancia

    private Dice(){

    }

    public static Dice getInstance(){
        if(instance == null){
           instance = new Dice();
        }
      return instance;
    }

    public int nextNumber(){ // + 1 para incluir el 6
        int n = ThreadLocalRandom.current().nextInt(1, 6 + 1); // Calcula un numero aleatorio que es lanzar el dado
       return n;
    }
}
