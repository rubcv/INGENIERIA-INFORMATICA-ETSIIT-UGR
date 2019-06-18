package NapakalakiGame;

/**
 *
 * @author manjaro
 */
 
public enum CombatResult {

    WINGAME, WIN, LOSE,LOSEANDCONVERT;


    @Override
    public String toString(){
    String opcion;
    switch (this) {


            case WINGAME :  opcion = "WINGAME";
                          break;
            case WIN :  opcion = "WIN";
                          break;
            case LOSE:  opcion = "LOSE";
                          break;
            case LOSEANDCONVERT: opcion = "LOSEANDCONVERT";
                          break;
           default: opcion = "Invalid CombatResult";
                     break;
    }
    return opcion;
}

}
