/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

/**
 *
 * @author manjaro
 */
public class Treasure {
    private String name;
    private int bonus;
    private TreasureKind t;

    public Treasure(String n, int bonus, TreasureKind t){
        this.name = n;
        this.bonus = bonus;
        this.t = t;
    }

    public String getName(){
        return name;
    }

    public int getBonus(){
        return bonus;
    }

    public TreasureKind getType(){
        return t;
    }

    public String toString(){
      return ("Nombre: " + name + " Bonus: " + bonus + " Tipo: " + t + "\n");
    }
}
