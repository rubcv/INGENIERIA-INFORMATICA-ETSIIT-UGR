import java.lang.Thread; // PARA LOS THREADS
import java.lang.Runnable; // PARA RUNNABLE
import java.util.Random;
import monitor.*;


class Peaje extends AbstractMonitor{
  private int cabina1 = 1, cabina2 = 2;
  private int cabina1Cont = 0, cabina2Cont = 0;
  private Condition colaEspera1 = makeCondition();
  private Condition colaEspera2 = makeCondition();

  private int menor(int a, int b){
    return (a < b)? a : b;
  }

  public int llegada_peaje(){
    enter();
      System.out.println("CABINA: Llega un coche");
      int cabina;
      int menosCoches = menor(cabina1Cont, cabina2Cont);
      if(menosCoches == cabina1Cont){
        cabina = 1;
        System.out.println("CABINA " + cabina + ": viene aqui");
        cabina1Cont++;
      }else{
        cabina = 2;
        System.out.println("CABINA " + cabina + ": viene aqui");
        cabina2Cont++;
      }
      if(!colaEspera1.isEmpty()){
        colaEspera1.await();
      }
      if(!colaEspera2.isEmpty()){
        colaEspera2.await();
      }
    leave();
    return cabina;
  }

  public void pagado(int cabina){
    enter();
      if(cabina == 1){
        System.out.println("CABINA " + cabina + ": el coche se marcha");
        cabina1Cont--;
        colaEspera1.signal();

      }else{
        System.out.println("CABINA " + cabina + ": el coche se marcha");
        cabina2Cont--;
        colaEspera2.signal();
      }
    leave();
  }
}

class Coche implements Runnable{
  public Thread thr;
  Peaje peaje;

  public Coche(Peaje peaje){
    thr = new Thread(this);
    this.peaje = peaje;
  }

  public void run(){
    while(true){
      int cabina = peaje.llegada_peaje();
      aux.dormir_max(2000); // Simulacion del pago
      peaje.pagado(cabina);
      aux.dormir_max(2000); // El coche se marcha
    }
  }
}

class main{
  public static void main(String[] args){

    // Creacion de los objetos
    int numCoches = Integer.parseInt(args[0]);
    Peaje peaje = new Peaje();
    Coche[] coches = new Coche[numCoches];

    for(int i = 0; i < numCoches; i++){
      coches[i] = new Coche(peaje);
    }

    // Lanzamiento de las hebras
    for(int i = 0; i < numCoches; i++){
      coches[i].thr.start();
    }

    try{
      //Fin de las hebras
      for(int i = 0; i < numCoches; i++){
        coches[i].thr.join();
      }
    }catch(Exception ex){}

  }
}
