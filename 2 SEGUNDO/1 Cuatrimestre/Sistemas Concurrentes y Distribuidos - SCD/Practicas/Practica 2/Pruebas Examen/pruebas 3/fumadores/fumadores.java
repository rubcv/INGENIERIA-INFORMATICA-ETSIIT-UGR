import java.lang.Thread; // PARA LOS THREADS
import java.lang.Runnable; // PARA RUNNABLE
import java.util.Random;
import monitor.*;



// ---------------------------------------------------------------------------------------
// --------------------------------------- ESTANCO ---------------------------------------
// ---------------------------------------------------------------------------------------

class Estanco extends AbstractMonitor{
  private final int FUM = 3; // Numero de fumadores
  private Condition mesaOcupada = makeCondition(); // Cuatro condiciones, mesa ocupada y uno por cada ingrediente -> fumador
  private Condition[] ingredientes = new Condition[FUM]; // Array de ingredientes
  private int ingredienteDepositado; // Ingrediente que se produce
  private final int SIN_INGREDIENTE = -1; // No hay ingrediente en la mesa

// ---------------------------------------------------------------------------------------

  public Estanco(){
    /* ingredientes[i] ->  0: papel y cerillas, 1 papel y tabaco, 2:  tabaco y cerillas */
    for(int i = 0; i < FUM; i++){
      ingredientes[i] = makeCondition(); // Array de ingredientes para los fumadores
    }
    ingredienteDepositado = SIN_INGREDIENTE; // Al principio no hay ingrediente
  }

// ---------------------------------------------------------------------------------------

  public void obtenerIngrediente(int miIngrediente){
    enter();
      System.out.println("FUMADOR " + miIngrediente + ": Cogiendo ingrediente");
      if(ingredienteDepositado != miIngrediente){ // Si ingrediente distinto del que quieres, esperas
        System.out.println("FUMADOR " + miIngrediente + ": No esta mi ingrediente (hay " + ingredienteDepositado + "), espero");
        ingredientes[miIngrediente].await();
      }
      System.out.println("FUMADOR " + miIngrediente + ": Cojo el ingrediente");
      ingredienteDepositado = SIN_INGREDIENTE;
      if(!mesaOcupada.isEmpty()){ // Si la mesa tiene ingrediente, mandas aviso
        System.out.println("FUMADOR " + miIngrediente + ": Aviso al estanquero");
        mesaOcupada.signal();
      }
    leave();
  }

// ---------------------------------------------------------------------------------------

  public void ponerIngrediente(int ingrediente){
    enter();
      ingredienteDepositado = ingrediente; // Pones el ingrediente
      System.out.println("ESTANQUERO: Puesto el ingrediente " + ingredienteDepositado);
      if(ingredientes[ingrediente].count() > 0){ // PONER EN ESE ORDEN: Para segun como lleguen las hebras
        System.out.println("ESTANQUERO: Avisando al fumador " + ingrediente);
        ingredientes[ingrediente].signal();
      }
    leave();
  }

// ---------------------------------------------------------------------------------------

  public void esperarRecogidaIngrediente(int ingrediente){
      enter();
        if(ingredienteDepositado != SIN_INGREDIENTE){ // Si hay ingrediente, se espera
          System.out.println("ESTANQUERO: Esperando recogida");
          mesaOcupada.await();
        }
        else {
          System.out.println("ESTANQUERO: No hay elemento, no espero");
        }
      leave();
  }

}



// ---------------------------------------------------------------------------------------
// --------------------------------------- FUMADOR ---------------------------------------
// ---------------------------------------------------------------------------------------

class Fumador implements Runnable{
  int miIngrediente;
  public Thread thr;
  Estanco estanco;


  public Fumador(int p_miIngrediente, Estanco estanco){
      thr = new Thread(this);
      miIngrediente = p_miIngrediente;
      this.estanco = estanco;
  }

// ---------------------------------------------------------------------------------------

  public void run(){
      try{
          while(true){
            estanco.obtenerIngrediente(miIngrediente);
            aux.dormir_max(2000);
          }
      }catch(Exception ex){
        System.out.print("\nExcepcion en run de fumador: " + ex + "\n");
      }
    }
}



// ---------------------------------------------------------------------------------------
// --------------------------------------- ESTANQUERO ---------------------------------------
// ---------------------------------------------------------------------------------------

class Estanquero implements Runnable{
    public Thread thr;
    Estanco estanco;

// ---------------------------------------------------------------------------------------

    public Estanquero(Estanco estanco){
      thr = new Thread(this);
      this.estanco = estanco;
    }

// ---------------------------------------------------------------------------------------

    public void run(){
      try{
        int ingrediente;

        while(true){
          ingrediente = (int) (Math.random() * 3.0); // 0, 1,  2 //  0: papel y cerillas, 1 papel y tabaco, 2:  tabaco y cerillas

          estanco.ponerIngrediente(ingrediente);
          estanco.esperarRecogidaIngrediente(ingrediente);
        }
      }catch(Exception ex){
        System.out.print("\nExcepcion en run de estanquero: " + ex + "\n");
      }
    }
}

// ---------------------------------------------------------------------------------------
// --------------------------------------- MAIN  -----------------------------------------
// ---------------------------------------------------------------------------------------

class MainFumadores{

  public static void main(String[] args){

    int miIngrediente;
    int numFumadores = 3; // 3 Fumadores
    int numEstanqueros = 1; // 1 Estanquero

    Estanco estanco = new Estanco();
    Fumador[] fumadores = new Fumador[numFumadores];
    Estanquero[] estanqueros = new Estanquero[numEstanqueros];

    // Objetos
     for(int i = 0; i < numFumadores; i++){
       miIngrediente = i; // Un ingrediente a cada uno
       fumadores[i] = new Fumador(miIngrediente, estanco); // Todos los fumadores comparten el mismo estanco
     }

     for(int i = 0; i < numEstanqueros; i++){
       estanqueros[i] = new Estanquero(estanco); // Comparte el mismo estanco
     }


      // Lanzamiento de las hebras

     for(int i = 0; i < numFumadores; i++){
       fumadores[i].thr.start();
     }
     for(int i = 0; i < numEstanqueros; i++){
       estanqueros[i].thr.start();
     }

    // Terminar las hebras
      try{
        for(int i = 0; i < numFumadores; i++){
          fumadores[i].thr.join();
        }
        for(int i = 0; i < numEstanqueros; i++){
          estanqueros[i].thr.join();
        }
      }catch(Exception ex){}


  }
}
