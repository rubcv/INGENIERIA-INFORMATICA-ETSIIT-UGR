/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;
import java.util.Collections;
/**
 *
 * @author manjaro
 */
public class Player {
   static final int MAXLEVEL = 10;
   private String name;
   private int level;
   private boolean dead;
   private boolean canISteal;
   private BadConsequence pendingBadConsequence;
   private ArrayList<Treasure> hiddenTreasures;
   private ArrayList<Treasure> visibleTreasures;
   Player enemy;


   public Player(String name){
       this.name = name;
       level = 1;
       dead = true;
       canISteal = true;
       pendingBadConsequence = null;
       hiddenTreasures = new ArrayList<Treasure>();
       visibleTreasures = new ArrayList<Treasure>();
       enemy = null;
   }
   public Player(){ // Es necesario para poder inicializar los \
                   // atributos de tipo player de las otras clases sin tener que pasarles argumentos
       level = 1;
       dead = true;
       canISteal = true;
       pendingBadConsequence = null;
       hiddenTreasures = new ArrayList<Treasure>();
       visibleTreasures = new ArrayList<Treasure>();
       enemy = null;
   }

   public String getName(){
       return name;
   }

   private void bringToLife(){
       dead = true;
   }

   private int getLevels(){
       return level;
   }

   private void incrementLevels(int l){
       level += l;
   }

   private void decrementLevels(int l){
       level -= l;
   }

   private void setPendingBadConsequence(BadConsequence b){
       pendingBadConsequence = b;
   }



   private void applyPrize(Monster m){
       int niveles = m.getLevelsGained();
       incrementLevels(niveles);

       int tesoros = m.getTreasuresGained();

       if(tesoros > 0){
           CardDealer dealer = CardDealer.getInstance();

           for(int i = 0; i < tesoros; i++){
               Treasure t = dealer.nextTreasure();
               hiddenTreasures.add(t);
           }
       }
   }

   private void applyBadConsequence(Monster m){

     decrementLevels((m.getBC()).getLevels());
     if(level < 1){
       dead = true;
     }else{
       pendingBadConsequence = (m.getBC()).adjustToFitTreasureLists(visibleTreasures, hiddenTreasures);
       setPendingBadConsequence(pendingBadConsequence);
     }
   }

   private boolean canMakeTreasureVisible(Treasure t){
       boolean puede = false;

       if(visibleTreasures.size() < 4){
           puede = true;
          TreasureKind tipo = t.getType();

          int contOne = 0;

          if(tipo == TreasureKind.ONEHAND){
              for(Treasure aux : visibleTreasures){
                  if(aux.getType() == TreasureKind.BOTHHANDS){ // Contar los de  una mano
                    return false;
                  }else if(aux.getType() == TreasureKind.ONEHAND){
                    contOne++;
                  }
              }
          }
          if(contOne == 2){
            return false;
          }
            // Si es otro, ver que no esté


          for( Treasure tr : visibleTreasures){
              if(tr.getType() != TreasureKind.ONEHAND){
                  if(tr.getType() == t.getType()){
                      return false;
                  }
              }
          }
       }
   return puede;
}

   private int howManyVisibleTreasures(TreasureKind tKind){
        int contador = 0;
        for (Treasure t : this.visibleTreasures) {
            if (t.getType() == tKind) {
                contador++;
            }
        }
        return contador;
   }

   private void dieIfNoTreasures(){
     if (this.visibleTreasures.isEmpty() && this.hiddenTreasures.isEmpty()) {
            this.dead = true;
     }
   }
   public boolean isDead(){
       return dead;
   }


   public ArrayList<Treasure> getHiddenTreasures(){
       return hiddenTreasures;
   }

   public ArrayList<Treasure> getVisibleTreasures(){
       return visibleTreasures;
   }

   public CombatResult combat(Monster m){
       CombatResult result = null;
       int myLevel = getLevels();
       int monsterLevel = m.getCombatLevel();

       if(!canISteal){
         Dice dice = Dice.getInstance();
         int number = dice.nextNumber();
         if(number < 3){
           int enemyLevel = enemy.getLevels();
           monsterLevel += enemyLevel;
         }
       }

       if(myLevel > monsterLevel){
         if(myLevel >= MAXLEVEL){
           result = CombatResult.WINGAME;
         }else{
           result = CombatResult.WIN;
         }
         applyPrize(m);
       }else{

         result = CombatResult.LOSE;
         applyBadConsequence(m);
       }

    return result;
   }

   public void makeTreasureVisible(ArrayList<Treasure> treasures){
     for(Treasure t : treasures){
       boolean canI = canMakeTreasureVisible(t);
       if(canI){
         visibleTreasures.add(t);
         hiddenTreasures.remove(t);
       }
     }
   }

   public void discardVisibleTreasure(Treasure t){
       visibleTreasures.remove(t);
   }

   public void discardHiddenTreasure(Treasure t){
       hiddenTreasures.remove(t);
   }
   public boolean validState(){
         return (this.pendingBadConsequence == null || (this.pendingBadConsequence.isEmpty() && this.hiddenTreasures.size() <= 4));
   }

   public void initTreasures(){
        CardDealer dealer = CardDealer.getInstance();

        Dice dice = Dice.getInstance();

        this.bringToLife();

        Treasure treasure = dealer.nextTreasure();
        this.hiddenTreasures.add(treasure);

        int number = dice.nextNumber();


        if (number > 1){
            treasure = dealer.nextTreasure();
            this.hiddenTreasures.add(treasure);
        }else
        if (number == 6) {
          treasure = dealer.nextTreasure();
          this.hiddenTreasures.add(treasure);
        }

   }

   public void getLevelsFromTreasures(){
       // Tesoros solo visibles
       for(Treasure t : visibleTreasures){
           level += t.getBonus();
       }
   }

   public Treasure stealTreasure(){

     Treasure treasure = null;
     boolean canI = canISteal();
     if(canI){
       boolean canYou = canYouGiveMeATreasure();

       if(canYou){
         treasure = enemy.giveMeATreasure();
         hiddenTreasures.add(treasure);
         haveStolen();
       }
     }
     return treasure;
   }

   public void setEnemy(Player enemy){
     this.enemy = enemy;
   }

   private Treasure giveMeATreasure(){
     Treasure t = new Treasure("", 0, null);
     if(enemy.canYouGiveMeATreasure()){
       t = enemy.getHiddenTreasures().get(0);
       enemy.hiddenTreasures.remove(t);
     }
      return t;
   }

   public boolean canISteal(){
       return canISteal;
   }

   private boolean canYouGiveMeATreasure(){
    if(!(this.hiddenTreasures.isEmpty())) {
      return true;
    }else{
        return false;
    }
   }

   private void haveStolen(){
    if(canISteal){
        canISteal = false;
    }
   }

   public void discardAllTreasures(){
       visibleTreasures.clear();
       hiddenTreasures.clear();
   }

   public String toString(){
     return ( name + "\nLevel: " + level + " hiddenTreasures: " + hiddenTreasures + " visibleTreasures: " + visibleTreasures);
   }

}
