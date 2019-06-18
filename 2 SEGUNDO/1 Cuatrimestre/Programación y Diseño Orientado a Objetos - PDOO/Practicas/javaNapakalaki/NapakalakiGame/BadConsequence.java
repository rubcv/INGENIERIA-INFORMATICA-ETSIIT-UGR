package NapakalakiGame;
import java.lang.*;

import java.util.ArrayList;

/**
 *
 * @author manjaro
 */

public abstract class BadConsequence {

    private String text="";
    private int levels;
    private static final int MAXTREASURES = 10;

    public BadConsequence(String text, int levels){
        this.text = text;
        this.levels = levels;
    }

    public String getText() {
        return text;
    }


    public int getLevels() {
        return levels;
    }

    public void setLevels(int l){
         this.levels = l;
    }

    public boolean isEmpty(){
         boolean empty = false;
         if(text == "" && levels == 0 ){
            empty = true;
         }
      return empty;
     }

    public abstract boolean isDeath();

    public abstract void setnVisibleTreasures(int n);

    public abstract void setnHiddenTreasures(int n);

    public abstract int getnVisibleTreasures();

    public abstract int getnHiddenTreasures();

    public abstract void substractVisibleTreasure(Treasure t);

    public abstract void substractHiddenTreasure(Treasure t);

    public abstract  BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v , ArrayList<Treasure> h);

    public abstract String toStringPendingVisible();

    public abstract String toStringPendingOculto();


}
