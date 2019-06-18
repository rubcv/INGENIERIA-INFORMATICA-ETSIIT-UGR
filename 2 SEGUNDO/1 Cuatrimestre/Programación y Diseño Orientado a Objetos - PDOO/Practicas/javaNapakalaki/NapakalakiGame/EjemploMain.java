package NapakalakiGame;

import Test.GameTester;

public class EjemploMain {

    public static void main(String[] args) {
      Napakalaki game = Napakalaki.getInstance();
      GameTester test = GameTester.getInstance();

      test.play(game, 2);

    }
}
