package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author manjaro
 */

public class NumericBadConsequence extends BadConsequence  {
    private int nVisibleTreasures;
    private int nHiddenTreasures;

    public NumericBadConsequence(String text, int levels , int nVisible, int nHidden) {

        super(text, levels);
        this.nVisibleTreasures = nVisible;
        this.nHiddenTreasures = nHidden;
    }

    @Override
    public boolean isDeath() {
        return false;
    }

    @Override
    public void substractVisibleTreasure(Treasure t){}

    @Override
    public void substractHiddenTreasure(Treasure t){}

    @Override
    public void setnVisibleTreasures(int n) {
        nVisibleTreasures = n;
    }

    @Override
    public void setnHiddenTreasures(int n) {
        nHiddenTreasures = n;
    }

    @Override
    public int getnVisibleTreasures() {
        return nVisibleTreasures;
    }

    @Override
    public int getnHiddenTreasures() {
        return nHiddenTreasures;
    }

    @Override
    public boolean isEmpty(){
       boolean res = false;
       if(super.getText() == "" && super.getLevels() == 0 && nVisibleTreasures == 0 && nHiddenTreasures == 0 ){
          res = true;
       }
       return res;
    }

    @Override
    public  BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v , ArrayList<Treasure> h){

      BadConsequence res;
      int visibles = 0;
      int ocultos = 0;
      int tamV = v.size();
      int tamH = h.size();

      if(nVisibleTreasures <= tamV ){
          visibles = nVisibleTreasures;

      }else if(tamV < nVisibleTreasures){
          visibles = tamV;
      }

      if(nHiddenTreasures <= tamH ){
          ocultos = nHiddenTreasures;
      }else if(tamH < nHiddenTreasures){
         ocultos = tamH;
      }
      res =  new NumericBadConsequence("", super.getLevels(), visibles, ocultos);
    return res;
 }

    @Override
     public String toString(){

        String res = super.getText() + "\nPierdes: " + super.getLevels() + " niveles "
                +  "\n" + Integer.toString(nVisibleTreasures)+" tesoros visibles\n"
                + Integer.toString(nHiddenTreasures) + " tesoros ocultos ";
      return res;
      }

     public String toStringPendingVisible(){
         String res = Integer.toString(nVisibleTreasures);
         return res;
     }

     public String toStringPendingOculto(){
         String res = Integer.toString(nHiddenTreasures);
         return res;
     }

}
