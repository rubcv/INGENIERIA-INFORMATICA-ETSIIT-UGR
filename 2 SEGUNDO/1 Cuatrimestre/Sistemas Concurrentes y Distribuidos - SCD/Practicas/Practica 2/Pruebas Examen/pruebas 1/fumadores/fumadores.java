/* - 6 fum + 2 estanq
   - ing especial
*/

import java.lang.Thread; // PARA LOS THREADS
import java.lang.Runnable; // PARA RUNNABLE
import java.util.Random;
import monitor.*;



// ---------------------------------------------------------------------------------------
// --------------------------------------- ESTANCO ---------------------------------------
// ---------------------------------------------------------------------------------------

class Estanco extends AbstractMonitor{
  private final int FUM = 3; // Numero de fumadores + ingrediente especial
  private Condition mesaOcupada = makeCondition(); // Cuatro condiciones, mesa ocupada y uno por cada ingrediente -> fumador
  private Condition[] ingredientes = new Condition[FUM]; // Array de ingredientes
  private int ingredienteDepositado; // Ingrediente que se produce
  private final int SIN_INGREDIENTE = -1; // No hay ingrediente en la mesa
  private final int ING_ESPECIAL = 3; // Ingrediente especial


// ---------------------------------------------------------------------------------------

  public Estanco(){
    /* ingredientes[i] ->  0: papel y cerillas, 1 papel y tabaco, 2:  tabaco y cerillas */
    for(int i = 0; i < FUM; i++){
      ingredientes[i] = makeCondition(); // Array de ingredientes para los fumadores
    }
    ingredienteDepositado = SIN_INGREDIENTE; // Al principio no hay ingrediente
  }

// ---------------------------------------------------------------------------------------

  public boolean obtenerIngrediente(int miIngrediente){
    enter();
      boolean abierto = true;
      if(ingredienteDepositado == ING_ESPECIAL){
        abierto = false;
      }
      if(abierto){
        if(ingredienteDepositado != miIngrediente){ // Si ingrediente distinto del que quieres, esperas
          System.out.println("FUMADOR " + miIngrediente + ": No esta mi ingrediente (hay " + ingredienteDepositado + "), espero");
          ingredientes[miIngrediente].await();
        }
        if(ingredienteDepositado != ING_ESPECIAL){
          System.out.println("FUMADOR " + miIngrediente + ": Cojo el ingrediente");
          ingredienteDepositado = SIN_INGREDIENTE;
          if(!mesaOcupada.isEmpty()){ // Si la mesa tiene ingrediente, mandas aviso
            System.out.println("FUMADOR " + miIngrediente + ": Aviso al estanquero");
            mesaOcupada.signal();
          }
        }else{
          abierto = false;
        }
      }
    leave();
   return abierto;
  }

// ---------------------------------------------------------------------------------------

  public boolean ponerIngrediente(int ingrediente){
    enter();
      boolean abierto = true;
        if(ingrediente == ING_ESPECIAL){
          abierto = false;
          ingredienteDepositado = ingrediente;
          System.out.println("ESTANQUERO: Voy a cerrar el estanco, aviso a los fumadores");

          for(Condition condicion : ingredientes){ // Despertar a los que esten dormidos para avisarlos a todos
            while(!condicion.isEmpty()){
              condicion.signal();
            }
          }
          if(!mesaOcupada.isEmpty()){
            mesaOcupada.signal();
          }
        }
        if(abierto){
          if(ingredienteDepositado != SIN_INGREDIENTE){ // Si ya ha puesto el otro estanquero, esperas a que lo quiten
            mesaOcupada.await();
          }

          ingredienteDepositado = ingrediente; // Pones el ingrediente
          System.out.println("ESTANQUERO: Puesto el ingrediente " + ingredienteDepositado);

          if(ingredientes[ingrediente].count() > 0){ // PONER EN ESE ORDEN: Para segun como lleguen las hebras
            System.out.println("ESTANQUERO: Avisando al fumador " + ingrediente);
            ingredientes[ingrediente].signal();
          }
        }
      leave();
    return abierto;
  }

// ---------------------------------------------------------------------------------------

  public boolean esperarRecogidaIngrediente(int ingrediente){
      enter();
        boolean abierto = true;
        if(ingrediente == ING_ESPECIAL){
          System.out.println("ESTANQUERO: Estanco cerrado");
          abierto = false;
        }
        if(abierto){
          if(ingredienteDepositado != SIN_INGREDIENTE){ // Si hay ingrediente, se espera
            System.out.println("ESTANQUERO: Esperando recogida");
            mesaOcupada.await();
          }
          else {
            System.out.println("ESTANQUERO: No hay elemento, no espero");
          }
        }
      leave();
      return abierto;
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
          while(estanco.obtenerIngrediente(miIngrediente)){
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
    private boolean abierto = true;
// ---------------------------------------------------------------------------------------

    public Estanquero(Estanco estanco){
      thr = new Thread(this);
      this.estanco = estanco;
    }


// ---------------------------------------------------------------------------------------

    public void run(){
      try{
        int ingrediente;
        boolean abierto = true;
        while(abierto){
          ingrediente = (int) (Math.random() * 4.0); // Se modifica para poner un ingrediente especial
          abierto = estanco.ponerIngrediente(ingrediente);

          if(abierto)
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
    int numFumadores = 6; // 6 Fumadores
    int numEstanqueros = 2; // 2 Estanqueros

    Estanco estanco = new Estanco();
    Fumador[] fumadores = new Fumador[numFumadores];
    Estanquero[] estanqueros = new Estanquero[numEstanqueros];

    // Objetos
    int mitad = numFumadores/2;
     for(int i = 0; i < mitad; i++){
       miIngrediente = i; // Un ingrediente a cada uno
       fumadores[i] = new Fumador(miIngrediente, estanco); // Todos los fumadores comparten el mismo estanco

       fumadores[mitad + i] = new Fumador(miIngrediente, estanco); // Todos los fumadores comparten el mismo estanco
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
            System.out.println("Fumador " + i + " a casa");
            fumadores[i].thr.join();
          }
          System.out.println("Los fumadores se han ido");
          for(int i = 0; i < numEstanqueros; i++){
            System.out.println("Estanquero " + i + " cierra el estanco");
            estanqueros[i].thr.join();
          }
          System.out.println("Los estanqueros han cerrado");
      }catch(Exception ex){}


  }
}
