package NapakalakiGame;
import java.lang.*;

/**
 *
 * @author manjaro
 */

public class Monster {
    private String name;
    private int combatLevel;
    private BadConsequence badConse;
    private Prize prize;
    private int levelChangeAgainstCultistPlayer = 0 ;

    public Monster(String name, int level, BadConsequence bc, Prize prize){
        this.name = name;
        combatLevel = level;
        badConse = bc;
        this.prize = prize;
    }

    public Monster(String name, int level, BadConsequence bc, Prize prize, int IC){
        this.name = name;
        combatLevel = level;
        badConse = bc;
        this.prize = prize;
        this.levelChangeAgainstCultistPlayer = IC;

    }

    public String getName() {
        return name;
    }

    public int getCombatLevel() {
        return combatLevel;
    }

    public BadConsequence getBadConsequence() {
        return badConse;
    }

    public int getLevelsGained() {
        return prize.getLevel();
    }

    public int getTreasuresGained(){
        return prize.getTreasures();
    }

    public Prize getPrize(){
        return prize;
    }

    public int getCombatLevelAgainstCultistPlayer(){
        int res ;
        res = this.getCombatLevel() + this.levelChangeAgainstCultistPlayer;
        return res;
    }


    @Override
     public String toString(){

        String monstruo = "Nombre: " + name + " CombatLevel = " + Integer.toString(combatLevel)
                + "\nBad Consequence: " + badConse.toString() + "\nPrize: " + prize.toString() + "\n";
        return monstruo;
      }

}
