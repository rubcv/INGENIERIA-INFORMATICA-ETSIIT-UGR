package NapakalakiGame;

import java.util.ArrayList;
import java.util.Arrays;



public class Player {

 private static final int MAXLEVEL = 10;
 private String name;
 protected int level;
 private boolean dead = true;
 private boolean canISteal = true;
 private ArrayList<Treasure> hiddenTreasures = new ArrayList<Treasure>();
 private ArrayList<Treasure> visibleTreasures = new ArrayList<Treasure>();
 protected Player enemy;
 private BadConsequence pendingBadConsequence = new NumericBadConsequence("",0,0,0);
 private boolean isCultist = false;
 private boolean texto = false;


 public Player (String nombre){
     name = nombre;
     level = 1 ;
 }

 public Player (Player p){

   name = p.name;
   level = p.level;
   dead = p.dead;
   canISteal = p.canISteal;
   hiddenTreasures = (ArrayList<Treasure>) (p.hiddenTreasures).clone();
   visibleTreasures =  (ArrayList<Treasure>) (p.visibleTreasures).clone();
   enemy = p.enemy;
   pendingBadConsequence = p.pendingBadConsequence;

 }

 protected int getOponentLevel(Monster m ){
     return m.getCombatLevel();
 }

 protected boolean shouldConvert(){
     int dado = (int)(Math.random() * 5 + 1);
     boolean sol = false;
     if(dado == 1){
         sol = true;
     }
     return sol;
 }


 public boolean isDeath(){

    boolean death = false;
    if(dead){
        death = true;
    }
    return death;
 }

   @Override
     public String toString(){
       
        String res = " "+ name +" Nivel: " + level+  "\n"
                + "Mal rollo a cumplir: " + pendingBadConsequence + "\n";
        return res ;
      }

 public String getName(){
     return name;
 }


 public Player getEnemy(){
     return enemy;
 }

 public BadConsequence getPendingBadConsequence(){
     return pendingBadConsequence;
 }

 public ArrayList<Treasure> getVisibleTreasures(){
     return visibleTreasures;
 }

 public ArrayList<Treasure> getHiddenTreasures(){
     return hiddenTreasures;
 }

 private void bringToLife(){
     dead = false;
 }

 protected int getLevelTreasures(){
   int res  = 0;
   for (Treasure iterador: visibleTreasures){
      res = res+ iterador.getBonus();
    }
    return res;
 }

 protected int getCombatLevel(){
    int combatLevel = getLevelTreasures();
    combatLevel = combatLevel + level;

    return combatLevel;
 }

 private void incrementLevels(int i){

     if(level+i >= MAXLEVEL){
        level = MAXLEVEL;
     }else{
        level = level + i;
     }
 }
 private void decrementLevels(int i){

     if(level-i <= 1){
        level = 1;
     }else{
        level = level - i;
     }
 }

 private void setPendingBadConsequence(BadConsequence b){
    pendingBadConsequence = b;
 }

 private void dieIfNoTreasures(){
   if(hiddenTreasures.isEmpty()  && visibleTreasures.isEmpty()){
     dead = true;
    }
 }

 public boolean validState(){

     boolean res=true;

     if(!(pendingBadConsequence.isEmpty()) || hiddenTreasures.size() > 4){
       res = false;
     }
     return res;
 }

  public int getLevel(){
     return level;
 }

  protected int howManyVisibleTreasures(TreasureKind tKind){
    int res = 0;

   for (Treasure iterador: visibleTreasures){
      if(iterador.getType() == tKind){
        res++;
      }
    }
     return res;
  }

  protected int howManyHiddenTreasures(TreasureKind tKind){
    int res = 0;
     for (Treasure iterador: visibleTreasures){
      if(iterador.getType() == tKind){
        res++;
      }
    }
   return res;
  }

  public void setEnemyPlayer(Player enemy){
      this.enemy = enemy;
  }

  public boolean canISteal(){
      return canISteal;
  }

  private void haveStolen(){
      canISteal = false;
  }

  private boolean canYouGiveMeATreasure(){
      boolean res = false;

      if(hiddenTreasures.size()> 0){
          res = true;
      }
    return res;
  }


  public boolean canMakeTreasureVisible(Treasure t){

    boolean res=true;

    if(visibleTreasures.size()<4){

    TreasureKind elemento = t.getType();

    switch (elemento){

    case ONEHAND:

        if (howManyVisibleTreasures(TreasureKind.BOTHHANDS)>0) {
            res = false;
        } else {
          int i = 0;
          for (Treasure tv : this.visibleTreasures) {
              if (tv.getType() == (TreasureKind.ONEHAND)) {
                  i++;
              }
          }
          if (i == 2) {
              res = false;
          } else {
              res = true;
          }
        }
        break;

    case BOTHHANDS:
      if(howManyVisibleTreasures(TreasureKind.ONEHAND)>0){
          res = false;
      } else {
        int j = 0;
        for (Treasure tv : this.visibleTreasures) {
            if (tv.getType() == (TreasureKind.BOTHHANDS)) {
                j++;
            }
        }

        if (j == 1) {
            res = false;
        } else {
            res = true;
        }
      }
      break;

    default:
        res = howManyVisibleTreasures(elemento)==0;
        break;
          }

      }else{
          res = false;
      }
  return res;
  }

  private void applyPrize(Monster m){
      this.incrementLevels(m.getLevelsGained());
      int tesoros = m.getTreasuresGained();

      CardDealer baraja = CardDealer.getInstance();

      for(int i = 0; i < tesoros; i++){
          hiddenTreasures.add(baraja.nextTreasure());
      }
  }

  private void applyBadConsequence(Monster m){

    BadConsequence bad = m.getBadConsequence();
    BadConsequence pendingBad;
    boolean actualizar = false;

    if(!(bad.isDeath())){

      pendingBad = bad.adjustToFitTreasureLists(visibleTreasures,hiddenTreasures);

      int niveles = pendingBad.getLevels();
      this.decrementLevels(niveles);

      pendingBad.setLevels(0);
      this.setPendingBadConsequence(pendingBad);
      muerto(actualizar);

    }else if(bad.isDeath()){
      actualizar = true;
      muerto(actualizar);
      this.decrementLevels(MAXLEVEL);
      this.discardAllTreasures();
     }
  }

  public boolean muerto(boolean muerte){

      if(muerte == true){
          texto = true;
      }else{
          texto = false;
      }
      return texto;
  }

  public boolean getT(){
      return texto;
  }

  public Treasure stealTreasure(){
      boolean canI = this.canISteal();
      Treasure treasure = null;

      if(canI){
          boolean canYou = enemy.canYouGiveMeATreasure();
          if(canYou){
              treasure=enemy.giveMeATreasure();
              this.hiddenTreasures.add(treasure);
              enemy.hiddenTreasures.remove(treasure);
              enemy.dieIfNoTreasures();
              this.haveStolen();
          }
      }
      return treasure;
  }

  private Treasure giveMeATreasure(){

       Treasure res;
       int posAleatorio;
       posAleatorio = (int) (Math.random() * hiddenTreasures.size());
       res = hiddenTreasures.get(posAleatorio);

       return res;
  }

  public void discardVisibleTreasure(Treasure t){

      visibleTreasures.remove(t);

      if((pendingBadConsequence != null) && (!pendingBadConsequence.isEmpty())){
            pendingBadConsequence.substractVisibleTreasure(t);
           if(pendingBadConsequence.getnVisibleTreasures() > 0){
            int n = pendingBadConsequence.getnVisibleTreasures();
            n--;
            pendingBadConsequence.setnVisibleTreasures(n);
           }
      }

      dieIfNoTreasures();
 }

  public void discardHiddenTreasure(Treasure t){

      hiddenTreasures.remove(t);

      if((pendingBadConsequence != null) && (!pendingBadConsequence.isEmpty())){
            pendingBadConsequence.substractHiddenTreasure(t);
        if(pendingBadConsequence.getnHiddenTreasures() > 0){
            int n = pendingBadConsequence.getnHiddenTreasures();
            n--;
            pendingBadConsequence.setnHiddenTreasures(n);

            }
      }

      dieIfNoTreasures();
  }

  public void discardAllTreasures(){
    ArrayList<Treasure> visible = new ArrayList();
    ArrayList<Treasure> oculto = new ArrayList();

    for(int i = 0; i< visibleTreasures.size(); i++){
        visible.add(visibleTreasures.get(i));
    }

     for(int i = 0; i< visible.size(); i++){
         this.discardVisibleTreasure(visible.get(i));
    }

    for(int i = 0; i< hiddenTreasures.size(); i++){
        oculto.add(hiddenTreasures.get(i));
    }

     for(int i = 0; i< oculto.size(); i++){
         this.discardHiddenTreasure(oculto.get(i));
    }
    dieIfNoTreasures();
  }

  public void initTreasures(){
    CardDealer dealer = CardDealer.getInstance();

    Dice dice = Dice.getInstance();

    this.bringToLife();

    Treasure treasure = dealer.nextTreasure();
    this.hiddenTreasures.add(treasure);

    int number = (int)(Math.random() * 5 + 1);


    if (number > 1){
        treasure = dealer.nextTreasure();
        this.hiddenTreasures.add(treasure);
    }else
    if (number == 6) {
      treasure = dealer.nextTreasure();
      this.hiddenTreasures.add(treasure);
    }
  }

  public CombatResult combat(Monster m){
      CombatResult combatResult;
      int myLevel = getCombatLevel();
      int monsterLevel = this.getOponentLevel(m);

      if(myLevel > monsterLevel){
          this.applyPrize(m);

          if(level >=MAXLEVEL){
                combatResult = CombatResult.WINGAME;
          }
          else{
               combatResult = CombatResult.WIN;
          }
      }else{
        this.applyBadConsequence(m);
        dieIfNoTreasures();

        if(this.shouldConvert()){
           isCultist = true;
           combatResult = CombatResult.LOSEANDCONVERT;

        }else{
          combatResult = CombatResult.LOSE;
        }
      }
    return combatResult;
  }

  public void makeTreasureVisible(Treasure t){

      boolean canI = canMakeTreasureVisible(t);

      if(canI){
          visibleTreasures.add(t);
          hiddenTreasures.remove(t);
      }
  }

  public boolean isCultist(){
    return isCultist;
  }

}
