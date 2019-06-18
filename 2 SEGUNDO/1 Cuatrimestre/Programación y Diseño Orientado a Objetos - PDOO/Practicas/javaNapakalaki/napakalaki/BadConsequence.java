/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;

/**
 *
 * @author manjaro
 */
public class BadConsequence {
    static final int MAXTREASURES = 10;
    private String text;
    private int levels;
    private int nVisibleTreasures;
    private int nHiddenTreasures;
    private boolean death;
    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList<TreasureKind>();
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList<TreasureKind>();

    public boolean isEmpty(){
        return ((nVisibleTreasures == 0) && (nHiddenTreasures == 0) && (((specificHiddenTreasures.size() == 0) && (specificVisibleTreasures.size() == 0)) || ((specificHiddenTreasures == null) && (specificVisibleTreasures == null))));
    }

    public int getLevels(){
        return levels;
    }

    public int getnVisibleTreasures(){
        return nVisibleTreasures;
    }

    public int getnHiddenTreasures(){
        return nHiddenTreasures;
    }

    public ArrayList<TreasureKind> getHiddenTreasures(){
        return specificHiddenTreasures;
    }

    public ArrayList<TreasureKind> getVisibleTreasures(){
        return specificVisibleTreasures;
    }


    public void substractVisibleTreasure(Treasure uno){

            for (TreasureKind t: specificVisibleTreasures ){
                if (t.equals(uno.getType())){
                    specificVisibleTreasures.remove(t);
                    nVisibleTreasures--;
                }
            }
    }

    public void substractHiddenTreasure(Treasure uno){
            for (TreasureKind t: specificHiddenTreasures ){
                if (t.equals(uno.getType())){
                    specificHiddenTreasures.remove(t);
                    nHiddenTreasures--;
                }
            }
    }

    public BadConsequence(String text, int levels, int nVisible, int nHidden){
        this.text = text;
        this.levels = levels;
        this.nVisibleTreasures = nVisible;
        this.nHiddenTreasures = nHidden;
    }

    public BadConsequence(String text, boolean death){
        this.text = text;
        this.death = death;
    }

    public BadConsequence(String text, int levels, ArrayList<TreasureKind> tVisible, ArrayList<TreasureKind> tHidden){
        this.text = text;
        this.levels = levels;
        this.specificVisibleTreasures = tVisible;
        this.specificHiddenTreasures = tHidden;
    }

    public String getText(){
        return text;
    }


    public boolean getDeath(){
        return death;
    }

    public String toString(){
            return (" Text = " + text + " levels = " + Integer.toString(levels) + " Visible Treasures = " + Integer.toString(nVisibleTreasures) +  " Hidden Treasures = " + Integer.toString(nHiddenTreasures) + "\n" + "death = " + death +  " Specific Visible Treasures = " + specificVisibleTreasures + " Specific Hidden Treasures = " + specificHiddenTreasures);
    }

    public BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h){


        ArrayList<TreasureKind> visibleAux = new ArrayList<TreasureKind>();
        ArrayList<TreasureKind> hiddenAux = new ArrayList<TreasureKind>();

          for(Treasure t : v){
            if(!specificVisibleTreasures.contains(t.getType())){
              visibleAux.add(t.getType());
            }
          }

          for(Treasure t : h){
            if(!specificHiddenTreasures.contains(t.getType())){
              hiddenAux.add(t.getType());
            }
          }

        BadConsequence bc = new BadConsequence(text, 0, visibleAux, hiddenAux);

     return bc;

    }


}
