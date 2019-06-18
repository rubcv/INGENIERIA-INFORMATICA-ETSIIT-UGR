
package napakalaki;

import test.*;

public class MainNapakalaki{

    public static void main(String[] args) {

      PruebaNapakalaki metodos = new PruebaNapakalaki(); // Para probar los metodos
      Napakalaki game = Napakalaki.getInstance();
      GameTester prueba = GameTester.getInstance();

      // // Poner el numero de jugadores con el que se quiera probar
      prueba.play(game, 2);
      // metodos.pruebaMetodos();

    }
}
