package NapakalakiGame;

/**
 *
 * @author manjaro
 */
public class Dice {

    private static  Dice instance;


    private Dice(){

    }
    
    public static Dice getInstance(){
      if(instance == null){
        instance = new Dice();
      }
        return instance;
    }
    public int nextNumber(){

        return (int) (Math.random() * 5 + 1);
    }
}
