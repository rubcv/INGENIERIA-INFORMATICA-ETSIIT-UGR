import java.lang.Thread; // PARA LOS THREADS
import java.lang.Runnable; // PARA RUNNABLE
import monitor.*;

// ---------------------------------------------------------------------------------------
// --------------------------------------- BARBERIA ---------------------------------------
// ---------------------------------------------------------------------------------------

class Barberia extends AbstractMonitor{
      private Condition finDelCorte = makeCondition(); // Termina con un cliente y puede llamar a otro
      private Condition sillaOcupada = makeCondition(); // Silla ocupada o libre
      private Condition barberoDisponible = makeCondition(); // Barbero despierto o dormido
      private int vecesPeladas = 0; // Cada 3 veces el barbero echa a los clientes
      private final int AFORO = 2; // Capacidad de la sala de espera (2 < 3 clientes)
      private int contador = 0; // Contar los clientes que van a la sal de espera
// ---------------------------------------------------------------------------------------
  public void cortarPelo(){
    enter();
      if(!barberoDisponible.isEmpty()){ // barbero.isEmpty() <- Nadie ha hecho un await de esa conicion
        System.out.println("BARBERO: Me acaban de avisar");
        barberoDisponible.signal(); // Si no esta ocupado, lo aviso
      }else{
        System.out.println("BARBERO: Terminando de pelar");
        finDelCorte.await(); // Si esta ocupado, lo espero
      }
      System.out.println("BARBERO: Se ocupa la silla");
      sillaOcupada.await(); // En cualquier caso, se ocupa la silla
      vecesPeladas++;
      if(vecesPeladas == 3){
        System.out.println("BARBERO: Estoy harto de pelar a esta panda de melenudos piojosos");
        vecesPeladas = 0;
      }
    leave();
  }
// ---------------------------------------------------------------------------------------

  public void siguienteCliente(){
    enter();
        if(!finDelCorte.isEmpty()){ // Si esta ocupado, va a la sala de espera
          System.out.println("CLIENTE: Va a la sala de espera");
          contador++;
          if(contador == AFORO){
            System.out.println("CLIENTE: Sala de espera llena, me voy a la calle");
          }
          finDelCorte.signal();
        }else{
          System.out.println("CLIENTE: Ocupa al barbero");
          vecesPeladas = 0;
          contador = 0;
          barberoDisponible.await(); // Sino, ocupa al barbero
        }
    leave();
  }
// ---------------------------------------------------------------------------------------

  public void finCliente(){
    enter();
      System.out.println("BARBERO: Acaba con el cliente");
        sillaOcupada.signal();
    leave();
  }
// ---------------------------------------------------------------------------------------

}

// ---------------------------------------------------------------------------------------
// --------------------------------------- BARBERO ---------------------------------------
// ---------------------------------------------------------------------------------------

class Barbero implements Runnable{
  public Thread thr;
  Barberia barberia;

// ---------------------------------------------------------------------------------------
  public Barbero(Barberia barberia){
    thr = new Thread(this);
    this.barberia = barberia;
  }


// ---------------------------------------------------------------------------------------
  public void run(){
    while(true){
      barberia.siguienteCliente();
      aux.dormir_max(2000); // El barbero esta cortando el pelo
      barberia.finCliente();
    }
  }
}

// ---------------------------------------------------------------------------------------
// --------------------------------------- CLIENTE ---------------------------------------
// ---------------------------------------------------------------------------------------

class Cliente implements Runnable{
    public Thread thr;
    Barberia barberia;
// ---------------------------------------------------------------------------------------
    public Cliente(Barberia barberia){
      thr = new Thread(this);
      this.barberia = barberia;
    }
// ---------------------------------------------------------------------------------------

    public void run(){
      while(true){
        barberia.cortarPelo(); //el cliente espera (si procede) y se corta el pelo
        aux.dormir_max(2000); // el cliente esta fuera de la barberia un tiempo
      }
    }
}

// ---------------------------------------------------------------------------------------
// --------------------------------------- MAIN  -----------------------------------------
// ---------------------------------------------------------------------------------------

class MainBarbero{
  public static void main(String args[]){

  int numClientes = 3; // Numero de clientes
  int numBarberos = 1; // Numero de barberos
  Barberia barberia = new Barberia();

  Barbero[] barberos = new Barbero[numBarberos];
  Cliente[] clientes = new Cliente[numClientes];

  for(int i = 0; i < numBarberos; i++){
    barberos[i] = new Barbero(barberia);
  }

  for(int i = 0; i < numClientes; i++){
    clientes[i] = new Cliente(barberia);
  }



  // Lanzamiento de las hebras
  for(int i = 0; i < numBarberos; i++){
    barberos[i].thr.start();
  }
  for(int i = 0; i < numClientes; i++){
    clientes[i].thr.start();
  }


  // Terminar las hebras
  try{
    for(int i = 0; i < numBarberos; i++){
      barberos[i].thr.join();
    }

    for(int i = 0; i < numClientes; i++){
      clientes[i].thr.join();
    }
  }catch(Exception ex){}



  }
}
