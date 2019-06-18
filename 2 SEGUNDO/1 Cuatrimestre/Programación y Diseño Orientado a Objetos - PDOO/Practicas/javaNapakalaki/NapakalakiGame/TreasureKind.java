
package NapakalakiGame;
import java.lang.*;

/**
 *
 * @author manjaro
 */

public enum TreasureKind {

    ARMOR, ONEHAND, BOTHHANDS, HELMET, SHOES;

    @Override
    public String toString(){
      String opcion ;
      switch (this) {


              case ARMOR :  opcion = "ARMOR";
                            break;
              case ONEHAND :  opcion = "ONEHAND";
                            break;
              case BOTHHANDS :  opcion = "BOTHHANDS";
                            break;
              case HELMET :  opcion = "HELMET";
                            break;
              case SHOES :  opcion = "SHOES";
                            break;
              default: opcion = "Invalid TreasureKind";
                       break;
      }
        return opcion;
    }
}
