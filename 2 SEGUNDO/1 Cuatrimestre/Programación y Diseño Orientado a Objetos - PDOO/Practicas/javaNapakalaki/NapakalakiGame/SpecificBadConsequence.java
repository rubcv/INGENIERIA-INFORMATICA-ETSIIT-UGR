package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author manjaro
*/

public class SpecificBadConsequence extends BadConsequence {
    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList();
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList();

    public SpecificBadConsequence(String text, int levels, ArrayList<TreasureKind> tVisible, ArrayList<TreasureKind> tHidden) {
        super(text, levels);
        this.specificHiddenTreasures = tHidden;
        this.specificVisibleTreasures = tVisible;
    }

    public ArrayList<TreasureKind> getVisibleTreasures(){

        return specificVisibleTreasures;
    }

    public ArrayList<TreasureKind> getHiddenTreasures(){

        return specificHiddenTreasures;
    }

    private String ArrayToString(ArrayList<TreasureKind> datos){
        String uno="" ;

        for (TreasureKind t: datos){
            uno += t.toString() + "\t";
        }
        return uno;

    }

     @Override
     public boolean isDeath(){
       return false;
     }

     @Override
     public void setnVisibleTreasures(int n){}

     @Override
     public void setnHiddenTreasures(int n){}

     @Override
     public int getnVisibleTreasures(){
         return 0;
     }

     @Override
     public int getnHiddenTreasures(){
         return 0;
     }

     @Override
     public void substractVisibleTreasure(Treasure t){

        for(int i =0; i< specificVisibleTreasures.size(); i++){
             if(t.getType() == specificVisibleTreasures.get(i)){
                 specificVisibleTreasures.remove(i);
             }
        }
     }

     @Override
     public void substractHiddenTreasure(Treasure t){

         for(int i =0; i< specificHiddenTreasures.size(); i++){
             if(t.getType() == specificHiddenTreasures.get(i)){
                 specificHiddenTreasures.remove(i);

             }
        }
     }

     @Override
     public  BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v , ArrayList<Treasure> h){

         BadConsequence uno;

          ArrayList<TreasureKind> visibles = new ArrayList();
          ArrayList<TreasureKind> ocultos = new ArrayList();

           for(Treasure iterador:v){
               if(this.specificVisibleTreasures.contains(iterador.getType())){
                   visibles.add(iterador.getType());
               }
           }

          for(Treasure iterador:h){
               if(this.specificHiddenTreasures.contains(iterador.getType())){
                   ocultos.add(iterador.getType());
               }
           }
           uno =  new SpecificBadConsequence("",super.getLevels(),visibles,ocultos);
          return uno;
        }

     @Override
       public boolean isEmpty(){
           boolean uno = false;
           if(super.getText() == "" && super.getLevels() == 0 && specificHiddenTreasures.isEmpty() && specificVisibleTreasures.isEmpty() ){
              uno = true;
           }
          return uno;
       }

     @Override
     public String toString(){

        String uno = super.getText() + "\n Pierdes " + super.getLevels() + " niveles "
                +  "\nTesoros visibles: " + ArrayToString(specificVisibleTreasures)
                + "\nTesoros ocultos: " + ArrayToString(specificHiddenTreasures) + "\n";
          return uno;
      }

     public String toStringPendingVisible(){
         String uno = ArrayToString(specificVisibleTreasures);
         return uno;
     }

     public String toStringPendingOculto(){
         String uno = ArrayToString(specificHiddenTreasures);
         return uno;
     }

}
