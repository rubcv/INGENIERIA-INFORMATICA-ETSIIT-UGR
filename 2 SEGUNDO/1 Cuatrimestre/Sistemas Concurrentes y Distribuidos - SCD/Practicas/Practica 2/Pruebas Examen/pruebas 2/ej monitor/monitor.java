import java.lang.Thread; // PARA LOS THREADS
import java.lang.Runnable; // PARA RUNNABLE
import java.util.Random;
import monitor.*;
import java.util.ArrayList;

class Monitor extends AbstractMonitor{
  private int tipo1 = 0, tipo2 = 0;
  private Condition espera1 = makeCondition(), espera2 = makeCondition();

  public void acceso(int tipo){
    enter();
      System.out.println("Accediendo hebra de tipo: " + tipo);
      if(tipo == 1){
        if(tipo1 < 3){ // Solo 3 interacciones de hebra 1
          tipo1++;
          System.out.println("Es la " + tipo1 + " vez que accedo");
        }else{
          espera1.await();
        }
      }else if(tipo == 2){
        if(tipo2 < 2){ // Solo 2 interacciones de hebra 2
          tipo2++;
          System.out.println("Es la " + tipo2 + " vez que accedo");
        }else{
          espera2.await();
        }
      }
    leave();
  }


  public void fin_acceso(int tipo){
    enter();
      if(tipo == 1){
        if(!espera1.isEmpty()){ // Lo mismo que !espera1.isEmpty()
          espera1.signal();
          System.out.println("Hebra de tipo1 decremento");
          tipo1--; // Se decrementa, no se pone directamente a 0 porque son varias hebras las que trabajan
        }
      }else if(tipo == 2){
        if(!espera2.isEmpty()){
          espera2.signal();
          System.out.println("Hebra de tipo2 decremento");
          tipo2--;
        }
      }
    leave();
  }

}


class Hebra implements Runnable{ // La misma hebra va cambiando el tipo a la hora de acceder
  private int tipo;
  private Monitor recurso;
  Thread thr;

  public Hebra(Monitor recurso, int tipo){
    thr = new Thread(this);
    this.recurso = recurso;
    this.tipo = tipo;
  }

  public void run(){
    while(true){
      int random = (int) (Math.random() * 2.0) + 1; // Acceder aleatoriamente de tipo 1 o 2
      recurso.acceso(random);
      aux.dormir_max(2000);
      recurso.fin_acceso(random);
    }
  }
}

class main{
  public static void main(String[] args){
    // System.out.println("Clase monitor con hebras, 3 de tipo1 y 2 de tipo2 (max)");

    Monitor recurso = new Monitor();
    ArrayList<Hebra> hebras = new ArrayList<Hebra>();
    int numHebra = 2;

    for(int i = 1; i <= numHebra; i++){
      hebras.add(new Hebra(recurso, i));
    }

    for(int i = 0; i < hebras.size(); i++){
      hebras.get(i).thr.start();
    }

    try{
      for(int i = 0; i < hebras.size(); i++){
        hebras.get(i).thr.join();
      }
    }catch(Exception ex){}

  }
}
