package napakalaki;


import java.util.ArrayList;
import java.util.Random;

public class CultistPlayer extends Player{

  private Cultist myCultistCard;

  
    // Contador de jugadores cultist
    private static int totalCultistPlayer = 0;

    static int getTotalCultistPlayer() {
        return totalCultistPlayer;
    }
