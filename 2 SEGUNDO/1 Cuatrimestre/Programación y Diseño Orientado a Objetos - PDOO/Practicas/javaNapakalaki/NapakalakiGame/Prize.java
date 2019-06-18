package NapakalakiGame;
import java.lang.*;

/**
 *
 * @author manjaro
 */

public class Prize {

      private int treasures;
      private int level;

      public Prize(int treasure, int level){

          this.treasures = treasure;
          this.level = level;
      }

      public int getTreasures(){
          return treasures;
      }

      public int getLevel(){
          return level;
      }

      @Override
      public String toString(){
        String res = "Treasures " + Integer.toString(treasures) + " levels " + Integer.toString(level);
        return res ;
      }
}
