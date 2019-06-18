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
public class Monster {
    private String name;
    private int combatLevel;
    private Prize premio;
    private BadConsequence bC;

    public Monster(String name, int combatLevel, BadConsequence bc, Prize prize){
        this.name = name;
        this.combatLevel = combatLevel;
        premio = prize;
        bC = bc;
    }

    public Monster(){
      this.name = "";
      this.combatLevel = -1;
      premio = new Prize(-1, -1);
      bC = new BadConsequence("", 0, 0, 0);
    }

    public String getName(){
        return name;
    }

    public int getCombatLevel(){
        return combatLevel;
    }

    public Prize getPremio(){
        return premio;
    }

    public BadConsequence getBC(){
        return bC;
    }

    public String toString(){
            return ("Name = " + name + " Combat level = " + Integer.toString(combatLevel) + "\n" + premio + "\n" + bC + "\n\n");
    }

    public int getLevelsGained(){
        return premio.getLevels();
    }

    public int getTreasuresGained(){
        return premio.getTreasures();
    }
}
