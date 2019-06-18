package NapakalakiGame;

/**
 *
 * @author manjaro
 */
 
public class Cultist {

    private String name;
    private int gainedLevels;

    public Cultist(String name , int gainedLevels) {
        this.name = name;
        this.gainedLevels = gainedLevels;

    }

    public int getGainedLevels(){
        return this.gainedLevels;
    }


}
