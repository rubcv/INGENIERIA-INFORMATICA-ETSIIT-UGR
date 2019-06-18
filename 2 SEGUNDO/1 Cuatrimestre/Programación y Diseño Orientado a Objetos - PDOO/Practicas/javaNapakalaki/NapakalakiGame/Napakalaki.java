package NapakalakiGame;
import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author manjaro
 */

public class Napakalaki {


  private Player currentPlayer;
  private ArrayList<Player> players;
  private CardDealer dealer = CardDealer.getInstance();
  private Monster currentMonster;
  private static Napakalaki instance;


  private Napakalaki() {

  }
  public static Napakalaki getInstance() {
    if (instance == null) {
      instance = new Napakalaki();
    }
    return instance;
  }

  private void initPlayers(ArrayList<String> names){
      players = new ArrayList();
     for(String n : names){
       players.add(new Player(n));
      }
    currentPlayer = nextPlayer();
  }

  private Player nextPlayer(){
          Player aux;
          int pos;
      if (currentPlayer == null){
        int numeroJugadores = players.size() - 1;
        pos = (int) (Math.random() * numeroJugadores);
        aux = players.get(pos);
        currentPlayer = aux;
      }else{
        pos = players.indexOf(currentPlayer);
        pos++;
        if(pos >= players.size()){
          aux = players.get(0);
          currentPlayer = aux;
        }else{
          aux = players.get(pos);
          currentPlayer = aux;
        }
      }


      return currentPlayer;
  }

  private boolean nextTurnAllowed(){

      boolean res = false;
        if(currentPlayer != null){
          res = currentPlayer.validState();
        }
      return res;
  }


  private void setEnemies(){

      int posAleatorio;
      int tamanio = players.size();
      for(Player p : players){
       posAleatorio = (int) (Math.random() * tamanio);
       while (players.get(posAleatorio) == p){
         posAleatorio = (int) (Math.random() * tamanio);
       }
       p.setEnemyPlayer(players.get(posAleatorio));
     }
  }

  public void initGame(ArrayList<String> player){

      initPlayers(player);
      setEnemies();
      dealer.initCards();
      nextTurn();
  }

  public boolean nextTurn(){

      boolean stateOK = false;

     stateOK = nextTurnAllowed();

     if(stateOK){

         currentMonster = dealer.nextMonster();
         currentPlayer = nextPlayer();

         boolean dead = currentPlayer.isDeath();

         if(dead){
             currentPlayer.initTreasures();
         }

     }
      return stateOK;
  }

  public void discardVisibleTreasures(ArrayList<Treasure> treasures){

    for(Treasure t : treasures){
      currentPlayer.discardVisibleTreasure(t);
      dealer.giveTreasureBack(t);
    }
  }

  public void discardHiddenTreasures(ArrayList<Treasure> treasures){

    for(Treasure t : treasures){
      currentPlayer.discardHiddenTreasure(t);
      dealer.giveTreasureBack(t);
    }
  }


  public CombatResult developCombat(){
    Monster m = currentMonster;
    CombatResult combatResult = currentPlayer.combat(m);

    if(combatResult == CombatResult.LOSEANDCONVERT){
     Cultist nueva =  dealer.nextCultist();
     CultistPlayer nuevoPlayer = new CultistPlayer(currentPlayer, nueva);
     int pos = players.indexOf(currentPlayer);
     players.set(pos, nuevoPlayer);

     for(Player p : players){
       if(p.getEnemy() == currentPlayer){
        p.setEnemyPlayer(nuevoPlayer);
        }
      }
    }
      dealer.giveMonsterBack(m);
      return combatResult;
  }

  public void makeTreasuresVisible(ArrayList<Treasure> treasures){

   for(Treasure t : treasures){
      currentPlayer.makeTreasureVisible(t);
    }
  }

  public Player getCurrentPlayer(){
    return currentPlayer;
  }

  public Monster getCurrentMonster(){
     return currentMonster;
  }

  public boolean endOfGame(CombatResult result){

      boolean fin = false;
      if(result.toString().equals("WINGAME")){
        fin = true;
      }
      return fin;
   }

}
