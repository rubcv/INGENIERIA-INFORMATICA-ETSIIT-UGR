
package NapakalakiGame;

/**
 *
 * @author manjaro
 */

public class Treasure {
    private String dire;
    private String name ;
    private int bonus ;
    private TreasureKind type;

    public Treasure(String n, int bonus, TreasureKind t){
           name = n;
           this.bonus = bonus;
           type = t;
    }

    public String getName(){
        return name;
    }

    public int getBonus(){
        return bonus;
    }

    public TreasureKind getType(){
        return type;
    }

      @Override
     public String toString(){

        String tesoro = "Nombre = " + name + "\nBonus = " + Integer.toString(bonus)
               + "\nTipo = " + type.toString() + "\n";
        return tesoro;

      }
}
