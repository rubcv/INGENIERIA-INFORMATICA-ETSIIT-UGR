/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 *
 * @author manjaro
 */
public class Napakalaki {
    private static Napakalaki instance = null;
    private ArrayList<Player> players = new ArrayList<Player>(); // Array de jugadores
    private Player currentPlayer = new Player();
    private CardDealer dealer = CardDealer.getInstance();
    private Monster currentMonster = new Monster();

    private Napakalaki(){}

    private void initPlayers(ArrayList<String> nombres){
      players = new ArrayList<Player>();

       for(String s : nombres){
        players.add(new Player(s));
    }
   }
    private Player nextPlayer(){
        int proximoPos;
        int posActual;
        Player proximoPlayer;
        int total = players.size();

        if(currentPlayer == null){ // Si aun no hay jugador
           Random rand = new Random();
           proximoPos = rand.nextInt(total); // Numero aleatorio de 0 a "total" (Exclusivo)
        }else{
            posActual = players.indexOf(currentPlayer); // Sacar el indice del jugador actual

            if(posActual == total - 1){
                proximoPos = 0;
            }else{
                proximoPos = posActual + 1;
            }
        }
        proximoPlayer = players.get(proximoPos);
        currentPlayer = proximoPlayer;

        return currentPlayer;
    }

    private boolean nextTurnAllowed(){
           boolean puede;

           if(currentPlayer == null){
               puede = true;
           }else{
               puede = currentPlayer.validState();
           }
       return puede;
    }

    private void setEnemies(){
        Player p = null;
        while( p != currentPlayer){
            Collections.shuffle(players);
            p = players.get(0);
        }
          currentPlayer.enemy = p;
    }

    public static Napakalaki getInstance(){
        if(instance == null){
            instance = new Napakalaki();
        }
        return instance;
    }

    public CombatResult developCombat(){
      CombatResult combat = currentPlayer.combat(currentMonster);
      return combat;
    }

    public void discardVisibleTreasures(ArrayList<Treasure> treasures){

        for (Treasure t : treasures) {
            this.currentPlayer.discardVisibleTreasure(t);
            this.dealer.giveTreasureBack(t);
        }
    }

    public void discardHiddenTreasures(ArrayList<Treasure> treasures){

        for (Treasure t : treasures) {
          this.currentPlayer.discardHiddenTreasure(t);
          this.dealer.giveTreasureBack(t);
        }
    }

   public void makeTreasuresVisible(ArrayList<Treasure> treasures){
     currentPlayer.makeTreasureVisible(treasures);
   }

   public void initGame(ArrayList<String> names){

        this.initPlayers(names);
        dealer.initCards();
        this.nextTurn();
   }

   public Player getCurrentPlayer(){
         return currentPlayer;
   }

   public Monster getCurrentMonster(){
       return currentMonster;
   }

   public boolean nextTurn() {
         boolean stateOK = nextTurnisAllowed();

         if(stateOK){
            currentMonster = dealer.nextMonster();
            currentPlayer = nextPlayer();
            boolean dead = currentPlayer.isDead();

            if(dead){
              currentPlayer.initTreasures();
            }
         }else{
           currentMonster = dealer.nextMonster(); // Para que no se bloquee el juego con el mismo monstruo
         }


       return stateOK;
   }

   public boolean nextTurnisAllowed(){
       boolean sePuede = true;

       if(currentPlayer != null){
           sePuede = currentPlayer.validState();
       }
       return sePuede;
   }

   public boolean endOfGame(CombatResult result){
       return (result == CombatResult.WINGAME);
   }


}
