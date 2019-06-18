package NapakalakiGame;


public class CultistPlayer extends Player{
    private static int totalCultistPlayers = 0;
    private Cultist myCultistCard ;

    public CultistPlayer(Player p ,Cultist c){
        super(p);
        this.myCultistCard = c;
    }

    @Override
    protected int getCombatLevel(){
        double val ;

        val = super.getCombatLevel() ;
        val= val * 1.20;
        val = val + (myCultistCard.getGainedLevels() * totalCultistPlayers);
        return (int)val;

    }

    @Override
    protected int getOponentLevel(Monster m){
        int res;
        res = m.getCombatLevelAgainstCultistPlayer();
        return res;
    }

    @Override
    protected boolean shouldConvert(){
      Dice dice = Dice.getInstance();
      boolean res = false;
      int number = dice.nextNumber();

      if (number == 1){
          res =true;
      }
      return res;
    }


    private Treasure giveMeATreasure(){
       Treasure res;
       int posAleatorio;
       posAleatorio = (int) (Math.random() * super.getVisibleTreasures().size());
       res = super.getVisibleTreasures().get(posAleatorio);

       return res;
    }

    private boolean canYouGiveMeATreasure(){
      boolean res = false;

      if(super.getVisibleTreasures().size()> 0){
          res = true;
      }
      return res;
    }

    public int getTotalCultistPlayers(){
        return totalCultistPlayers;
    }

    @Override
    public boolean isCultist(){
        return true;
    }
}
